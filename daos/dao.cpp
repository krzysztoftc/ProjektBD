#include "dao.h"

Dao::Dao()
{

}

int Dao::connect(){
    database.connect();
}

void Dao::disconnect(){
    database.disconnect();
}



