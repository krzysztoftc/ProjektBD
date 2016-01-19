#ifndef INVOICE_H
#define INVOICE_H
#include <models/invoicesender.h>
#include <QString>
#include <QDate>

class Invoice
{
public:
    int id;
    InvoiceSender invoiceSender;
    int amount;
    QString title;
    QDate dateOfPayment;
    QDate paymentDate;
    Invoice();
    Invoice(int,InvoiceSender,int,QString,QDate,QDate);
};

#endif // INVOICE_H
