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

    QString subraceof;
    QMap<QString, bool> classRestrictions;  //syntax: "classname": true means race has to be that class, false means it cannot be

    QVector<Property *> textProps;    //store all text-only properties

    QVector<RaceModifier *> modProps;
};

#endif // PRACE_H
