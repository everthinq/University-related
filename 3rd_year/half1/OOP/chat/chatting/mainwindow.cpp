#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&chat, SIGNAL(getMes()), this, SLOT(_getMes()));
    connect(&chat, SIGNAL(submit()), this, SLOT(_submit()));

    connect(&chat, SIGNAL(getFile()), this, SLOT(_getFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_refresh_clicked()
{
    QString users = "";

    ui->comboBox->clear();
    ui->comboBox->addItem("Всем");

    for (auto &i : chat.getUserSet())
    {
        ui->comboBox->addItem(i.c_str());
        users += i.c_str();
        users += "\n";
    }

    ui->users->setPlainText(users);
    ui->checkBox->setChecked(false);

}

void MainWindow::_getMes()
{
    std::string history;
    for (auto &i : chat.getHistory())
        history = i + history;

    ui->history->setPlainText(history.c_str());
}

void MainWindow::_submit()
{
    ui->checkBox->setChecked(true);
    qDebug("SetChecked = true");
}

void MainWindow::_getFile() //file
{
    QMessageBox box0, box1;
    box0.setText("Check your build folder for 'temp.bmp' file!1");
    box0.exec();

    box1.setText("And check your label below!1");
    box1.exec();

    QPixmap myPixmap ("temp.bmp");
    ui->label->setPixmap (myPixmap);
}

void MainWindow::on_sendBtn_clicked()
{
    ui->checkBox->setChecked(false);
    qDebug("SetChecked = false");
    std::string currentIP = ui->comboBox->currentText().toStdString(),
                message = ui->message->toPlainText().toStdString();

    if (message.empty()) return;

    ui->message->setPlainText("");

    if (currentIP == "Всем") chat.send(message, QHostAddress::Broadcast);
    else
    {
        if (currentIP == chat.getLocalIP())
        {
            QMessageBox box;
            box.setText("You can\'t send message to yourself");
            box.exec();
        }
        else chat.send(message, QHostAddress(currentIP.c_str()));
    }
}

void MainWindow::on_sendFileBtn_clicked() //file
{
    QString Filename = QFileDialog::getOpenFileName();

    std::string currentIP = ui->comboBox->currentText().toStdString();

    if ( (currentIP == "Всем") ||
         (currentIP == chat.getLocalIP()) )
    {
        QMessageBox box;
        box.setText("You can\'t send file to ALL or YOURSELF");
        box.exec();
        return;
    }

    chat.sendFile(Filename, QHostAddress(currentIP.c_str()) );
}
