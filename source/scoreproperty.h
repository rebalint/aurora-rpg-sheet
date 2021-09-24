/**
 * This class should be used to store simple numerical properties such as ability scores, NR, SR, etc.
*/

#ifndef SCOREPROPERTY_H
#define SCOREPROPERTY_H

#include "property.h"
#include <QObject>

class ScoreProperty : public Property
{
    Q_OBJECT
public:
    explicit ScoreProperty(QObject *parent = nullptr);

    int score = 0;                  //stores the property value, public to allow usage in mod lists
    int manualMod = 0;              //stores a sum of all manually entered values, used for character customisation

    int getScore() const;
    void addModifier(int* newModifier);

    void setBase(int newBase);

    bool isCalculated = false;  //set to true if using baseCalculation
    int (*baseCalculation)(ScoreProperty * arg1, ScoreProperty * arg2);    //OVERRIDE THIS EITHER WITH ACTUAL BASE CALCULATION IF APPLICABLE

    ScoreProperty * baseArg1;   //stores properties used in baseCalculation
    ScoreProperty * baseArg2;

    int getBase() const;

protected:
    int base = 0;   //stores the base score which is usually rolled
    QVector<int*> modifiers;    //pointer array to any modifiers this property might have

public slots:
    virtual void recalculate(); //connect to when used modifiers change
    void baseChange(int newBase);
    void modChange(int newMod);

signals:
    void scoreChange(int newValue);
};

#endif // SCOREPROPERTY_H
