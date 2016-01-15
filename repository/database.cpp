#include "database.h"

//Database::Database()
//{
//    qDebug()<<"Create database";
//    db.setHostName(server_addres);
//    db.setDatabaseName("Ksiegowosc");
//    db.setUserName(user);
//    db.setPassword(password);
//  //    qDebug() << "here1\n";
////    db.open();
////    qDebug() << "here2\n";
////    db.close();
////    qDebug() << "here3\n";
//}

int Database::connect(){
    qDebug() << "here4\n";
    db = QSqlDatabase::addDatabase("QMYSQL");
    if (!db.open())
    {
        qDebug() << "Blad: nie mozna sie polaczyć z baza!";
        return 0;
    }
    else
    {
        qDebug() << "Nawiazano polaczenie z baza danych.";
        return 1;
    }
}

void Database::disconnect(){
    db.close();
    QSqlDatabase::removeDatabase("QMYSQL");
}

QSqlQuery Database::execQuery(QString query){
    return db.exec(query);
}

