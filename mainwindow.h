#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "SecondWindow.h"
#include "filedata.h"


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
    std::string upload();
    void close();

private:
    Ui::MainWindow *ui;

    SecondWindow *Pointersecondwindow;

    //QString userText;//User text input
    std::string filename;//std::string of user input
    std::vector<double> x;
    std::vector<double> y;

    FileData inputData;
    bool readBoolean;
};
#endif // MAINWINDOW_H
