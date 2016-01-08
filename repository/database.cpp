#include "database.h"

Database::Database()
{
    db.setHostName(server_addres);
    db.setDatabaseName("Ksiegowosc");
    db.setUserName(user);
    db.setPassword(password);
}

int Database::connect(){
    if (!db.open())
    {
        qDebug() << "Błąd: nie można się połączyć z bazą!";
        return 0;
    }
    else
    {
        qDebug() << "Nawiązano połączenie z bazą danych.";
        return 1;
    }
}

void Database::disconnect(){
    db.close();
}

QSqlQuery Database::execQuery(QString query){
    return db.exec(query);
}
