#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // IF THERE ARE NO LISTS DISABLE BUTTONS
    if (ui->listWidget->count()==0)
    {
        ui->pushButton->setEnabled(false);
        ui->pushButton_11->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        ui->pushButton_9->setEnabled(false);
        ui->pushButton_10->setEnabled(false);
    }
    ui->lineEdit_2->setPlaceholderText("index: ");
}

MainWindow::~MainWindow()
{
    delete ui;
}
/****************************************************************
* PUSH_FRONT FUNCTION
*
*  This function will push a value inputted to the front of the
*  linked list selected in the list widget
* --------------------------------------------------------------
*   Pre: value inputted matches the data type stored in linked list
*   selected
* --------------------------------------------------------------
*   Post: size of linked list increased by 1
***************************************************************/
void MainWindow::on_pushButton_7_clicked() // push front
{
    int inti;
    double doublei;
    string stringi;




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
    else if (list.toStdString().substr(0, 2)=="Do")
    {
        doublei = ui->lineEdit->text().toDouble();
        doublei = floor(doublei * 100.0) / 100.0;

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
    else if (list.toStdString().substr(0, 2)=="Da")
    {
        unsigned day, month, year;
        string l = ui->lineEdit->text().toStdString();
        stringstream ss(l);

        ss >> month;
        ss.ignore(256, '/');
        ss >> day;
        ss.ignore(256, '/');
        ss >> year;

        Date datei(month, day, year);
        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vDate.at(row)).push_front(datei);

        cout << month << " " << day << " " << year << endl;

    }
    else if (list.toStdString().at(0)==QString::fromStdString("R"))
    {

        int num, den;
        string l = ui->lineEdit->text().toStdString();
        stringstream ss(l);

        ss >> num;
        ss.ignore(256, '/');
        ss >> den;

        Rational rationali(num, den);

        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vRational.at(row)).push_front(rationali);


    }
    else if (list.toStdString().at(0)==QString::fromStdString("C"))
    {

        double real, ima;
        string l = ui->lineEdit->text().toStdString();
        stringstream ss(l);

        ss >> real;
        ss.ignore(256, '+');
        ss >> ima;

        real = floor(real * 100.0) / 100.0;
        ima = floor(ima * 100.0) / 100.0;

        Complex complexi(real, ima);

        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vComplex.at(row)).push_front(complexi);
    }
}

/****************************************************************
* PUSH_BACK FUNCTION
*
*  This function will push a value inputted to the bcak of the
*  linked list selected in the list widget
* --------------------------------------------------------------
*   Pre: value inputted matches the data type stored in linked list
*   selected
* --------------------------------------------------------------
*   Post: size of linked list increased by 1
***************************************************************/
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
    else if (list.toStdString().substr(0,2)=="Do")
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
    else if (list.toStdString().substr(0,2)=="Da")
    {
        unsigned day, month, year;
        string l = ui->lineEdit->text().toStdString();
        stringstream ss(l);

        ss >> month;
        ss.ignore(256, '/');
        ss >> day;
        ss.ignore(256, '/');
        ss >> year;

        Date datei(month, day, year);
        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vDate.at(row)).push_back(datei);

    }
    else if (list.toStdString().at(0)==QString::fromStdString("R"))
    {
        int num, den;
        string l = ui->lineEdit->text().toStdString();
        stringstream ss(l);

        ss >> num;
        ss.ignore(256, '/');
        ss >> den;


        Rational rationali(num, den);

        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vRational.at(row)).push_back(rationali);
    }
    else if (list.toStdString().at(0)==QString::fromStdString("C"))
    {
        double real, ima;
        char val;
        string l = ui->lineEdit->text().toStdString();
        stringstream ss(l);

        ss >> real;
        ss >> val;
        ss >> ima;

        if (val=='-')
            ima *= -1;
        Complex complexi(real, ima);

        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
        {
            cout << ima << endl;
            (vComplex.at(row)).push_back(complexi);
        }
    }

}

