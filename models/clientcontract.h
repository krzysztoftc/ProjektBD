#ifndef CLIENTCONTRACT_H
#define CLIENTCONTRACT_H
#include <QDate>
#include "client.h"
#include "project.h"
class ClientContract
{
public:

    int id;
    QDate startDate;
    QDate endDate;
    Client client;
    Project project;
    int price;
    ClientContract();
    ClientContract(int,QDate,QDate,Client,Project,int);
};

#endif // CLIENTCONTRACT_H
