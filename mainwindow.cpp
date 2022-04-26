#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_7_clicked() // push front
{
    int row = ui->listWidget->currentRow();
    int input;
    input = ui->lineEdit->text().toInt();
    if(row==-1)
        ui->textBrowser->setText(QString::fromStdString("No list selected!"));
    else
        (vInt.at(row)).push_front(input);
}

void MainWindow::on_pushButton_clicked() // push back button
{
    int row = ui->listWidget->currentRow();
    int input;
    input = ui->lineEdit->text().toInt();
    if (row==-1)
            ui->textBrowser->setText(QString::fromStdString("No list selected!"));
    else
        (vInt.at(row)).push_back(input);
}


void MainWindow::on_pushButton_3_clicked()  //display button
{
    int row = ui->listWidget->currentRow();
    ui->listWidget.cur
    QString output;
    output = QString::fromStdString(vInt.at(row).getString());

    if(row==-1)
    {
        ui->textBrowser->setText(QString::fromStdString("No list selected!"));
    }
    else
        ui->textBrowser->setText(output);
}


void MainWindow::on_pushButton_2_clicked()  //add list
{
    bool intl, doublel, stringl, rationall, datel, complex;
    intl = ui->radioButton->isChecked();
    doublel = ui->radioButton_2->isChecked();
//    stringl = ui->radioButton_3->isChecked();
//    rationall = ui->radioButton_4->isChecked();
//    datel = ui->radioButton_5->isChecked();
//    complex = ui->radioButton_6->isChecked();

    if (intl)
    {
        ui->listWidget->addItem(QString::fromStdString("IntList"));
        //LinkedList<int> *pushint;
        //pushint = new LinkedList<int>;
        //vInt.push_back(pushint);
        //LinkedList<int> temp;
        //vInt.push_back(temp);
        vInt.resize(vInt.size() + 1);
    }
    if (doublel)
    {
        ui->listWidget->addItem(QString::fromStdString("DoubleList"));
        vDouble.resize(vDouble.size()+1);
    }
}





void MainWindow::on_pushButton_5_clicked() //insert
{

    int index = ui->lineEdit_2->text().toInt();
    int row = ui->listWidget->currentRow();

//    if (index >=0)
//    {
//        vInt.at(row).insert(index, )
//    }
}


void MainWindow::on_pushButton_4_clicked() //duplicates
{

}


void MainWindow::on_pushButton_6_clicked() //sort
{

}

