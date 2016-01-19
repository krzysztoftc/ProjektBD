#include "client.h"

Client::Client()
{

}
Client::Client(qlonglong NIP,QString name,CantactDetails contactDetails)
{
    this->NIP=NIP;
    this->name=name;
    this->contactDetails=contactDetails;
}

