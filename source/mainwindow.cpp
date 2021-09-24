#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connections from character fields to UI
    ui->bodyBox->scoreConnect(& ch.body);
    ui->mindBox->scoreConnect(& ch.mind);
    ui->soulBox->scoreConnect(& ch.soul);

    ui->nrBox->scoreConnect(& ch.nr);
    ui->srBox->scoreConnect(& ch.sr);
    ui->speedBox->scoreConnect(& ch.speed);

    ui->strengthBox->scoreConnect(& ch.strength);
    ui->nimbleBox->scoreConnect(& ch.nimble);
    ui->perceptionBox->scoreConnect(& ch.perception);
    ui->diplomacyBox->scoreConnect(& ch.diplomacy);
    ui->magicBox->scoreConnect(& ch.magic);
    ui->connectionBox->scoreConnect(& ch.connection);

    ui->hpBox->poolConnect(& ch.hp);
    ui->wpBox->poolConnect(& ch.wp);
}

MainWindow::~MainWindow()
{
    delete ui;
}

