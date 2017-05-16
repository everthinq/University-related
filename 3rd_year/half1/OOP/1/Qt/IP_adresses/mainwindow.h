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

private slots:

    void on_printBTN3_clicked();
    void on_trycatchOKBTN_clicked();
    void on_trycatchFINDBTN_clicked();
    void on_trycatchADDBTN_clicked();
    void on_trycatchCLEARBTN_clicked();
    void on_MultiAddingTrigger_clicked();

    void on_BACKBTN_clicked();

    void on_okBTN2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
