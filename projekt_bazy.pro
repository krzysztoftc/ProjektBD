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
        windows/loginwindow.cpp \
    repository/database.cpp \
    daos/dao.cpp \
    daos/user_login_dao.cpp \
    controlers/login_controler.cpp \
    models/user.cpp \
    windows/choose_window.cpp \
    windows/acountant_module.cpp \
    windows/dialog_raport.cpp \
    windows/project_manager_module.cpp \
    models/person.cpp \
    models/test.cpp \
    windows/projectlist.cpp \
    daos/projectsddao.cpp \
    models/project.cpp \
    windows/dialognewproject.cpp \
    models/employee.cpp \
    models/clientcontract.cpp \
    models/client.cpp \
    models/cantactdetails.cpp \
    models/invoicesender.cpp \
    models/invoice.cpp \
    daos/clientcontractdao.cpp \
    daos/clientdao.cpp \
    daos/contactdetailsdao.cpp \
    daos/invoicesenderdao.cpp \
    daos/invoicedao.cpp


HEADERS  += windows/loginwindow.h \
    repository/database.h \
    daos/dao.h \
    daos/user_login_dao.h \
    controlers/login_controler.h \
    models/user.h \
    windows/choose_window.h \
    windows/acountant_module.h \
    windows/dialog_raport.h \
    windows/project_manager_module.h \
    models/person.h \
    models/test.h \
    windows/projectlist.h \
    daos/projectsddao.h \
    models/project.h \
    windows/dialognewproject.h \
    models/employee.h \
    models/clientcontract.h \
    models/client.h \
    models/cantactdetails.h \
    models/invoicesender.h \
    models/invoice.h \
    daos/clientcontractdao.h \
    daos/clientdao.h \
    daos/contactdetailsdao.h \
    daos/invoicesenderdao.h \
    daos/invoicedao.h

FORMS    += windows/loginwindow.ui \
    windows/choose_window.ui \
    windows/acountant_module.ui \
    windows/dialog_raport.ui \
    windows/project_manager_module.ui \
    windows/projectlist.ui \
    windows/dialognewproject.ui


INCLUDEPATH += /usr/include/mysql

RESOURCES += \
    images.qrc
