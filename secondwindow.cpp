#include "secondwindow.h"
#include "ui_SecondWindow.h"
#include "qcustomplot.cpp"
#include <iostream>
#include <QMessageBox>


SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    SecondWindow::makePlot();

}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::makePlot() {

    QVector<double> xx(101), yy(101); //101 = the amount of data points
    for (int i=0; i<100; i++) {
        xx[i] = i; //set x-values
        yy[i] = i; //set y-values
    }

    //qDebug() << QString::number(this->x.isEmpty());

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(xx,yy);
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone); //lsNone = no line
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssStar); //ssStar = star points

    ui->customPlot->xAxis->setLabel("x"); //axis labels
    ui->customPlot->yAxis->setLabel("y");

    ui->customPlot->xAxis->setRange(0,10); //axis ranges
    ui->customPlot->yAxis->setRange(0,10);
}

//C:\Users\leona\OneDrive\Bureau\ScatterTest5\recData.csv
