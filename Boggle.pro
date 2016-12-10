#-------------------------------------------------
#
# Project created by QtCreator 2016-12-09T15:11:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Boggle
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    Boggle.cpp \
    Trie.cpp

HEADERS  += widget.h \
    Boggle.h \
    Trie.h

FORMS    += widget.ui

@CONFIG += debug_and_release@