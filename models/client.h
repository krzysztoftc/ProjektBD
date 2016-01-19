#ifndef CLIENT_H
#define CLIENT_H
#include <QtGlobal>
#include <models/cantactdetails.h>
#include <QString>
class Client
{
public:

    qlonglong NIP;
    QString name;
    Client();
    CantactDetails contactDetails;
    Client(qlonglong NIP,QString name,CantactDetails contactDetails);

};

#endif // CLIENT_H
