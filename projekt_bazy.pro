#-------------------------------------------------
#
# Project created by QtCreator 2015-12-15T09:41:17
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QTPLUGIN += QSQLMYSQL

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projekt_bazy
TEMPLATE = app


SOURCES += main.cpp\
        loginwindow.cpp \
    repository/database.cpp \
    daos/dao.cpp \
    daos/user_login_dao.cpp

HEADERS  += loginwindow.h \
    repository/database.h \
    daos/dao.h \
    daos/user_login_dao.h

FORMS    += loginwindow.ui

INCLUDEPATH += /usr/include/mysql
