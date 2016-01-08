#ifndef DAO_H
#define DAO_H

#include "../repository/database.h"

class Dao
{
    Database database;
public:
    Dao();
    int connect();
    void disconnect();
};

#endif // DAO_H
