#include "prace.h"

PRace::PRace(QObject *parent) : Property(parent)
{

}

void PRace::setup(){
    for(int i = 0; i < modProps.size(); i++){
        modProps.at(i)->generateDescription();
    }
}

QVector<RaceModifier *> PRace::getOneProp(){
    QVector<RaceModifier *> ret;

    for(int i = 0; i < modProps.size(); i++){
        if(modProps.at(i)->modType.contains("ONEPROP") &&
                !modProps.at(i)->prop1Name.contains("any")){
            ret.push_back(modProps.at(i));
        }
    }
    return ret;
}
