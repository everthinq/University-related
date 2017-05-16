#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lopi.h"

lopi Object1;
int count;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//TRYCATCH BEGIN
void MainWindow::on_printBTN3_clicked()
{
    Object1.print();
}

void MainWindow::on_trycatchOKBTN_clicked()
{
    Object1.list.clear();
    int count = ui->trycatchOKEDIT->text().toInt();
    Object1.setRandomPositiveIntegers(count);
    Object1.print();
    ui->trycatchOKEDIT->clear();
}

void MainWindow::on_trycatchFINDBTN_clicked()
{
    try
    {
        if (ui->trycatchFINDEDIT->text().isEmpty() )
            return;

        int i = ui->trycatchFINDEDIT->text().toInt();

        if ( (i >= 0) && (i < Object1.list.size()) )
             Object1.getNumber(i);
        else
            throw i;
    }

    catch (int FINDBTNexception)
    {
        qDebug() << "The index is not in range.\n";
    }

    ui->trycatchFINDEDIT->clear();
}

void MainWindow::on_trycatchADDBTN_clicked()
{
    try
    {
        if (ui->trycatchADDI->text().isEmpty() )
            return;

        int value = ui->trycatchADDI->text().toInt();

        if (Object1.list.contains(value) )
                throw value;
        else
        {
            Object1.putNumber(value);
            Object1.print();
        }
    }

    catch (int ADDBTNexception)
    {
        qDebug() << "Value is already in list.\n";
    }

    ui->trycatchADDI->clear();
}

void MainWindow::on_trycatchCLEARBTN_clicked()
{
    Object1.clear();
}

void MainWindow::on_MultiAddingTrigger_clicked()
{
    ui->tabWidget->setCurrentWidget(ui->tab);
}
//TRYCATCH END

//POS ADD BEGIN
void MainWindow::on_BACKBTN_clicked()
{
    ui->tabWidget->setCurrentWidget(ui->tab_3);
}

void MainWindow::on_okBTN2_clicked()
{
    try
    {
        if (ui->VALUE->text().isEmpty() )
            return;

        if (ui->POS->text().isEmpty() )
            return;


        int pos = ui->POS->text().toInt();
      int value = ui->VALUE->text().toInt();

      if (Object1.list.contains(value) )
              throw value;
      else
      {
          Object1.add(pos, value);

          ui->POS->clear();
          ui->VALUE->clear();

          Object1.print();
      }

    }

    catch (int)
    {
        qDebug() << "Value is already in list.\n";
    }
}
//POS ADD END
