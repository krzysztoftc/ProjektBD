#include "dao.h"

Dao::Dao()
{

}

int Dao::connect(){
   return Database::getInstance().connect();
}

void Dao::disconnect(){
    Database::getInstance().disconnect();
}

QSqlQuery Dao::execQuery(QString query){
    connect();
    QSqlQuery answer = Database::getInstance().execQuery(query);
    disconnect();
    return answer;
}




