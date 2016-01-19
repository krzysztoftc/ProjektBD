#ifndef DAO_H
#define DAO_H

#include "../repository/database.h"
#include <QList>
class Dao
{
    QSqlDatabase database;
public:
    Dao();
    int connect();
    void disconnect();
    QSqlQuery execQuery(QString query);

};

#endif // DAO_H
