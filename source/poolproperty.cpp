#include "poolproperty.h"

PoolProperty::PoolProperty(QObject *parent) : Property(parent)
{

}

int PoolProperty::getCurrent() const
{
    return current;
}

void PoolProperty::setCurrent(int newCurrent)
{
    if(newCurrent <= max.getScore()){
        current = newCurrent;
        emit onChange();
    } //TODO: error handle otherwise?
}
