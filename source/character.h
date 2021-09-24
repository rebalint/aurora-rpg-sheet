/*
 * Class used to store a character.
 *
 * Heavily WIP.
 * TODO:
 *  - implement loading and saving
 *  - display everything
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QDebug>
#include "poolproperty.h"
#include "scoreproperty.h"
//#include "skillproperty.h"

class Character : private QObject
{
    Q_OBJECT

public:
    explicit Character(QObject *parent = nullptr);

    void roll();    //rolls a random character

    //basic hardcoded properties
    ScoreProperty body;
    ScoreProperty mind;
    ScoreProperty soul;

    PoolProperty hp;
    PoolProperty wp;

    ScoreProperty nr;
    ScoreProperty sr;
    ScoreProperty speed;

    ScoreProperty strength;
    ScoreProperty nimble;
    ScoreProperty perception;
    ScoreProperty diplomacy;
    ScoreProperty magic;
    ScoreProperty connection;

    //Funtions for calculating certain properties
    static int hpBase(ScoreProperty * arg1, ScoreProperty * arg2);
    static int wpBase(ScoreProperty * arg1, ScoreProperty * arg2);
    static int nrBase(ScoreProperty * arg1, ScoreProperty * arg2);
    static int srBase(ScoreProperty * arg1, ScoreProperty * arg2);
    static int skillBase(ScoreProperty * arg1, ScoreProperty * arg2);


signals:

};

#endif // CHARACTER_H
