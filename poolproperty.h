/*
 * Class used for properties which function as pools like HP and WP
 *
 * The max amount is type ScoreProperty, making use of base and mod, etc.
*/
#ifndef POOLPROPERTY_H
#define POOLPROPERTY_H

#include "property.h"
#include "scoreproperty.h"

class PoolProperty : public Property
{
public:
    explicit PoolProperty(QObject *parent = nullptr);

    int getCurrent() const;
    void setCurrent(int newCurrent);

    ScoreProperty max;

private:
    int current = 0;
};

#endif // POOLPROPERTY_H
