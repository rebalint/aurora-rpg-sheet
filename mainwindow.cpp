#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connections from character fields to UI
    ui->bodyWidget->refresh(& ch.body); //testline
}

MainWindow::~MainWindow()
{
    delete ui;
}

