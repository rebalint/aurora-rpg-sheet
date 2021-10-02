/*
 * Test suite for ScoreProperty
 * TODO: create a testing fixture
 */
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <QVector>
#include <QString>

#include "../source/scoreproperty.h"

using namespace testing;

TEST(ScorePropertyTest, manualModTest)
{
    //test basic manualMod functionality
    QVector<int> baseValue{10, -3,  0};
    QVector<int> manualMod{ 2,  5, -2};

    QVector<std::string> testName{"normal", "negative base", "negative mod"};

    for(int i = 0; i < baseValue.size(); i++){
        ScoreProperty prop;

        prop.baseChange(baseValue.at(i));
        prop.modChange(manualMod.at(i));

        EXPECT_EQ(prop.score, baseValue.at(i) + manualMod.at(i)) << "test case name: " << testName.at(i);
    }
}

TEST(ScorePropertyTest, referenceModTest){
    //TODO: test usage of one or more mods added with addModifier(int*mod)
    //QVector<int> baseValue;
    EXPECT_EQ(1, 1);
}

