#include "invoice.h"

Invoice::Invoice()
{

}
Invoice::Invoice(int id,InvoiceSender invoiceSender,int amount,QString title,QDate dateOfPayment,QDate paymentDate)
{
    this->id=id;
    this->invoiceSender=invoiceSender;
    this->amount=amount;
    this->title=title;
    this->dateOfPayment=dateOfPayment;
    this->paymentDate=paymentDate;
}

