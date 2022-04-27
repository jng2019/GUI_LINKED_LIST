#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vectorList.h"
#include "date.h"
#include "complex.h"
#include "rational.h"


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
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    VectorList<LinkedList<int>> vInt;
    VectorList<LinkedList<double>> vDouble;
    VectorList<LinkedList<string>> vString;
    VectorList<LinkedList<Date>> vDate;
    VectorList<LinkedList<Complex>> vComplex;
    VectorList<LinkedList<Rational>> vRational;


};
#endif // MAINWINDOW_H
