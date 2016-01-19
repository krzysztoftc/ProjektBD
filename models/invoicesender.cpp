#include "invoicesender.h"

InvoiceSender::InvoiceSender()
{

}
InvoiceSender::InvoiceSender(int id,QString name, QString accountNumber,CantactDetails contactDetails)
{
    this->id=id;
    this->name=name;
    this->accountNumber=accountNumber;
    this->contactDetails=contactDetails;
}
