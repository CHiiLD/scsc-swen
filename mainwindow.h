#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractItemModel>

namespace Ui
{
class MainWindow;
}

/**
 * @brief 메인 윈도우 클래스
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    /**
     * @brief 사전에 ui컴포넌트의 이벤트와 기초통계량 테이블뷰를 설정합니다.
     */
    void init();

    /**
     * @brief 잘못된 입력에 대한 경고 메시지를 출력합니다.
     */
    void showWrongInputMessageBox();

    /**
     * @brief 파일 다이얼로그를 사용하여 텍스트를 파일로 저장합니다.
     * @param text 텍스트
     */
    void saveToFile(QString text);
private:
    Ui::MainWindow *ui;

private slots:
    /**
     * @brief 프로그램의 정보를 메시지박스로 출력합니다.
     */
    void showAbout();

    /**
     * @brief 프로그램을 종료합니다.
     */
    void quit();

    /**
     * @brief 난수를 생성하고 결과를 업데이트합니다.
     * @param checked
     */
    void genelateRandomNumber(bool checked);

    /**
     * @brief 난수생성 관련 edit컴포넌트를 초기화합니다.
     * @param checked
     */
    void clearRandNumberData(bool checked);

    /**
     * @brief 생성된 난수들을 파일로 저장합니다.
     * @param checked
     */
    void saveRandNumberData(bool checked);

    /**
     * @brief 기초통계량-일변량 데이터셋을 히스토그램으로 보여줍니다.
     * @param checked
     */
    void showHistogram(bool checked);

    /**
     * @brief 기초통계량-일변량을 계산하고 결과를 업데이트합니다.
     * @param checked
     */
    void calcUnivariateData(bool checked);

    /**
     * @brief 기초통계량-일변량 관련 edit컴포넌트를 초기화합니다.
     * @param checked
     */
    void clearUnivariateData(bool checked);

    /**
     * @brief 기초통계량-일변량 데이터와 계산 결과를 파일로 저장합니다.
     * @param checked
     */
    void saveUnivariateData(bool checked);

    /**
     * @brief 기초통계량-이변량 데이터셋을 산점도로 보여줍니다.
     * @param checked
     */
    void showScatterPlot(bool checked);

    /**
     * @brief 기초통계량-이변량을 계산하고 결과를 업데이트합니다.
     * @param checked
     */
    void calcBivariateData(bool checked);

    /**
     * @brief 기초통계량-이변량 관련 edit컴포넌트를 초기화합니다.
     * @param checked
     */
    void clearBivariateData(bool checked);

    /**
     * @brief 기초통계량-이변량 데이터와 계산 결과를 파일로 저장합니다.
     * @param checked
     */
    void saveBivariateData(bool checked);

    /**
     * @brief 가설검증을 실행합니다.
     * @param checked
     */
    void judgeNullHypothesis(bool checked);

    /**
     * @brief 가설검증 관련 edit컴포넌트를 초기화합니다.
     * @param checked
     */
    void claerNullHypothesisData(bool checked);
};

#endif // MAINWINDOW_H
