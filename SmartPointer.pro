QT += core
QT -= gui

CONFIG += c++11

TARGET = SmartPointer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    shared_ptr.h \
    scoped_ptr.h