/****************************************************************
* DISPLAY FUNCTION
*
*  This function will display all values of the linked list
*  selected in the list widget
* --------------------------------------------------------------
*   Pre: none
* --------------------------------------------------------------
*   Post: size of linked list increased by 1
***************************************************************/
void MainWindow::on_pushButton_3_clicked()  //display button
{
    LinkedList<string>::Iterator stringit;
    LinkedList<Date>::Iterator dateit;
    LinkedList<Complex>::Iterator comit;
    LinkedList<Rational>::Iterator ratit;

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
        {
            cout << vInt.at(row).length() << endl;
            if (vInt.at(row).length() >0)
            {
                output = QString::fromStdString(vInt.at(row).getString());
            }
            else
            {
                ui->textBrowser->setText(QString::fromStdString("List Empty!"));
            }
        }
    }
    else if (list.toStdString().substr(0,2)=="Do")
    {
        row = list.toStdString().at(list.length()-1) - '1';

        if (row<0)
        {
            ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        }
        else
        {
            cout << vDouble.at(row).length() << endl;
            if (vDouble.at(row).length() >0)
                output = QString::fromStdString(vDouble.at(row).getString());
            else
            {
                ui->textBrowser->setText(QString::fromStdString("List Empty!"));
                cout << "ran\n";
            }
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
            if (vString.at(row).length() > 0)
            {
                for (stringit = vString.at(row).begin(); stringit!= vString.at(row).end();++stringit)
                {
                    sout += *stringit + " ";
                }
                output = QString::fromStdString(sout);
            }
            else
            {    ui->textBrowser->setText(QString::fromStdString("List Empty!"));
                cout << "ran\n";
            }
        }
    }
    else if (list.toStdString().substr(0,2)=="Da")
    {
        row = list.toStdString().at(list.length()-1) - '1';

        if (row<0)
        {
            ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        }
        else
        {
            if (vDate.at(row).length() > 0)
            {
                for (dateit = vDate.at(row).begin(); dateit!= vDate.at(row).end();++dateit)
                {
                    Date dateobj = *dateit;
                    sout += dateobj.getNum() + " ";
                }
                output = QString::fromStdString(sout);
            }
            else
            {    ui->textBrowser->setText(QString::fromStdString("List Empty!"));
                cout << "ran\n";
            }
        }
    }
    else if (list.toStdString().at(0)==QString::fromStdString("R"))
    {
        row = list.toStdString().at(list.length()-1) - '1';

        if (row<0)
        {
            ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        }
        else
        {
            if (vRational.at(row).length() > 0)
            {
                for (ratit = vRational.at(row).begin(); ratit!= vRational.at(row).end();++ratit)
                {
                    Rational ratobj = *ratit;
                    sout += ratobj.getNum() + " "; //
                    cout << sout << endl;
                }
                output = QString::fromStdString(sout);
            }
            else
            {    ui->textBrowser->setText(QString::fromStdString("List Empty!"));
                cout << "ran\n";
            }
        }
    }
    else if (list.toStdString().at(0)==QString::fromStdString("C"))
    {
        row = list.toStdString().at(list.length()-1) - '1';

        if (row<0)
        {
            ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        }
        else
        {
            if (vComplex.at(row).length() > 0)
            {
                for (comit = vComplex.at(row).begin(); comit!= vComplex.at(row).end();++comit)
                {
                    Complex comobj = *comit;
                    sout += comobj.getNum() + "i "; //
                    cout << sout << endl;
                }
                output = QString::fromStdString(sout);
            }
            else
            {    ui->textBrowser->setText(QString::fromStdString("List Empty!"));
                cout << "ran\n";
            }
        }
    }

    ui->textBrowser->setText(output);
}

/****************************************************************
* ADD_LIST FUNCTION
*
*  This function will add a new list to whatever data is selected
*  by the radio buttons the the vector of linked lists
* --------------------------------------------------------------
*   Pre: none
* --------------------------------------------------------------
*   Post: size of vector linked list of data type increased by 1
***************************************************************/
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

