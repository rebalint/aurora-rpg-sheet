/*
 * UI element class used to display ScoreProperty objects.
 */

#ifndef SCOREPROPERTYWIDGET_H
#define SCOREPROPERTYWIDGET_H

#include <QWidget>
#include "scoreproperty.h"

namespace Ui {
class ScorePropertyWidget;
}

class ScorePropertyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ScorePropertyWidget(QWidget *parent = nullptr);
    ~ScorePropertyWidget();
    void scoreConnect(ScoreProperty * scoreProp);   //event connection

private:
    Ui::ScorePropertyWidget *ui;

signals:
    int manualModChange(int newMod);
    int manualBaseChange(int newBase);

public slots:
    void refresh(ScoreProperty * scoreProp);    //syncs everything
    void changeScore(int newScore);

private slots:
    void on_manualModSelector_valueChanged(int arg1);
    void on_baseSelector_valueChanged(int arg1);
};

#endif // SCOREPROPERTYWIDGET_H
