#include "character.h"

Character::Character(QObject *parent) : QObject(parent)
{
    //set up names
    //yes this is awful, and? it's still the most viable method
    body.name = "Body";
    mind.name = "Mind";
    soul.name = "Soul";

    hp.name = "hp";
    wp.name = "wp";

    nr.name  = "nr";
    sr.name = "sr";
    speed.name = "speed";

    strenght.name = "strenght";
    nimble.name = "nimble";
    perception.name = "perception";
    diplomacy.name = "diplomacy";
    magic.name = "magic";
    connection.name = "connection";

    //setup for skills
    strenght.init(& body);
    nimble.init(& body);
    perception.init(& mind);
    diplomacy.init(& mind);
    magic.init(& soul);
    connection.init(& soul);

    //setup for baseCalcs, connections
    hp.max.baseArg1 = & body;
    hp.max.baseCalculation = & hpBase;
    connect(&body, &Property::onChange, &hp.max, &ScoreProperty::recalculate);

    wp.max.baseArg1 = & soul;
    wp.max.baseCalculation = & wpBase;
    connect(&soul, &Property::onChange, &wp.max, &ScoreProperty::recalculate);


    nr.baseArg1 = & mind;
    nr.baseArg2 = & body;
    nr.baseCalculation = & nrBase;
    connect(&mind, &Property::onChange, &nr, &ScoreProperty::recalculate);
    connect(&body, &Property::onChange, &nr, &ScoreProperty::recalculate);


    sr.baseArg1 = & soul;
    sr.baseCalculation = srBase;
    connect(&soul, &Property::onChange, &sr, &ScoreProperty::recalculate);
}

void Character::roll(){
    //TODO: replace with actual rolls
    body.setBase(14);
    mind.setBase(18);
    soul.setBase(6);
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
