#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractItemModel>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void init();
    void showWrongInputMessageBox();
    void saveToFile(QString text);
private:
    Ui::MainWindow *ui;

private slots:
    void showAbout();
    void quit();

    void genelateRandomNumber(bool checked);
    void clearRandNumberOutputBox(bool checked);
    void saveRandNumberOutput(bool checked);

    void showHistogram(bool checked);
    void calcUnivariateData(bool checked);
    void clearUnivariateOutputBox(bool checked);
    void saveUnivariateOutput(bool checked);

    void showScatterPlot(bool checked);
    void calcBivariateData(bool checked);
    void clearBivariateOutputBox(bool checked);
    void saveBivariateOutput(bool checked);

    void judgeNullHypothesis(bool checked);
    void claerNullHypothesisOutputBox(bool checked);
};

#endif // MAINWINDOW_H
