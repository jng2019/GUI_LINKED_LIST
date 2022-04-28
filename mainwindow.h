#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vectorList.h"
#include "date.h"
#include "complex.h"
#include "rational.h"
#include <QListWidgetItem>
#include <sstream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
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
    void on_pushButton_7_clicked();

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
    void on_pushButton_clicked();
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
    void on_pushButton_3_clicked();
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
    void on_pushButton_2_clicked();
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

    void on_pushButton_5_clicked();
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
    void on_pushButton_4_clicked();
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
    void on_pushButton_6_clicked();
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
    void on_pushButton_8_clicked();
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
    void on_listWidget_itemClicked(QListWidgetItem *item);
    /****************************************************************
    * POP_FRONT FUNCTION
    *
    *  This function will remove the first value in the selected linked list
    * --------------------------------------------------------------
    *   Pre: none
    * --------------------------------------------------------------
    *   Post: size of linked list decreased by 1
    ***************************************************************/
    void on_pushButton_10_clicked();
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
    void on_pushButton_9_clicked();
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
    void on_pushButton_11_clicked();
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
    void on_pushButton_12_clicked();

private:
    Ui::MainWindow *ui;

    // VECTORS OF LINKED LISTS OF EACH DATA TYPE
    VectorList<LinkedList<int>> vInt;
    VectorList<LinkedList<double>> vDouble;
    VectorList<LinkedList<string>> vString;
    VectorList<LinkedList<Date>> vDate;
    VectorList<LinkedList<Complex>> vComplex;
    VectorList<LinkedList<Rational>> vRational;


};
#endif // MAINWINDOW_H
