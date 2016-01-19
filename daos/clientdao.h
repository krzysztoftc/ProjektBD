#ifndef CLIENTDAO_H
#define CLIENTDAO_H
#include <QSqlQuery>
#include <models/client.h>
#include <daos/contactdetailsdao.h>
#include <daos/dao.h>
class ClientDAO:public Dao
{
private:
    QSqlQuery getClientByIdQuery(qlonglong id);
    QSqlQuery getClientsQuery();
public:
    ClientDAO();
    Client getClientById(qlonglong id);
    QList<Client> getClients();
};

#endif // CLIENTDAO_H
