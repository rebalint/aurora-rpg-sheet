/*
 * class handling the skill points that use the conversion table
 * call init after creation
 */
#ifndef SKILLPROPERTY_H
#define SKILLPROPERTY_H

#include "scoreproperty.h"
#include <QObject>

class SkillProperty : public ScoreProperty
{
public:
    explicit SkillProperty(QObject *parent = nullptr);
    void init(ScoreProperty* parentAbility);

private:
    int* baseParent;
public slots:
    void recalculate();
};

#endif // SKILLPROPERTY_H
