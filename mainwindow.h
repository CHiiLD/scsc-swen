#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
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

private:
    Ui::MainWindow *ui;

private slots:
    void showAbout();
    void quit();
    void genelateRandomNumber(bool checked);
    void clearRandNumberOutputBox(bool checked);
    void saveRandNumberOutput(bool checked);
};

#endif // MAINWINDOW_H