/****************************************************************
* INSERT FUNCTION
*
*  This function will inserts a value inputted to the
*  linked list selected in the list widget at the inputted index
* --------------------------------------------------------------
*   Pre: value inputted matches the data type stored in linked list
*   selected
*   index inputted exists in the linked list
* --------------------------------------------------------------
*   Post: size of linked list increased by 1
***************************************************************/
void MainWindow::on_pushButton_5_clicked() //insert
{

    int inti;
    double doublei;
    string stringi;
     Date datei;
     Rational rationali;
     Complex complexi;



    int row, index;
    QString list;
    list=ui->listWidget->currentItem()->text();
    string indexi = ui->lineEdit_2->text().toStdString();
    index = indexi.at(indexi.length()-1) - '0';

    if (list.toStdString().at(0)==QString::fromStdString("I"))
    {
        inti = ui->lineEdit->text().toInt();
        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
        {
            (vInt.at(row)).insert(index, inti);
            cout << "inserted : " << inti << endl;
        }
        cout << "inti : " << inti << " index : " << index << " row: " << row  << endl;
    }
    else if (list.toStdString().substr(0,2)=="Do")
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
    else if (list.toStdString().substr(0,2)=="Da")
    {
        unsigned day, month, year;
        string l = ui->lineEdit->text().toStdString();
        stringstream ss(l);

        ss >> month;
        ss.ignore(256, '/');
        ss >> day;
        ss.ignore(256, '/');
        ss >> year;

        Date datei(month, day, year);
        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vDate.at(row)).insert(index, datei);

    }
    else if (list.toStdString().at(0)==QString::fromStdString("R"))
    {
        int num, den;
        string l = ui->lineEdit->text().toStdString();
        stringstream ss(l);

        ss >> num;
        ss.ignore(256, '/');
        ss >> den;


        Rational rationali(num, den);

        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vRational.at(row)).insert(index, rationali);
    }
    else if (list.toStdString().at(0)==QString::fromStdString("C"))
    {
        double real, ima;
        char val;
        string l = ui->lineEdit->text().toStdString();
        stringstream ss(l);

        ss >> real;
        ss >> val;
        ss >> ima;

        if (val=='-')
            ima *= -1;
        Complex complexi(real, ima);

        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
        {
            cout << ima << endl;
            (vComplex.at(row)).insert(index, complexi);
        }
    }
}

/****************************************************************
* REMOVE_DUPLICATES FUNCTION
*
*  This function will remove all duplicates in the linked list
*  selected in the list widget
* --------------------------------------------------------------
*   Pre: none
* --------------------------------------------------------------
*   Post: sizse of linked list decreases
***************************************************************/
void MainWindow::on_pushButton_4_clicked() //duplicates
{

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
        {
            vInt.at(row).remove_duplicates();
        }
    }
    else if (list.toStdString().substr(0,2)=="Do")
    {
        row = list.toStdString().at(list.length()-1) - '1';

        if (row<0)
        {
            ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        }
        else
        {
            vDouble.at(row).remove_duplicates();
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
            vString.at(row).remove_duplicates();
        }
    }
    else if (list.toStdString().substr(0,2)=="Da")
    {
        row = list.toStdString().at(list.length()-1) - '1';

        if (row<0)
        {
            ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        }
        else
        {
            vDate.at(row).remove_duplicates();
        }
    }
    else if (list.toStdString().at(0)==QString::fromStdString("R"))
    {
        row = list.toStdString().at(list.length()-1) - '1';

        if (row<0)
        {
            ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        }
        else
        {
            vRational.at(row).remove_duplicates();
        }
    }
    else if (list.toStdString().at(0)==QString::fromStdString("C"))
    {
        row = list.toStdString().at(list.length()-1) - '1';

        if (row<0)
        {
            ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        }
        else
        {
            vComplex.at(row).remove_duplicates();
        }
    }
}

