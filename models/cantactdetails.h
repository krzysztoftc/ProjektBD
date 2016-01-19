#ifndef CANTACTDETAILS_H
#define CANTACTDETAILS_H
#include <QString>

class CantactDetails
{
public:
    int id;
    QString addressLine1;
    QString addressLine2;
    QString phoneNumber;
    QString email;
    CantactDetails();
   // ContactDetails(int id,QString addressLine1,QString addressLine2,QString phoneNumber,QString email);
};

#endif // CANTACTDETAILS_H
