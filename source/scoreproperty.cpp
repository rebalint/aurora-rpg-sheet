#include "scoreproperty.h"

ScoreProperty::ScoreProperty(QObject *parent) : Property(parent)
{

}

int ScoreProperty::getScore() const
{
    return score;
}

void ScoreProperty::addModifier(int *newModifier){
    modifiers.push_back(newModifier);
    recalculate();
}

int ScoreProperty::getBase() const
{
    return base;
}

void ScoreProperty::baseChange(int newBase){
    base = newBase;
    recalculate();
}

void ScoreProperty::modChange(int newMod){
    manualMod = newMod;
    recalculate();
}

void ScoreProperty::recalculate(){
    if(isCalculated){
        base = baseCalculation(baseArg1, baseArg2);
    }
    int currentScore = base + manualMod;
    if(modifiers.size()>0){
        for(int i=0; i<modifiers.size(); i++){
            //qDebug() << modifiers.at(i);
            currentScore += *modifiers.at(i);
        }
    }
    score = currentScore;
    emit onChange();
    emit scoreChange(score);
}

