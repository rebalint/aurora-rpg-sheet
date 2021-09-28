#include "property.h"

Property::Property(QObject *parent) : QObject(parent)
{

}

void Property::setDescription(const QString &newDescription)
{
    description = newDescription;
    emit onChange();
}
