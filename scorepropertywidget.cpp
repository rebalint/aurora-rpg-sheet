#include "scorepropertywidget.h"
#include "ui_scorepropertywidget.h"

ScorePropertyWidget::ScorePropertyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScorePropertyWidget)
{
    ui->setupUi(this);

}

ScorePropertyWidget::~ScorePropertyWidget()
{
    delete ui;
}

void ScorePropertyWidget::refresh(ScoreProperty * scoreProp)
{
    //add to this for additional features

    ui->label->setText(scoreProp->name);
    ui->scoreDisp->setValue(scoreProp->score);
    ui->baseSelector->setValue(scoreProp->getBase());
    ui->manualModSelector->setValue(scoreProp->manualMod);
    //hide base select if the prop is calculated
    if(scoreProp->isCalculated){
        ui->baseSelector->hide();
        ui->baseLabel->hide();
    }
}

void ScorePropertyWidget::changeScore(int newScore){
    ui->scoreDisp->setValue(newScore);
}

void ScorePropertyWidget::scoreConnect(ScoreProperty *scoreProp){
    //UI->SCOREPROP connections
    connect(this, & ScorePropertyWidget::manualBaseChange, scoreProp, & ScoreProperty::baseChange);
    connect(this, &  ScorePropertyWidget::manualModChange, scoreProp, & ScoreProperty::modChange);

    //SCOREPROP->UI connections
    connect(scoreProp, & ScoreProperty::scoreChange, this, & ScorePropertyWidget::changeScore);

    refresh(scoreProp);
}

//connect UI events to signals for external use
void ScorePropertyWidget::on_manualModSelector_valueChanged(int newMod)
{
    emit manualModChange(newMod);
}
void ScorePropertyWidget::on_baseSelector_valueChanged(int newBase)
{
    emit manualBaseChange(newBase);
}


