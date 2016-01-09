#-------------------------------------------------
#
# Project created by QtCreator 2015-12-15T09:41:17
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QTPLUGIN += QSQLMYSQL
CONFIG += c++11
CONFIG += -O3

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projekt_bazy
TEMPLATE = app


SOURCES += main.cpp\
        loginwindow.cpp \
    repository/database.cpp \
    daos/dao.cpp \
    daos/user_login_dao.cpp \
    controlers/login_controler.cpp \
    models/user.cpp \
    windows/choose_module.cpp

HEADERS  += loginwindow.h \
    repository/database.h \
    daos/dao.h \
    daos/user_login_dao.h \
    controlers/login_controler.h \
    models/user.h \
    windows/choose_module.h

FORMS    += loginwindow.ui

INCLUDEPATH += /usr/include/mysql
