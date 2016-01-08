#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

class Database
{
    QString server_addres = "86.105.49.166";
    QString user = "test";
    QString password = "123456789";


    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
public:
    Database();
    int connect();
    void disconnect();
    QSqlQuery execQuery (QString query);
};

#endif // DATABASE_H
