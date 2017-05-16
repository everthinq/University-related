#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "chat.h"

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
    void on_sendBtn_clicked();
    void on_refresh_clicked();

    void on_sendFileBtn_clicked(); //file

public slots:
    void _getMes();
    void _submit();

    void _getFile(); //file

private:

    Ui::MainWindow *ui;
    Chat chat;
};

#endif // MAINWINDOW_H
