#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "randnumgen.h"
#include "basicstat.h"
#include "nullhypothesis.h"
#include "save.h"
#include "statchart.h"

#include <math.h>

#include <QStandardItemModel>
#include <QMessageBox>

#define TABLEVIEW_ROW_MAX_SIZE 50000
#define TERM_MEAN "평균"
#define TERM_VARIANCE "분산"
#define TERM_STD_DEVIATION "표준편차"
#define TERM_25TH_PERCENTILE "제1분위수"
#define TERM_50TH_PERCENTILE "제2사분위수(중앙값)"
#define TERM_75TH_PERCENTILE "제3사분위수"
#define TERM_CORRELATIONCOEFFICIENT "상관계수"
#define TERM_X "X"
#define TERM_Y "Y"
#define TERM_FOUNDATION_STAT "기초통계량"
#define TERM_DATASET "데이터 셋"

using namespace QtCharts;

bool writeUnivariateStatOutput(dataset data, QAbstractItemModel* model, int row);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    // 메뉴 아이템들의 클릭 이벤트를 연결합니다.
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(showAbout()));
    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(quit()));

    // 난수생성 컴포넌트들의 이벤트를 연결합니다.
    connect(ui->pushButton_randGenExecute, SIGNAL(clicked(bool)), this, SLOT(genelateRandomNumber(bool)));
    connect(ui->pushButton_randGenInit, SIGNAL(clicked(bool)), this, SLOT(clearRandNumberData(bool)));
    connect(ui->pushButton_randGenSave, SIGNAL(clicked(bool)), this, SLOT(saveRandNumberData(bool)));

    // 기초통계량 - 일변량 컴포넌트 이벤트를 연결합니다.
    connect(ui->pushButton_univariateHistogram, SIGNAL(clicked(bool)), this, SLOT(showHistogram(bool)));
    connect(ui->pushButton_univariateExecute, SIGNAL(clicked(bool)), this, SLOT(calcUnivariateData(bool)));
    connect(ui->pushButton_univariateInit, SIGNAL(clicked(bool)), this, SLOT(clearUnivariateData(bool)));
    connect(ui->pushButton_univariateSave, SIGNAL(clicked(bool)), this, SLOT(saveUnivariateData(bool)));

    // 기초통계량 - 이변량 컴포넌트 이벤트를 연결합니다.
    connect(ui->pushButton_bivarivateScatterPlot, SIGNAL(clicked(bool)), this, SLOT(showScatterPlot(bool)));
    connect(ui->pushButton_bivarivateExecute, SIGNAL(clicked(bool)), this, SLOT(calcBivariateData(bool)));
    connect(ui->pushButton_bivariateInit, SIGNAL(clicked(bool)), this, SLOT(clearBivariateData(bool)));
    connect(ui->pushButton_bivariateSave, SIGNAL(clicked(bool)), this, SLOT(saveBivariateData(bool)));

    connect(ui->pushButton_nullhypothesisExecute, SIGNAL(clicked(bool)), this, SLOT(judgeNullHypothesis(bool)));
    connect(ui->pushButton_nullHypothesisInit, SIGNAL(clicked(bool)), this, SLOT(claerNullHypothesisData(bool)));

    // 일변량 데이터 입력 테이블뷰 설정
    QStandardItemModel *model = new QStandardItemModel(TABLEVIEW_ROW_MAX_SIZE,1,this);
    model->setHorizontalHeaderItem(0, new QStandardItem(QString(TERM_X)));
    ui->tableView_univariateInput->setModel(model);

    // 일변량 출력 테이블뷰 설정
    model = new QStandardItemModel(1,6,this);
    model->setHorizontalHeaderItem(0, new QStandardItem(TERM_MEAN));
    model->setHorizontalHeaderItem(1, new QStandardItem(TERM_VARIANCE));
    model->setHorizontalHeaderItem(2, new QStandardItem(TERM_STD_DEVIATION));
    model->setHorizontalHeaderItem(3, new QStandardItem(TERM_25TH_PERCENTILE));
    model->setHorizontalHeaderItem(4, new QStandardItem(TERM_50TH_PERCENTILE));
    model->setHorizontalHeaderItem(5, new QStandardItem(TERM_75TH_PERCENTILE));
    ui->tableView_univariateOutput->setModel(model);

    // 이변량 데이터 입력 테이블 뷰 설정
    model = new QStandardItemModel(TABLEVIEW_ROW_MAX_SIZE,2,this);
    model->setHorizontalHeaderItem(0, new QStandardItem(QString(TERM_X)));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString(TERM_Y)));
    ui->tableView_bivariateInput->setModel(model);

    // 이변량 출력 테이블뷰 설정
    model = new QStandardItemModel(2,7,this);
    model->setHorizontalHeaderItem(0, new QStandardItem(TERM_MEAN));
    model->setHorizontalHeaderItem(1, new QStandardItem(TERM_VARIANCE));
    model->setHorizontalHeaderItem(2, new QStandardItem(TERM_STD_DEVIATION));
    model->setHorizontalHeaderItem(3, new QStandardItem(TERM_25TH_PERCENTILE));
    model->setHorizontalHeaderItem(4, new QStandardItem(TERM_50TH_PERCENTILE));
    model->setHorizontalHeaderItem(5, new QStandardItem(TERM_75TH_PERCENTILE));
    model->setHorizontalHeaderItem(6, new QStandardItem(TERM_CORRELATIONCOEFFICIENT));
    ui->tableView_bivariateOutput->setModel(model);
}

