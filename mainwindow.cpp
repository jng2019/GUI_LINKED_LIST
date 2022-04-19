#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "vectorList.h"

LinkedList<int> link;

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


void MainWindow::on_pushButton_clicked()
{
    int input;
    input = ui->lineEdit->text().toInt();
    link.push_back(input);
}


void MainWindow::on_pushButton_3_clicked()
{
    QString output;
    output = QString::fromStdString(link.getString());
    ui->textBrowser->setText(output);
}