/****************************************************************
* SORT FUNCTION
*
*  This function will sort the linked list selected in the list
*  widget
* --------------------------------------------------------------
*   Pre: none
* --------------------------------------------------------------
*   Post: none
***************************************************************/
void MainWindow::on_pushButton_6_clicked() //sort
{
    int row;
    QString list;
    list=ui->listWidget->currentItem()->text();

    if (list.toStdString().at(0)==QString::fromStdString("I"))
    {
        row = list.toStdString().at(list.length()-1) - '1';

        if (row<0)
        {
            ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        }
        else
        {
            vInt.at(row).select_sort();
        }
    }
    else if (list.toStdString().substr(0,2)=="Do")
    {
        row = list.toStdString().at(list.length()-1) - '1';

        if (row<0)
        {
            ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        }
        else
        {
            vDouble.at(row).select_sort();
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
            vString.at(row).select_sort();
        }
    }
    else if (list.toStdString().substr(0,2)=="Da")
    {
        cout << "HLLO\n";
        row = list.toStdString().at(list.length()-1) - '1';

        if (row<0)
        {
            ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        }
        else
        {
            vDate.at(row).select_sort();
        }
    }
    else if (list.toStdString().at(0)==QString::fromStdString("R"))
    {
        row = list.toStdString().at(list.length()-1) - '1';

        if (row<0)
        {
            ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        }
        else
        {
            vRational.at(row).select_sort();
        }
    }


}
/****************************************************************
* COPY LIST FUNCTION
*
*  This function will create a new list from an existing linked
*  list and copy over values from the old list
* --------------------------------------------------------------
*   Pre: none
* --------------------------------------------------------------
*   Post: size of vector linked list of data type increased by 1
***************************************************************/

void MainWindow::on_pushButton_8_clicked() // copy
{
    QString list;
    list=ui->listWidget->currentItem()->text();
    int row;
    row = list.toStdString().at(list.length()-1) - '1';

    if (list.toStdString().at(0)==QString::fromStdString("I"))
    {
        string list = "IntList Copy " + to_string(vInt.size() + 1);
        ui->listWidget->addItem(QString::fromStdString(list));
        vInt.resize(vInt.size() + 1);

        for (int i = 0; i < vInt.at(row).length();i++)
        {
            vInt.at(vInt.size()-1).push_back(vInt.at(row).at(i));
        }
    }
    else if (list.toStdString().substr(0,2)=="Do")
    {
        string list = "DoubleList Copy " + to_string(vDouble.size() + 1);

        ui->listWidget->addItem(QString::fromStdString(list));
        vDouble.resize(vDouble.size()+1);

        for (int i = 0; i < vDouble.at(row).length();i++)
        {
            vDouble.at(vDouble.size()-1).push_back(vDouble.at(row).at(i));
        }
    }
    else if (list.toStdString().at(0)==QString::fromStdString("S"))
    {
        string list = "StringList Copy " + to_string(vString.size() + 1);

        ui->listWidget->addItem(QString::fromStdString(list));
        vString.resize(vString.size()+1);
        for (int i = 0; i < vString.at(row).length();i++)
        {
            vString.at(vString.size()-1).push_back(vString.at(row).at(i));
        }
    }
    else if (list.toStdString().substr(0,2)=="Da")
    {
        string list = "DateList Copy " + to_string(vDate.size() + 1);

        ui->listWidget->addItem(QString::fromStdString(list));
        vDate.resize(vDate.size()+1);

        for (int i = 0; i < vDate.at(row).length();i++)
        {
            vDate.at(vDate.size()-1).push_back(vDate.at(row).at(i));
        }
    }
    else if (list.toStdString().at(0)==QString::fromStdString("R"))
    {
        string list = "RationalList Copy " + to_string(vRational.size() + 1);

        ui->listWidget->addItem(QString::fromStdString(list));
        vRational.resize(vRational.size()+1);

        for (int i = 0; i < vRational.at(row).length();i++)
        {
            vRational.at(vRational.size()-1).push_back(vRational.at(row).at(i));
        }
    }
    else if (list.toStdString().at(0)==QString::fromStdString("C"))
    {
        string list = "ComplexList Copy " + to_string(vComplex.size() + 1);

        ui->listWidget->addItem(QString::fromStdString(list));
        vComplex.resize(vComplex.size()+1);
        for (int i = 0; i < vComplex.at(row).length();i++)
        {
            vComplex.at(vComplex.size()-1).push_back(vComplex.at(row).at(i));
        }
    }
}
/****************************************************************
* GREY OUT FUNCTION
*
*  This function will gray out the sort and insert sorted when
*  a complex linked list is selected
* --------------------------------------------------------------
*   Pre: none
* --------------------------------------------------------------
*   Post: none
***************************************************************/

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)  // gray out sort button for complex
{
    QString list;
    list=ui->listWidget->currentItem()->text();
    if (list.toStdString().at(0)!=QString::fromStdString("C"))
    {
        // gray out sort button
        ui->pushButton->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
        ui->pushButton_8->setEnabled(true);
        ui->pushButton_9->setEnabled(true);
        ui->pushButton_10->setEnabled(true);
        ui->pushButton_11->setEnabled(true);

    }
    else {
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_9->setEnabled(false);
    }

    if (list.toStdString().substr(0, 2)=="Da")
    {
        ui->lineEdit->setPlaceholderText("mm/dd//yyyy");
    }
    else if (list.toStdString().at(0)==QString::fromStdString("R"))
    {
        ui->lineEdit->setPlaceholderText("numer / denom");
    }
    else if (list.toStdString().at(0)==QString::fromStdString("C"))
    {
        ui->lineEdit->setPlaceholderText("real + imaginary(i)");
    }
    else
    {
        ui->lineEdit->setPlaceholderText("");
    }
}

