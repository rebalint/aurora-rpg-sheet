/*
 * Class used for properties which function as pools like HP and WP
 *
 * The max amount is type ScoreProperty, making use of base and mod, etc.
*/
#ifndef POOLPROPERTY_H
#define POOLPROPERTY_H

#include <QObject>
#include "property.h"
#include "scoreproperty.h"

class PoolProperty : public Property
{
    Q_OBJECT
public:
    explicit PoolProperty(QObject *parent = nullptr);

    int getCurrent() const;

    ScoreProperty max;

private:
    int current = 0;

signals:
    void currentChanged(int newCurrent);

public slots:
    void setCurrent(int newCurrent);
};

#endif // POOLPROPERTY_H
