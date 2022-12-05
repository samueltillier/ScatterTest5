#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::makePlot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makePlot() {
    QVector<double> x(101), y(101); //101 = the amount of data points
    for (int i=0; i<100; i++) {
        x[i] = i; //set x-values
        y[i] = i; //set y-values
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x,y);
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone); //lsNone = no line
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssStar); //ssStar = star points

    ui->customPlot->xAxis->setLabel("x"); //axis labels
    ui->customPlot->yAxis->setLabel("y");

    ui->customPlot->xAxis->setRange(0,100); //axis ranges
    ui->customPlot->yAxis->setRange(0,100);
}
//comment