/****************************************************************
* POP_FRONT FUNCTION
*
*  This function will remove the first value in the selected linked list
* --------------------------------------------------------------
*   Pre: none
* --------------------------------------------------------------
*   Post: size of linked list decreased by 1
***************************************************************/
void MainWindow::on_pushButton_10_clicked() // popfront
{
    int row;
    QString list;
    list=ui->listWidget->currentItem()->text();

    if (list.toStdString().at(0)==QString::fromStdString("I"))
    {
        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
        {    (vInt.at(row)).pop_front();
            cout << "popfront ran\n";
        }
    }
    else if (list.toStdString().substr(0, 2)=="Do")
    {
        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vDouble.at(row)).pop_front();
    }
    else if (list.toStdString().at(0)==QString::fromStdString("S"))
    {
        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vString.at(row)).pop_front();
    }
    else if (list.toStdString().substr(0, 2)=="Da")
    {

        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vDate.at(row)).pop_front();

    }
    else if (list.toStdString().at(0)==QString::fromStdString("R"))
    {

        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vRational.at(row)).pop_front();


    }
    else if (list.toStdString().at(0)==QString::fromStdString("C"))
    {

        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vComplex.at(row)).pop_front();
    }
}
/****************************************************************
insert_sorted
This function assumes the list is already sorted and will insert
VALUE into the appropriate location so the list will remain sorted
__________________________________________________
    Pre:
      List is and is sorted
__________________________________________________
    Post:
      size of list increased by 1, list is still sorted
****************************************************************/

void MainWindow::on_pushButton_9_clicked() // insert sorted
{

    int inti;
    double doublei;
    string stringi;
     Date datei;
     Rational rationali;


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
            (vInt.at(row)).insert_sorted(inti);
    }
    else if (list.toStdString().substr(0, 2)=="Do")
    {
        doublei = ui->lineEdit->text().toDouble();
        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vDouble.at(row)).insert_sorted(doublei);
    }
    else if (list.toStdString().at(0)==QString::fromStdString("S"))
    {
        stringi = ui->lineEdit->text().toStdString();
        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vString.at(row)).insert_sorted(stringi);
    }
    else if (list.toStdString().substr(0, 2)=="Da")
    {
        unsigned day, month, year;
        string l = ui->lineEdit->text().toStdString();
        stringstream ss(l);

        ss >> month;
        ss.ignore(256, '/');
        ss >> day;
        ss.ignore(256, '/');
        ss >> year;

        Date datei(month, day, year);
        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vDate.at(row)).insert_sorted(datei);

        cout << month << " " << day << " " << year << endl;

    }
    else if (list.toStdString().at(0)==QString::fromStdString("R"))
    {

        int num, den;
        string l = ui->lineEdit->text().toStdString();
        stringstream ss(l);

        ss >> num;
        ss.ignore(256, '/');
        ss >> den;

        Rational rationali(num, den);

        row = list.toStdString().at(list.length()-1) - '1';
        if (row<0)
                ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        else
            (vRational.at(row)).insert_sorted(rationali);
    }

}
/****************************************************************
* DISPLAY_PART FUNCTION
*
*  This function will display part of the linked list selected
*  part is determined by user input
* --------------------------------------------------------------
*   Pre: the indexes inputted exist in the list
* --------------------------------------------------------------
*   Post: none
***************************************************************/

