#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "../source/scoreproperty.h"

class ScorePropertyTest : public QObject
{
    Q_OBJECT

public:
    ScorePropertyTest();
    ~ScorePropertyTest();

private slots:
    void initTestCase();
    void cleanupTestCase();

    void manualMod();
    void manualMod_data();

    void referenceMod();
    void referenceMod_data();

    void manualReferenceMod();
    void manualReferenceMod_data(); //reuse slightly changed referenceMod_data

};

ScorePropertyTest::ScorePropertyTest()
{

}

ScorePropertyTest::~ScorePropertyTest()
{

}

void ScorePropertyTest::initTestCase()
{

}

void ScorePropertyTest::cleanupTestCase()
{

}

void ScorePropertyTest::manualMod_data(){
    QTest::addColumn<int>("baseValue");
    QTest::addColumn<int>("manualMod");
    QTest::addColumn<int>("expected");

    QTest::newRow("basic") << 15 << 4 << 19 ;
    QTest::newRow("negative base") << -3 << 10 << 7;
    QTest::newRow("negative mod") << 5 << -2 << 3;
    QTest::newRow("both negative") << -5 << -2 << -7;
    QTest::newRow("zero as result") << 10 << -10 << 0;
    QTest::newRow("zero base") << 0 << 2 << 2;
    QTest::newRow("zero mod") << 14 << 0 << 14;
}

void ScorePropertyTest::manualMod()
{
    QFETCH(int, baseValue);
    QFETCH(int, manualMod);
    QFETCH(int, expected);

    ScoreProperty testprop;
    testprop.baseChange(baseValue);
    testprop.modChange(manualMod);

    QCOMPARE(testprop.score, expected);
}

void ScorePropertyTest::referenceMod_data(){
    QTest::addColumn<int>("baseValue");
    QTest::addColumn<int>("ref1");
    QTest::addColumn<bool>("isref2");
    QTest::addColumn<int>("ref2");
    QTest::addColumn<bool>("isref3");
    QTest::addColumn<int>("ref3");
    QTest::addColumn<int>("expected");

    QTest::newRow("1 ref, all pos") << 10 << 2 << false << 0 << false << 0 << 12;
    QTest::newRow("1 ref, negative") << 10 << -2 << false << 0 << false << 0 << 8;
    QTest::newRow("2 refs, all pos") << 10 << 1 << true << 3 << false << 0 << 14;
    QTest::newRow("2 refs, one negative") << 15 << 4 << true << -9 << false << 0 << 10;
    QTest::newRow("3 refs, all pos") << 10 << 2 << true << 3 << true << 1 << 16;
    QTest::newRow("3 refs, sum to zero") << 12 << 2 << true << -7 << true << -7 << 0;
    QTest::newRow("3 refs, all negative") << -1 << -2 << true << -2 << true << -5 << -10;

}

void ScorePropertyTest::referenceMod(){
    QFETCH(int, baseValue);
    QFETCH(int, ref1);
    QFETCH(bool, isref2);
    QFETCH(int, ref2);
    QFETCH(bool, isref3);
    QFETCH(int, ref3);
    QFETCH(int, expected);

    ScoreProperty testprop;
    testprop.baseChange(baseValue);

    testprop.addModifier(& ref1);
    if(isref2){
        testprop.addModifier(& ref2);
    }
    if(isref3){
        testprop.addModifier(& ref3);
    }
    testprop.recalculate();

    QCOMPARE(testprop.score, expected);
}

void ScorePropertyTest::manualReferenceMod_data(){
    QTest::addColumn<int>("baseValue");
    QTest::addColumn<int>("manualMod");
    QTest::addColumn<int>("ref1");
    QTest::addColumn<bool>("isref2");
    QTest::addColumn<int>("ref2");
    QTest::addColumn<int>("expected");

    QTest::newRow("2 refs, all pos") << 10 << 1 << 3 << false << 0 << 14;
    QTest::newRow("2 refs, one negative") << 15 << 4 << -9 << false << 0 << 10;
    QTest::newRow("3 refs, all pos") << 10 << 2 << 3 << true << 1 << 16;
    QTest::newRow("3 refs, sum to zero") << 12 << 2 << -7 << true << -7 << 0;
    QTest::newRow("3 refs, all negative") << -1 << -2 << -2 << true << -5 << -10;

}

void ScorePropertyTest::manualReferenceMod(){
    QFETCH(int, baseValue);
    QFETCH(int, manualMod);
    QFETCH(int, ref1);
    QFETCH(bool, isref2);
    QFETCH(int, ref2);
    QFETCH(int, expected);

    ScoreProperty testprop;
    testprop.baseChange(baseValue);
    testprop.modChange(manualMod);

    testprop.addModifier(& ref1);

    if(isref2){
        testprop.addModifier(& ref2);
    }

    testprop.recalculate();

    QCOMPARE(testprop.score, expected);
}

QTEST_MAIN(ScorePropertyTest)

#include "tst_scoreproperty.moc"
