#include "character.h"

Character::Character(QObject *parent) : QObject(parent)
{
    //set up names
    //yes this is awful, and? it's still the most viable method
    body.name = "Body";
    mind.name = "Mind";
    soul.name = "Soul";

    hp.max.name = "HP";
    wp.max.name = "WP";

    nr.name  = "NR";
    sr.name = "SR";
    speed.name = "Speed";

    strength.name = "Strength";
    nimble.name = "Nimble";
    perception.name = "Perception";
    diplomacy.name = "Diplomacy";
    magic.name = "Magic";
    connection.name = "Connection";

    //setup for baseCalcs, connections
    hp.max.isCalculated = true;
    hp.max.baseArg1 = & body;
    hp.max.baseCalculation = & hpBase;
    connect(&body, &Property::onChange, &hp.max, &ScoreProperty::recalculate);

    wp.max.isCalculated = true;
    wp.max.baseArg1 = & soul;
    wp.max.baseCalculation = & wpBase;
    connect(&soul, &Property::onChange, &wp.max, &ScoreProperty::recalculate);

    nr.isCalculated = true;
    nr.baseArg1 = & mind;
    nr.baseArg2 = & body;
    nr.baseCalculation = & nrBase;
    connect(&mind, &Property::onChange, &nr, &ScoreProperty::recalculate);
    connect(&body, &Property::onChange, &nr, &ScoreProperty::recalculate);

    sr.isCalculated = true;
    sr.baseArg1 = & soul;
    sr.baseCalculation = srBase;
    connect(&soul, &Property::onChange, &sr, &ScoreProperty::recalculate);

    //same setup for skills
    strength.baseArg1= & body;
    nimble.baseArg1 = & body;
    perception.baseArg1 = & mind;
    diplomacy.baseArg1 = & mind;
    magic.baseArg1 = & soul;
    connection.baseArg1 = & soul;

    strength.baseCalculation = & skillBase;
    nimble.baseCalculation = & skillBase;
    perception.baseCalculation = & skillBase;
    diplomacy.baseCalculation = & skillBase;
    magic.baseCalculation = & skillBase;
    connection.baseCalculation = & skillBase;

    connect(&body, &Property::onChange, &strength, &ScoreProperty::recalculate);
    connect(&body, &Property::onChange, &nimble, &ScoreProperty::recalculate);
    connect(&mind, &Property::onChange, &perception, &ScoreProperty::recalculate);
    connect(&mind, &Property::onChange, &diplomacy, &ScoreProperty::recalculate);
    connect(&soul, &Property::onChange, &magic, &ScoreProperty::recalculate);
    connect(&soul, &Property::onChange, &connection, &ScoreProperty::recalculate);

    strength.isCalculated = true;
    nimble.isCalculated = true;
    perception.isCalculated = true;
    diplomacy.isCalculated = true;
    magic.isCalculated = true;
    connection.isCalculated = true;
}

void Character::roll(){
    //TODO: replace with actual rolls
    body.baseChange(14);
    mind.baseChange(18);
    soul.baseChange(6);
}

void Character::setRace(PRace * newRace){
    race = newRace;

    //connect numerical mods that don't have any options we want the player to set
    QVector<RaceModifier *> oneprop = race->getOneProp();

    for(int i = 0; i < oneprop.size(); i++){
        //TODO figure this out
        //yes this isn't very scalable but it should be fine

    }
}

//baseCalc functions
int Character::hpBase(ScoreProperty * arg1, ScoreProperty * arg2){  //arg1: body
        return(arg1->score * 2);
}
int Character::wpBase(ScoreProperty * arg1, ScoreProperty * arg2){  //arg1: soul
    return(arg1->score * 4);
}
int Character::nrBase(ScoreProperty * arg1, ScoreProperty * arg2){  //arg1: mind, arg2: body
    if(arg1->score < arg2->score){
        return(arg1->score);
    } else{
        return(arg2->score);
    }
}
int Character::srBase(ScoreProperty * arg1, ScoreProperty * arg2){  //arg1: soul
    if(arg1->score != 0){
        return(floor(arg1->score / 2));
    } else {
        return(0);
    }
}

int Character::skillBase(ScoreProperty *arg1, ScoreProperty *arg2){
    //table is implemented here
    if(arg1->score <= 10){
        return(-1);
    } else if(arg1->score <= 15){
        return(0);
    } else if (arg1->score <= 20) {
        return(1);
    } else{
        return(2);
    }
}
