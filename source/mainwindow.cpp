#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    raceLoader();

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

void MainWindow::raceLoader(){
    //TODO ERROR HANDLING OR DIE
    QFile racefileHandler(":/races.txt");
    if(!racefileHandler.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Failed to open racefile.";
        exit(EXIT_FAILURE);
    }

    QTextStream racefile(&racefileHandler);

    QString line;
    int raceNumber; //contains number of races we will need to load

    line = racefile.readLine();

    raceNumber = line.toInt();

    qDebug() << "race number: " << raceNumber;

    for(int currentRaceNum = 0; currentRaceNum < raceNumber; currentRaceNum++){
        PRace current;
        int propNum;    //number of extra properties for currently loading race

        line = racefile.readLine();

        //sanity check and get propNum
        if(line.startsWith("RACE")){
            propNum = line.remove(0, 4).toInt();    //extract propNum
        } else {
            qDebug() << line;
            qDebug() << "Raceloader failed due to missing or badly processed RACE header";
            exit(EXIT_FAILURE);
        }

        //load name, desc, subraceof
        line = racefile.readLine();
        current.name = line.section('|', 0, 0);
        current.description = line.section('|', 1, 1);

        line = racefile.readLine();
        current.subraceof = line.section(' ', 1, 1);

        for(int currentPropNum = 0; currentPropNum < propNum; currentPropNum++){
            line = racefile.readLine();
            //TODO add processing
        }

        //finished processing, adding race to list
        allRaces.emplaceBack(current);
    }


    racefileHandler.close();
}
