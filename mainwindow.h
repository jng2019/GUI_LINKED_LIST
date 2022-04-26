#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vectorList.h"

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
    VectorList<LinkedList<int>> vDouble;
    VectorList<LinkedList<int>> vString;
    VectorList<LinkedList<int>> vDate;
    VectorList<LinkedList<int>> vComplex;
    VectorList<LinkedList<int>> vRational;


};
#endif // MAINWINDOW_H
