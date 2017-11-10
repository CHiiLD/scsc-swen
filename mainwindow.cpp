#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QMessageBox>
#include <QFileDialog>
#include "randnumgen.h"

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
    connect(ui->pushButton_randGenInit, SIGNAL(clicked(bool)), this, SLOT(clearRandNumberOutputBox(bool)));
    connect(ui->pushButton_randGenSave, SIGNAL(clicked(bool)), this, SLOT(saveRandNumberOutput(bool)));

    // 일변량 데이터 입력 테이블뷰 설정
    QStandardItemModel *model = new QStandardItemModel(50000,1,this);
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("X")));
    ui->tableView_univariateInput->setModel(model);

    // 일변량 출력 테이블뷰 설정
    model = new QStandardItemModel(1,5,this);
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("평균")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("분산")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("중앙값")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QString("표준편차")));
    model->setHorizontalHeaderItem(4, new QStandardItem(QString("사분위수")));
    ui->tableView_univariateOutput->setModel(model);

    // 이변량 데이터 입력 테이블 뷰 설정
    model = new QStandardItemModel(50000,2,this);
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("X")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Y")));
    ui->tableView_bivariateInput->setModel(model);

    // 변량 출력 테이블뷰 설정
    model = new QStandardItemModel(2,5,this);
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("평균")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("분산")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("중앙값")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QString("표준편차")));
    model->setHorizontalHeaderItem(4, new QStandardItem(QString("사분위수")));
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
    QMessageBox::about(this, "알림", "잘못된 입력입니다!");
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

void MainWindow::clearRandNumberOutputBox(bool checked)
{
    ui->textEdit_randGenOutput->clear();
    ui->lineEdit_randGenMinValue->clear();
    ui->lineEdit_randGenMaxValue->clear();
    ui->lineEdit_randGenOutputSize->clear();
}

void MainWindow::saveRandNumberOutput(bool checked)
{
    QString text = ui->textEdit_randGenOutput->toPlainText();
    QString fileName = QFileDialog::getSaveFileName(this, tr("데이터를 저장합니다"));

    if (fileName.isEmpty())
        return;
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        return;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_9);
    out << text;
}
