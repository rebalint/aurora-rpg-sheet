/*
 * Base class for all properties used in the program.
*/

#ifndef PROPERTY_H
#define PROPERTY_H

#include <QObject>
#include <QDebug>

class Property : public QObject
{
    Q_OBJECT
public:
    explicit Property(QObject *parent = nullptr);
    void setDescription(const QString &newDescription); //setter to make sure onChange is emitted if necessary
    QString name = "property";
    QString description;    //stores a description of the property

signals:
    void onChange();    //generic update signal for backend use only, triggers recalculation
};

#endif // PROPERTY_H
