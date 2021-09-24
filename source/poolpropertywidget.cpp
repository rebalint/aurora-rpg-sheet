#include "poolpropertywidget.h"
#include "ui_poolpropertywidget.h"

PoolPropertyWidget::PoolPropertyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PoolPropertyWidget)
{
    ui->setupUi(this);
}

PoolPropertyWidget::~PoolPropertyWidget()
{
    delete ui;
}
void PoolPropertyWidget::poolConnect(PoolProperty * poolProp){
    ui->maxBox->scoreConnect(& poolProp->max);

    ui->currentDisp->setValue(poolProp->getCurrent());
    ui->currentDisp->setMaximum(poolProp->max.score);

    //connect current changes
    connect(this, & PoolPropertyWidget::manualCurrentChange, poolProp, & PoolProperty::setCurrent);

    //connect backend to ui
    //connect(poolProp, & PoolProperty::currentChanged, this->ui->currentDisp, & QSpinBox::setValue);   //TODO uncomment and fix this if it's needed :)
    //connect(poolProp, & PoolProperty::maxChanged, this, & PoolPropertyWidget::maxChange);
    connect(& poolProp->max, & ScoreProperty::scoreChange, this, & PoolPropertyWidget::maxChange);
}

void PoolPropertyWidget::maxChange(int newMax){
    ui->currentDisp->setMaximum(newMax);
}
