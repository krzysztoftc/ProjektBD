#include "dao.h"

Dao::Dao()
{
   database=QSqlDatabase::database("Ksiegowosc");
}

int Dao::connect(){
    if (!database.open())
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

void Dao::disconnect(){
    database.close();
}

QSqlQuery Dao::execQuery(QString query){
    connect();
    QSqlQuery answer = database.exec(query);
    disconnect();
    return answer;
}




