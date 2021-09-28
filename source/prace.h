/*
 * class representing a player race
 */
#ifndef PRACE_H
#define PRACE_H

#include <QObject>
#include "property.h"

class PRace : public Property
{
    Q_OBJECT
public:
    explicit PRace(QObject *parent = nullptr);

    QString subraceof;
    QVector<Property> textProps;    //store all text-only properties

};

#endif // PRACE_H
