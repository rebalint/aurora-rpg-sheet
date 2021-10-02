/*
 * Class used to handle race properties that have a numerical modifier of some kind.
 *
 * modType: [ONEPROP/TWOPROP]|[SET/MOD]
 */

#ifndef RACEMODIFIER_H
#define RACEMODIFIER_H

#include "property.h"
#include <QObject>

class RaceModifier : public Property
{
    Q_OBJECT
public:
    explicit RaceModifier(QObject *parent = nullptr);

    void generateDescription();    //TODO: implement this to generate standard text description

    QString modType;

    QString prop1Name;
    QString prop2Name;

    int modifier;
};

#endif // RACEMODIFIER_H
