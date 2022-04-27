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
    int inti;
    double doublei;
    string stringi;
     Date datei;
     Rational rationali;
     Complex caomplexi;



    int row;
    QString list;
    list=ui->listWidget->currentItem()->text();

    if (list.toStdString().at(0)==QString::fromStdString("I"))
    {
        inti = ui->lineEdit->text().toInt();
        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vInt.at(row)).push_front(inti);
    }
    else if (list.toStdString().at(0)==QString::fromStdString("D"))
    {
        doublei = ui->lineEdit->text().toDouble();
        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vDouble.at(row)).push_front(doublei);
    }
    else if (list.toStdString().at(0)==QString::fromStdString("S"))
    {
        stringi = ui->lineEdit->text().toStdString();
        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vString.at(row)).push_front(stringi);
    }
    else if (list.toStdString().at(0)==QString::fromStdString("D"))
    {

    }
    else if (list.toStdString().at(0)==QString::fromStdString("R"))
    {

    }
    else if (list.toStdString().at(0)==QString::fromStdString("C"))
    {

    }
}

void MainWindow::on_pushButton_clicked() // push back button
{
    int inti;
    double doublei;
    string stringi;
     Date datei;
     Rational rationali;
     Complex caomplexi;



    int row;
    QString list;
    list=ui->listWidget->currentItem()->text();

    if (list.toStdString().at(0)==QString::fromStdString("I"))
    {
        inti = ui->lineEdit->text().toInt();
        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vInt.at(row)).push_back(inti);
    }
    else if (list.toStdString().at(0)==QString::fromStdString("D"))
    {
        doublei = ui->lineEdit->text().toDouble();
        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vDouble.at(row)).push_back(doublei);
    }
    else if (list.toStdString().at(0)==QString::fromStdString("S"))
    {
        stringi = ui->lineEdit->text().toStdString();
        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vString.at(row)).push_back(stringi);
    }
    else if (list.toStdString().at(0)==QString::fromStdString("D"))
    {

    }
    else if (list.toStdString().at(0)==QString::fromStdString("R"))
    {

    }
    else if (list.toStdString().at(0)==QString::fromStdString("C"))
    {

    }

}


void MainWindow::on_pushButton_3_clicked()  //display button
{
    LinkedList<string>::Iterator stringit;
    string sout;
    int row;
    QString list, output;
    list=ui->listWidget->currentItem()->text();

    if (list.toStdString().at(0)==QString::fromStdString("I"))
    {
        row = list.toStdString().at(list.length()-1) - '1';

        if (row<0)
        {
            ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        }
        else
            output = QString::fromStdString(vInt.at(row).getString());
    }
    else if (list.toStdString().at(0)==QString::fromStdString("D"))
    {
        row = list.toStdString().at(list.length()-1) - '1';

        if (row<0)
        {
            ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        }
        else
        {
            output = QString::fromStdString(vDouble.at(row).getString());
        }
    }
    else if (list.toStdString().at(0)==QString::fromStdString("S"))
    {
        row = list.toStdString().at(list.length()-1) - '1';

        if (row<0)
        {
            ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        }
        else
        {
            for (stringit = vString.at(row).begin(); stringit!= vString.at(row).end();++stringit)
            {
                sout += *stringit;
            }
            output = QString::fromStdString(sout);
        }
    }
    else if (list.toStdString().at(3)==QString::fromStdString("E"))
    {

    }
    else if (list.toStdString().at(0)==QString::fromStdString("R"))
    {

    }
    else if (list.toStdString().at(0)==QString::fromStdString("C"))
    {

    }

    ui->textBrowser->setText(output);
}


void MainWindow::on_pushButton_2_clicked()  //add list
{
    bool intl, doublel, stringl, rationall, datel, complexl;
    intl = ui->radioButton->isChecked();
    doublel = ui->radioButton_2->isChecked();
    stringl = ui->radioButton_3->isChecked();
    rationall = ui->radioButton_4->isChecked();
    datel = ui->radioButton_5->isChecked();
    complexl = ui->radioButton_6->isChecked();

    if (intl)
    {
        string list = "IntList " + to_string(vInt.size() + 1);
        ui->listWidget->addItem(QString::fromStdString(list));
        //LinkedList<int> *pushint;
        //pushint = new LinkedList<int>;
        //vInt.push_back(pushint);
        //LinkedList<int> temp;
        //vInt.push_back(temp);
        vInt.resize(vInt.size() + 1);
    }
    if (doublel)
    {
        string list = "DoubleList " + to_string(vDouble.size() + 1);

        ui->listWidget->addItem(QString::fromStdString(list));
        vDouble.resize(vDouble.size()+1);
    }
    if (stringl)
    {
        string list = "StringList " + to_string(vString.size() + 1);

        ui->listWidget->addItem(QString::fromStdString(list));
        vString.resize(vString.size()+1);
    }
    if (rationall)
    {
        string list = "RationalList " + to_string(vRational.size() + 1);

        ui->listWidget->addItem(QString::fromStdString(list));
        vRational.resize(vRational.size()+1);
    }
    if (datel)
    {
        string list = "DateList " + to_string(vDate.size() + 1);

        ui->listWidget->addItem(QString::fromStdString(list));
        vDate.resize(vDate.size()+1);
    }
    if (complexl)
    {
        string list = "ComplexList " + to_string(vComplex.size() + 1);

        ui->listWidget->addItem(QString::fromStdString(list));
        vComplex.resize(vComplex.size()+1);
    }
}





void MainWindow::on_pushButton_5_clicked() //insert
{

    int inti;
    double doublei;
    string stringi;
     Date datei;
     Rational rationali;
     Complex caomplexi;



    int row, index;
    QString list;
    list=ui->listWidget->currentItem()->text();

    if (list.toStdString().at(0)==QString::fromStdString("I"))
    {
        inti = ui->lineEdit->text().toInt();
        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vInt.at(row)).insert(index, inti);
    }
    else if (list.toStdString().at(0)==QString::fromStdString("D"))
    {
        doublei = ui->lineEdit->text().toDouble();
        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vDouble.at(row)).insert(index, doublei);
    }
    else if (list.toStdString().at(0)==QString::fromStdString("S"))
    {
        stringi = ui->lineEdit->text().toStdString();
        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vString.at(row)).insert(index, stringi);
    }
    else if (list.toStdString().at(0)==QString::fromStdString("D"))
    {

    }
    else if (list.toStdString().at(0)==QString::fromStdString("R"))
    {

    }
    else if (list.toStdString().at(0)==QString::fromStdString("C"))
    {

    }
}


void MainWindow::on_pushButton_4_clicked() //duplicates
{

}


void MainWindow::on_pushButton_6_clicked() //sort
{

}

