include(gtest_dependency.pri)

QT += core widgets

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread

SOURCES += \
        main.cpp         \
        tst_scoreproperty.cpp \
        ../source/property.cpp \
        ../source/scoreproperty.cpp \
        ../source/poolproperty.cpp

HEADERS += \
    ../source/property.h \
    ../source/scoreproperty.h \
    ../source/poolproperty.h
