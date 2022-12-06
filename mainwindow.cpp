#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "FileData.h"
#include <fstream>
#include <QMessageBox>
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //MainWindow::makePlot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::string MainWindow::upload(){

    QString userText;
    std::string input;

    userText= ui->plainTextEdit->toPlainText();
    input = userText.toStdString();

    return input;
}

void MainWindow::close(){

    Pointersecondwindow = new SecondWindow(this);
    Pointersecondwindow->setX(inputData.getX());
    Pointersecondwindow->setY(inputData.getY());

    Pointersecondwindow->show();
    this->hide();
}

void MainWindow::on_pushButton_clicked()
{
    filename = upload();
    readBoolean = inputData.readData(filename);

    if(readBoolean){
        QMessageBox::information(this, "Success", "File has been uploaded.", QMessageBox::Ok);
    }
    else{
        QMessageBox::information(this, "Error", "Could not find file, please specify the entire file location.", QMessageBox::Ok);

    }

    close();
}
