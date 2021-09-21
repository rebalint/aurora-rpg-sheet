#include "property.h"

Property::Property(QObject *parent) : QObject(parent)
{

}

const QString &Property::getDescription() const
{
    return description;
}

void Property::setDescription(const QString &newDescription)
{
    description = newDescription;
    emit onChange();
}
