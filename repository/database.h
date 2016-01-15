#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QDebug>

class Database
{
    QString server_addres = "86.105.49.166";
    QString user = "test";
    QString password = "123456789";
    QString databaseName="Ksiegowosc";


public:
    Database();
};


#endif // DATABASE_H
