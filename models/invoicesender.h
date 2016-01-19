#ifndef INVOICESENDER_H
#define INVOICESENDER_H
#include <QString>
#include <models/cantactdetails.h>
class InvoiceSender
{
public:
    int id;
    QString name;
    QString accountNumber;
    CantactDetails contactDetails;
    InvoiceSender();
    InvoiceSender(int,QString,QString,CantactDetails);

};

#endif // INVOICESENDER_H