void MainWindow::on_pushButton_11_clicked() // display part
{

    LinkedList<int>::Iterator intit;
    LinkedList<double>::Iterator dit;
    LinkedList<string>::Iterator stringit;
    LinkedList<Date>::Iterator dateit;
    LinkedList<Complex>::Iterator comit;
    LinkedList<Rational>::Iterator ratit;
    int begin, end;
    string input = ui->lineEdit_3->text().toStdString();
    stringstream ss(input);
    ss >> begin;
    ss.ignore(256, '-');
    ss >> end;
    QString list;
    list=ui->listWidget->currentItem()->text();
    int row;
    row = list.toStdString().at(list.length()-1) - '1';
    cout << begin << " " << end << endl;

    string sout;
    QString output;
    list=ui->listWidget->currentItem()->text();

    if (list.toStdString().at(0)==QString::fromStdString("I"))
    {
        if (row<0)
        {
            ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        }
        else
        {
            if (vInt.at(row).length()-1 >= begin && vInt.at(row).length() - 1 >= end)
            {
                cout << vInt.at(row).length() << endl;
                if (vInt.at(row).length() >0)
                {
                    cout << "ADSF\n";
                    intit = vInt.at(row).begin();
                    for(int i = 0; i < begin; i++)
                    {
                        ++intit;
                    }
                    for(int i = begin; i <= end; i++)
                    {
                        output += QString::fromStdString(to_string(*intit)) + " ";
                        ++intit;
                    }
                }
                else
                {
                    ui->textBrowser->setText(QString::fromStdString("List Empty!"));
                }
            }
        }
    }
    else if (list.toStdString().substr(0,2)=="Do")
    {
        row = list.toStdString().at(list.length()-1) - '1';

        if (row<0)
        {
            ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        }
        else
        {
            if (vDouble.at(row).length()-1 >= begin && vDouble.at(row).length() - 1 >= end)
            {
                if (vDouble.at(row).length() >0)
                {
                    cout << "ADSF\n";
                    dit = vDouble.at(row).begin();
                    for(int i = 0; i < begin; i++)
                    {
                        ++dit;
                    }
                    for(int i = begin; i <= end; i++)
                    {
                        output += QString::fromStdString(to_string(*dit)) + " ";
                        ++dit;
                    }
                }
                else
                {
                    ui->textBrowser->setText(QString::fromStdString("List Empty!"));
                }
            }
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
            if (vString.at(row).length()-1 >= begin && vString.at(row).length() - 1 >= end)
            {
                if (vString.at(row).length() >0)
                {
                    cout << "ADSF\n";
                    stringit = vString.at(row).begin();
                    for(int i = 0; i < begin; i++)
                    {
                        ++stringit;
                    }
                    for(int i = begin; i <= end; i++)
                    {
                        output += QString::fromStdString(*stringit) + " ";
                        ++stringit;
                    }
                }
                else
                {
                    ui->textBrowser->setText(QString::fromStdString("List Empty!"));
                }
            }
        }
    }
    else if (list.toStdString().substr(0,2)=="Da")
    {
        row = list.toStdString().at(list.length()-1) - '1';

        if (row<0)
        {
            ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        }
        else
        {
            if (vDate.at(row).length()-1 >= begin && vDate.at(row).length() - 1 >= end)
            {
                if (vDate.at(row).length() >0)
                {
                    cout << "ADSF\n";
                    dateit = vDate.at(row).begin();
                    for(int i = 0; i < begin; i++)
                    {
                        ++dateit;
                    }
                    for(int i = begin; i <= end; i++)
                    {
                        Date dateobj = *dateit;
                        output += QString::fromStdString(dateobj.getNum()) + " ";
                        ++dateit;
                    }
                }
                else
                {
                    ui->textBrowser->setText(QString::fromStdString("List Empty!"));
                }
            }
        }
    }
    else if (list.toStdString().at(0)==QString::fromStdString("R"))
    {
        row = list.toStdString().at(list.length()-1) - '1';

        if (row<0)
        {
            ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        }
        else
        {
            if (vRational.at(row).length()-1 >= begin && vRational.at(row).length() - 1 >= end)
            {
                if (vRational.at(row).length() >0)
                {
                    cout << "ADSF\n";
                    ratit = vRational.at(row).begin();
                    for(int i = 0; i < begin; i++)
                    {
                        ++ratit;
                    }
                    for(int i = begin; i <= end; i++)
                    {
                        Rational ratobj = *ratit;
                        output += QString::fromStdString(ratobj.getNum()) + " ";
                        ++ratit;
                    }
                }
                else
                {
                    ui->textBrowser->setText(QString::fromStdString("List Empty!"));
                }
            }
        }
    }
    else if (list.toStdString().at(0)==QString::fromStdString("C"))
    {
        row = list.toStdString().at(list.length()-1) - '1';

        if (row<0)
        {
            ui->textBrowser->setText(QString::fromStdString("No list selected!"));
        }
        else
        {
            if (vComplex.at(row).length()-1 >= begin && vComplex.at(row).length() - 1 >= end)
            {
                if (vComplex.at(row).length() >0)
                {
                    cout << "ADSF\n";
                    comit = vComplex.at(row).begin();
                    for(int i = 0; i < begin; i++)
                    {
                        ++comit;
                    }
                    for(int i = begin; i <= end; i++)
                    {
                        Complex comobj = *comit;
                        output += QString::fromStdString(comobj.getNum()) + " ";
                        ++comit;
                    }
                }
                else
                {
                    ui->textBrowser->setText(QString::fromStdString("List Empty!"));
                }
            }
        }
    }

    ui->textBrowser->setText(output);

}

