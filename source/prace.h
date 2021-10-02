/*
 * class representing a player race
 */
#ifndef PRACE_H
#define PRACE_H

#include <QObject>
#include "property.h"
#include "racemodifier.h"

class PRace : public Property
{
    Q_OBJECT
public:
    explicit PRace(QObject *parent = nullptr);

    void setup();

    QString subraceof;
    QMap<QString, bool> classRestrictions;  //syntax: "classname": true means race has to be that class, false means it cannot be

    QVector<Property *> textProps;    //store all text-only properties

    QVector<RaceModifier *> modProps;

    QVector<RaceModifier *> getOneProp();   //returns a qvector of modprops that can be automatically applied
};

#endif // PRACE_H
