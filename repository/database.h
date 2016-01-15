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


    QSqlDatabase db;// = QSqlDatabase::addDatabase("QMYSQL");;

    Database(){
        qDebug()<<"Konstruktor bazy";

    }    //for singleton

public:

//    S(S const&)               = delete;
//    void operator=(S const&)  = delete;

    Database(Database const&) = delete;         //for singleton
    void operator=(Database const&)  = delete;  //for singleton

    static Database& getInstance()
    {
     static Database instance; // Guaranteed to be destroyed.
                                     // Instantiated on first use.
     return instance;
    }

    int connect();
    void disconnect();
    QSqlQuery execQuery (QString query);
};


#endif // DATABASE_H