/****************************************************************
* DELETE FUNCTION
*
*  This function will remove a linked list from the list widget
*  and deallocate all memory from the linked list while removing it
*  from the vector of linked lists
* --------------------------------------------------------------
*   Pre: none
* --------------------------------------------------------------
*   Post: size of vector of linked list decreased by 1
***************************************************************/
void MainWindow::on_pushButton_12_clicked() // delete list
{
    QString list;
    list=ui->listWidget->currentItem()->text();
    int row;
    row = list.toStdString().at(list.length()-1) - '1';

    if (list.toStdString().at(0)==QString::fromStdString("I"))
    {
        // remove the list from widget
        // remove the list from the vector list
        qDeleteAll(ui->listWidget->selectedItems());
        vInt.at(row).~LinkedList<int>();
        vInt.resize(vInt.size());

    }
    else if (list.toStdString().substr(0,2)=="Do")
    {
        // remove the list from widget
        // remove the list from the vector list
        qDeleteAll(ui->listWidget->selectedItems());
        vDouble.at(row).~LinkedList<double>();
        vDouble.resize(vDouble.size());
    }
    else if (list.toStdString().at(0)==QString::fromStdString("S"))
    {
        // remove the list from widget
        // remove the list from the vector list
        qDeleteAll(ui->listWidget->selectedItems());
        vString.at(row).~LinkedList<string>();
        vString.resize(vString.size());
    }
    else if (list.toStdString().substr(0,2)=="Da")
    {
        // remove the list from widget
        // remove the list from the vector list
        qDeleteAll(ui->listWidget->selectedItems());
        vDate.at(row).~LinkedList<Date>();
        vDate.resize(vDate.size());
    }
    else if (list.toStdString().at(0)==QString::fromStdString("R"))
    {
        // remove the list from widget
        // remove the list from the vector list
        qDeleteAll(ui->listWidget->selectedItems());
        vRational.at(row).~LinkedList<Rational>();
        vRational.resize(vRational.size());
    }
    else if (list.toStdString().at(0)==QString::fromStdString("C"))
    {
        // remove the list from widget
        // remove the list from the vector list
        qDeleteAll(ui->listWidget->selectedItems());
        vComplex.at(row).~LinkedList<Complex>();
        vComplex.resize(vComplex.size());
    }
}

