#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "vectorList.h"

VectorList<LinkedList<int>> v;

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
    (v.at(row)).push_front(input);
}

void MainWindow::on_pushButton_clicked() // push back button
{
    int row = ui->listWidget->currentRow();
    int input;
    input = ui->lineEdit->text().toInt();
    (v.at(row)).push_back(input);
}


void MainWindow::on_pushButton_3_clicked()  //display button
{
    int row = ui->listWidget->currentRow();
    QString output;
    output = QString::fromStdString(to_string(row));
//    output = QString::fromStdString(v.at(row-1).getString());
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
    stringl = ui->radioButton_3->isChecked();
    rationall = ui->radioButton_4->isChecked();
    datel = ui->radioButton_5->isChecked();
    complex = ui->radioButton_6->isChecked();

    if (intl)
    {
        ui->listWidget->addItem(QString::fromStdString("IntList"));
        LinkedList<int> pushint;

        //v.push_back(pushint);
    }
}