void MainWindow::showAbout()
{
    QMessageBox::about(this, "기초 통계 프로그램",
                       "버전: 1.0"
                       "\n"
                       "Based on Qt 5.9.1"
                       "\n"
                       "\n"
                       "Copyright 2017 김아동 박세희 이수민"
                       "\n"
                       "\n"
                       "Permission is hereby granted, free of charge, to any person "
                       "obtaining a copy of this software and associated documentation "
                       "files (the \"Software\"), to deal in the Software without "
                       "restriction, including without limitation the rights to use, "
                       "copy, modify, merge, publish, distribute, sublicense, and/or sell "
                       "copies of the Software, and to permit persons to whom the "
                       "Software is furnished to do so, subject to the following"
                       "\n"
                       "\n"
                       "conditions:"
                       "\n"
                       "The above copyright notice and this permission notice shall be "
                       "included in all copies or substantial portions of the Software."
                       "\n"
                       "\n"
                       "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, "
                       "EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES "
                       "OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND "
                       "NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT "
                       "HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, "
                       "WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING "
                       "FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR "
                       "OTHER DEALINGS IN THE SOFTWARE.");
}

void MainWindow::quit()
{
    close();
}

void MainWindow::showWrongInputMessageBox()
{
    QMessageBox::information(this, "알림", "잘못된 입력입니다!");
}

void MainWindow::genelateRandomNumber(bool checked)
{
    bool ok;
    std::list<int> list;
    QString min = ui->lineEdit_randGenMinValue->text();
    QString max = ui->lineEdit_randGenMaxValue->text();
    QString outputSize = ui->lineEdit_randGenOutputSize->text();

    do
    {
        int imin = min.toInt(&ok);
        if(!ok) break;
        int imax = max.toInt(&ok);
        if(!ok) break;
        int iOutputSize = outputSize.toInt(&ok);
        if(!ok) break;

        if(RandNumber::generate(imin, imax, iOutputSize, list) != OK)
            ok = false;
    } while(false);

    if(!ok)
    {
        showWrongInputMessageBox();
        return;
    }
    QString text;
    for(auto iter = list.begin(); iter != list.end(); ++iter)
    {
        text.append(QString::number(*iter));
        text.append(", ");
    }
    text.remove(text.length() - 2, 2);
    ui->textEdit_randGenOutput->setText(text);
}

void MainWindow::clearRandNumberData(bool checked)
{
    ui->textEdit_randGenOutput->clear();
    ui->lineEdit_randGenMinValue->clear();
    ui->lineEdit_randGenMaxValue->clear();
    ui->lineEdit_randGenOutputSize->clear();
}

void MainWindow::saveToFile(QString text)
{
    QString error;
    if(!Save::ToFile(this, text, error))
    {
        QMessageBox::information(this, "파일을 열 수 없습니다.", error);
    }
}

