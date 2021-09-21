#include "skillproperty.h"

SkillProperty::SkillProperty(QObject *parent) : ScoreProperty(parent)
{

}

void SkillProperty::init(ScoreProperty* parentAbility){
    baseParent = &parentAbility->score;

    connect(parentAbility, &Property::onChange, this, &SkillProperty::recalculate);

    recalculate();
}

void SkillProperty::recalculate(){
    //table is implemented here
    if(* baseParent <= 10){
        base = -1;
    } else if(* baseParent <= 15){
        base = 0;
    } else if (* baseParent <= 20) {
        base = 1;
    } else{
        base = 2;
    }

    int currentScore = base;
    if(modifiers.size()>0){
        for(int i=0; i>=modifiers.size(); i++){
            currentScore += *modifiers.at(i);
        }
    }
    score = currentScore;
    emit onChange();
}
