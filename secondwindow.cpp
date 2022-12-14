#include "SecondWindow.h"
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



    /*ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(xx,yy);
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone); //lsNone = no line
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssStar); //ssStar = star points

    ui->customPlot->xAxis->setLabel("x"); //axis labels
    ui->customPlot->yAxis->setLabel("y");

    ui->customPlot->xAxis->setRange(0,10); //axis ranges
    ui->customPlot->yAxis->setRange(0,10);*/

   // This code works.******************************************************************************************************************

    QCPColorMap *colorMap = new QCPColorMap(ui->customPlot->xAxis, ui->customPlot->yAxis);
    QCPColorGradient *gradient = new QCPColorGradient();

    //gradient->setLevelCount(20); //sets the amount of discretised colours
    gradient->setNanHandling(QCPColorGradient::nhNone);
    gradient->setColorStopAt(0.0, QColor("#ffffff")); //lower gradient colour
    gradient->setColorStopAt(1.0, QColor("#ff0000")); //upper gradient colour

    colorMap->data()->setSize(100, 100);
      colorMap->data()->setRange(QCPRange(0, 100), QCPRange(0, 100)); //axis ranges of heat map
      for (int x=0; x<60; ++x)
        for (int y=0; y<60; ++y)
          colorMap->data()->setCell(3, 3, x+y);
      for (int x=60; x<100; ++x)
        for (int y=60; y<100; ++y)
          colorMap->data()->setCell(xx[x], yy[y], x+y);
      colorMap->setGradient(*gradient);
      colorMap->rescaleDataRange(true);
      colorMap->setInterpolate(false);
      ui->customPlot->rescaleAxes();
      ui->customPlot->replot();

//***********************************************************************************************************************************************

/* Adrian : Here I tried to plot a heat map
    // configure axis rect:
    ui->customPlot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom); // this will also allow rescaling the color scale by dragging/zooming
    ui->customPlot->axisRect()->setupFullAxesBox(true);
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");

    // set up the QCPColorMap:
    QCPColorMap *colorMap = new QCPColorMap(ui->customPlot->xAxis, ui->customPlot->yAxis);
    int nx = 200;
    int ny = 200;
    colorMap->data()->setSize(nx, ny); // we want the color map to have nx * ny data points
    colorMap->data()->setRange(QCPRange(-4, 4), QCPRange(-4, 4)); // and span the coordinate range -4..4 in both key (x) and value (y) dimensions

    // now we assign some data, by accessing the QCPColorMapData instance of the color map:
    //HERE I NEED TO CHANGE HOW TO GET DATA
    double x, y, z;
    for (int xIndex=0; xIndex<nx; ++xIndex)
    {
      for (int yIndex=0; yIndex<ny; ++yIndex)
      {
        colorMap->data()->cellToCoord(xIndex, yIndex, &x, &y);
        double r = 3*qSqrt(x*x+y*y)+1e-2;
        z = 2*x*(qCos(r+2)/r-qSin(r+2)/r); // the B field strength of dipole radiation (modulo physical constants)
        colorMap->data()->setCell(xIndex, yIndex, z);
      }
    }
    // set the color gradient of the color map to one of the presets:
    colorMap->setGradient(QCPColorGradient::gpPolar);
    // we could have also created a QCPColorGradient instance and added own colors to
    // the gradient, see the documentation of QCPColorGradient for what's possible.

    // rescale the data dimension (color) such that all data points lie in the span visualized by the color gradient:
    colorMap->rescaleDataRange();

    // rescale the key (x) and value (y) axes so the whole color map is visible:
    ui->customPlot->rescaleAxes(); */

//************************************************************************************************************************************************
}

//C:\Users\leona\OneDrive\Bureau\ScatterTest5\recData.csv
// nhTransparent 	Enumerator NaN data points appear transparent.
