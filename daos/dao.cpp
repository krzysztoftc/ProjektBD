#include "dao.h"

Dao::Dao()
{

}

int Dao::connect(){
   return database.connect();
}

void Dao::disconnect(){
    database.disconnect();
}

QSqlQuery Dao::execQuery(QString query){
    connect();
    QSqlQuery answer = database.execQuery(query);
    disconnect();
    return answer;
}