void MainWindow::saveRandNumberData(bool checked)
{
    QString text = ui->textEdit_randGenOutput->toPlainText();
    saveToFile(text);
}

bool extractDataset(QAbstractItemModel* model, int col, dataset& data)
{
    int row, rowCount = model->rowCount();
    bool ok = false;
    dataset list;
    // 공백을 만날 때까지 테이블뷰에서 데이터를 수집한다.
    for(row = 0; row < rowCount; ++row)
    {
        QModelIndex index = model->index(row, col);
        QVariant var = model->data(index);
        if(!var.isValid() || var.toString().length() == 0) // 공백을 만난 경우
            break;

        double value = var.toDouble(&ok);
        if(!ok) // 잘못된 데이터 입력을 감지
            break;

        list.push_back(value);
    }
    // 공백 이후에 데이터가 추가로 입력된 경우를 찾아서 잘못된 데이터 입력으로 처리
    for(++row; row < rowCount; ++row)
    {
        QModelIndex index = model->index(row, col);
        QVariant var = model->data(index);
        if(var.isValid() && var.toString().length() != 0)
        {
            ok = false;
            break;
        }
    }
    if(ok)
        data = list;
    return ok;
}

void MainWindow::showHistogram(bool checked)
{
    QAbstractItemModel* model = ui->tableView_univariateInput->model();
    dataset data;
    bool ok = extractDataset(model, 0, data);

    if(!ok)
    {
        showWrongInputMessageBox();
        return;
    }

    StatChart::histogram(data, "히스토그램", TERM_X)->show();
}

void MainWindow::calcUnivariateData(bool checked)
{
    QAbstractItemModel* model = ui->tableView_univariateInput->model();
    dataset data;
    bool ok = extractDataset(model, 0, data);

    if(!ok)
    {
        showWrongInputMessageBox();
        return;
    }

    model = ui->tableView_univariateOutput->model();
    if(!writeUnivariateStatOutput(data, model, 0))
    {
        showWrongInputMessageBox();
        return;
    }
}

void MainWindow::clearUnivariateData(bool checked)
{
    QStandardItemModel* model = (QStandardItemModel*) ui->tableView_univariateInput->model();
    model->setRowCount(0);
    model->setRowCount(TABLEVIEW_ROW_MAX_SIZE);
    model = (QStandardItemModel*) ui->tableView_univariateOutput->model();
    model->setRowCount(0);
    model->setRowCount(1);
}

void MainWindow::saveUnivariateData(bool checked)
{
    QString text;
    QAbstractItemModel* model = ui->tableView_univariateInput->model();
    dataset data;
    bool ok = extractDataset(model, 0, data);

    if(!ok)
    {
        showWrongInputMessageBox();
        return;
    }

    model = ui->tableView_univariateOutput->model();
    QString mean = model->data(model->index(0, 0)).toString();
    QString variance =model->data(model->index(0, 1)).toString();
    QString std =model->data(model->index(0, 2)).toString();
    QString q1 =model->data(model->index(0, 3)).toString();
    QString q2 =model->data(model->index(0, 4)).toString();
    QString q3 =model->data(model->index(0, 5)).toString();

    QString split = " : ";
    QString newline = "\n";
    // 기초통계량 정보
    text.append(TERM_FOUNDATION_STAT).append(newline);
    text.append(TERM_MEAN).append(split).append(mean).append(newline);
    text.append(TERM_VARIANCE).append(split).append(variance).append(newline);
    text.append(TERM_STD_DEVIATION).append(split).append(std).append(newline);
    text.append(TERM_25TH_PERCENTILE).append(split).append(q1).append(newline);
    text.append(TERM_50TH_PERCENTILE).append(split).append(q2).append(newline);
    text.append(TERM_75TH_PERCENTILE).append(split).append(q3).append(newline);

    text.append(newline);
    // X데이터 셋
    text.append(TERM_X).append(TERM_DATASET).append(newline);
    for(auto iter = data.begin(); iter != data.end(); ++iter)
        text.append(QString::number(*iter)).append(newline);
    text.remove(text.length() -1, 1); //마지막 개행문자 삭제
    saveToFile(text);
}

