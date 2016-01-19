#include "clientdao.h"

ClientDAO::ClientDAO()
{

}

QSqlQuery ClientDAO::getClientByIdQuery(qlonglong id)
{
    QString q = "SELECT * FROM klienci WHERE nip="+id;
    QSqlQuery answer = Dao::execQuery(q);
    return answer;
}

QSqlQuery ClientDAO::getClientsQuery()
{
    QString q = "SELECT * FROM klienci";
    QSqlQuery answer = Dao::execQuery(q);
    return answer;
}

Client ClientDAO::getClientById(qlonglong id)
{
    QSqlQuery a = getClientByIdQuery(id);

    Client c;
    c.NIP=a.value(0).toLongLong();
    c.name=a.value(1).toString();

    ContactDetailsDAO cdDAO;
    c.contactDetails=cdDAO.getContactDetailsById(a.value(2).toInt());
    return c;
}

QList<Client> ClientDAO::getClients()
{
    QList<Client> list;
    return list;
}
