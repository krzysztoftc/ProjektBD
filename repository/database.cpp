#include "database.h"

Database::Database()
{
    if(!QSqlDatabase::contains(databaseName))
    {
        QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL",databaseName);
        qDebug()<<"Dodaje\n";
        db.setHostName(server_addres);
        db.setDatabaseName(databaseName);
        db.setUserName(user);
        db.setPassword(password);
    }
}