void MainWindow::showScatterPlot(bool checked)
{
    QAbstractItemModel* model = ui->tableView_bivariateInput->model();
    dataset dataX, dataY;
    double cc;
    bool ok = extractDataset(model, 0, dataX);
    ok &= extractDataset(model, 1, dataY);
    if(!ok || FoundationStat::correlationCoefficient(dataX, dataY, cc) != OK)
    {
        showWrongInputMessageBox();
        return;
    }

    StatChart::scatterPlot(dataX, dataY, "산점도", "데이터")->show();
}

bool writeUnivariateStatOutput(dataset data, QAbstractItemModel* model, int row)
{
    double mean, variance, std, q1, q2, q3;

    int ret = FoundationStat::mean(data, mean);
    ret |= FoundationStat::variance(data, variance);
    ret |= FoundationStat::standardDeviation(data, std);
    ret |= FoundationStat::pecentile(data, 0.25, q1);
    ret |= FoundationStat::pecentile(data, 0.5, q2);
    ret |= FoundationStat::pecentile(data, 0.75, q3);

    if(ret != OK)
        return false;

    model->setData(model->index(row, 0), QString::number(mean, 'f', 2));
    model->setData(model->index(row, 1), QString::number(variance, 'f',2));
    model->setData(model->index(row, 2), QString::number(std, 'f',2));
    model->setData(model->index(row, 3), QString::number(q1, 'f', 2));
    model->setData(model->index(row, 4), QString::number(q2, 'f', 2));
    model->setData(model->index(row, 5), QString::number(q3, 'f', 2));

    return true;
}

void MainWindow::calcBivariateData(bool checked)
{
    QAbstractItemModel* model = ui->tableView_bivariateInput->model();
    dataset dataX, dataY;
    double cc;
    bool ok = extractDataset(model, 0, dataX);
    ok &= extractDataset(model, 1, dataY);
    if(!ok || FoundationStat::correlationCoefficient(dataX, dataY, cc) != OK)
    {
        showWrongInputMessageBox();
        return;
    }

    model = ui->tableView_bivariateOutput->model();
    if(!writeUnivariateStatOutput(dataX, model, 0) || !writeUnivariateStatOutput(dataY, model, 1))
    {
        showWrongInputMessageBox();
        return;
    }
    //상관계수 입력
    model->setData(model->index(0, 6), QString::number(cc, 'f', 2));
    model->setData(model->index(1, 6), QString::number(cc, 'f', 2));
}

void MainWindow::clearBivariateData(bool checked)
{
    QStandardItemModel* model = (QStandardItemModel*) ui->tableView_bivariateInput->model();
    model->setRowCount(0);
    model->setRowCount(TABLEVIEW_ROW_MAX_SIZE);
    model = (QStandardItemModel*) ui->tableView_bivariateOutput->model();
    model->setRowCount(0);
    model->setRowCount(2);
}

