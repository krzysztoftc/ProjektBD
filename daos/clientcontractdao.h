#ifndef CLIENTCONTRACTDAO_H
#define CLIENTCONTRACTDAO_H
#include <QSqlQuery>
#include <models/clientcontract.h>
#include <daos/clientdao.h>
#include <daos/projectsddao.h>
#include "models/cantactdetails.h"
#include <daos/dao.h>
#include <QDate>
class ClientContractDAO:public Dao
{
private:
    QSqlQuery getClientContractByIdQuery(int id);
    QSqlQuery getClientContractsQuery();
    QSqlQuery getClientContractsQuery(QDate startDate,QDate endDate);
    QList<ClientContract> parse(QSqlQuery);
public:
    ClientContractDAO();
    ClientContract getClientContractById(int id);
    QList<ClientContract> getClientContracts();
    QList<ClientContract> getClientContracts(QDate startDate,QDate endDate);
};

#endif // CLIENTCONTRACTDAO_H
