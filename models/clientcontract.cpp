#include "clientcontract.h"

ClientContract::ClientContract()
{

}
ClientContract::ClientContract(int id,QDate startDate,QDate endDate,Client client,Project project,int price)
{
    this->id=id;
    this->startDate=startDate;
    this->endDate=endDate;
    this->client=client;
    this->project=project;
    this->price=price;

}