void MainWindow::saveBivariateData(bool checked)
{
    QString text;
    QAbstractItemModel* model = ui->tableView_bivariateInput->model();
    dataset dataX, dataY;
    double cc;
    bool ok = extractDataset(model, 0, dataX);
    ok &= extractDataset(model, 1, dataY);
    if(!ok || FoundationStat::correlationCoefficient(dataX, dataY, cc) != OK)
    {
        showWrongInputMessageBox();
        return;
    }

    model = ui->tableView_bivariateOutput->model();
    QString dataName[] = {TERM_X, TERM_Y};
    QString split = " : ";
    QString newline = "\n";
    QString space = " ";
    for(int row = 0; row < 2; ++row)
    {
        QString mean = model->data(model->index(row, 0)).toString();
        QString variance =model->data(model->index(row, 1)).toString();
        QString std =model->data(model->index(row, 2)).toString();
        QString q1 =model->data(model->index(row, 3)).toString();
        QString q2 =model->data(model->index(row, 4)).toString();
        QString q3 =model->data(model->index(row, 5)).toString();

        text.append(dataName[row]).append(space).append(TERM_FOUNDATION_STAT).append(newline);
        text.append(TERM_MEAN).append(split).append(mean).append(newline);
        text.append(TERM_VARIANCE).append(split).append(variance).append(newline);
        text.append(TERM_STD_DEVIATION).append(split).append(std).append(newline);
        text.append(TERM_25TH_PERCENTILE).append(split).append(q1).append(newline);
        text.append(TERM_50TH_PERCENTILE).append(split).append(q2).append(newline);
        text.append(TERM_75TH_PERCENTILE).append(split).append(q3).append(newline);
        text.append(newline);
    }
    QString corr =model->data(model->index(0, 6)).toString(); //상관계수
    text.append(TERM_CORRELATIONCOEFFICIENT).append(split).append(corr).append(newline);
    text.append(newline);

    // X:Y데이터 셋
    text.append(TERM_X).append(split).append(TERM_Y).append(space).append(TERM_DATASET).append(newline);
    dataset::iterator iterX, iterY;
    for(int i = 0; i < dataX.size(); ++i)
    {
        iterX = dataX.begin();
        iterY = dataY.begin();
        std::advance(iterX, i);
        std::advance(iterY, i);
        text.append(QString::number(*iterX)).append(space).append(QString::number(*iterY)).append(newline);
    }

    text.remove(text.length() -1, 1); //마지막 개행문자 삭제
    saveToFile(text);
}

void MainWindow::judgeNullHypothesis(bool checked)
{
    QString sTestStatistic = ui->lineEdit_nullHypothesisTestStatistic->text();
    QString sStdDevation = ui->lineEdit_nullHypothesisStdDeviation->text();
    QString sSize = ui->lineEdit_nullHypothesisSize->text();
    QString sTestValue = ui->lineEdit_nullHypothesisTestValue->text();
    QString sAlpha = ui->lineEdit_nullHypothesisAlpha->text();
    QString sSign = ui->comboBox_sign->currentText();
    double testStatistic, stdDevation, testValue, alpha;
    int size;
    NullHypothesisSign sign = NullHypothesisSign::NONE;
    bool ok = false;
    do
    {
        testStatistic = sTestStatistic.toDouble(&ok);
        if(!ok) break;
        stdDevation = sStdDevation.toDouble(&ok);
        if(!ok) break;
        testValue = sTestValue.toDouble(&ok);
        if(!ok) break;
        alpha = sAlpha.toDouble(&ok);
        if(!ok) break;
        size = sSize.toInt(&ok);
        if(!ok) break;
    } while(false);

    if(sSign.compare(NULL_HYPOTHESIS_SIGN_NEIN) == 0)
        sign = NullHypothesisSign::NOT_EQUAL;
    else if (sSign.compare(NULL_HYPOTHESIS_SIGN_LESS_THEN))
        sign = NullHypothesisSign::LESS_THEN;
    else if (sSign.compare(NULL_HYPOTHESIS_SIGN_GREATER_THEN))
        sign = NullHypothesisSign::GREATER_THEN;

    if(!ok || sign == NullHypothesisSign::NONE)
    {
        showWrongInputMessageBox();
        return;
    }

    int ret = NullHypothesis::hyphothesis(testStatistic, stdDevation, size, testValue, alpha, sign);
    QString text;
    text.append("α=");
    text.append(QString::number(alpha));
    text.append("에서 귀무가설을 ");
    switch (ret)
    {
    case NULL_HYPOTHESIS_REJECT_SECCESS:
        text.append("기각한다.");
        break;
    case NULL_HYPOTHESIS_REJECT_FAIL:
        text.append("기각 할 수 없다.");
        break;
    default:
        showWrongInputMessageBox();
        return;
    }
    ui->textEdit_nullHypothesisOutput->setText(text);
}

void MainWindow::claerNullHypothesisData(bool checked)
{
    ui->lineEdit_nullHypothesisTestStatistic->clear();
    ui->lineEdit_nullHypothesisStdDeviation->clear();
    ui->lineEdit_nullHypothesisSize->clear();
    ui->lineEdit_nullHypothesisTestValue->clear();
    ui->lineEdit_nullHypothesisAlpha->clear();
    ui->textEdit_nullHypothesisOutput->clear();
}
