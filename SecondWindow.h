#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include "ui_SecondWindow.h"
#include <QMainWindow>
#include <QVector>


namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

    void setX(QVector<double> givenX) {x = givenX;};
    void setY(QVector<double> givenY) {y = givenY;};

    QVector<double> getX() {return x;};
    QVector<double> getY() {return y;};


private:
    Ui::SecondWindow *ui;

    void makePlot();
    QVector<double> x;
    QVector<double> y;


};

#endif // SECONDWINDOW_H
