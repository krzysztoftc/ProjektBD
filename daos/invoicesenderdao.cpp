#include "invoicesenderdao.h"

InvoiceSenderDao::InvoiceSenderDao()
{

}
QSqlQuery InvoiceSenderDao::getInvoiceSenderByIdQuery(int id)
{
    QString q="SELECT idnadawcaFaktury,Nazwa,NumerRachunku,iddaneKontaktowe,adresLinia1,adresLinia2,telefon,email FROM nadawcaFaktury JOIN daneKontaktowe ON nadawcaFaktury.daneKontaktowe=daneKontaktowe.iddaneKontaktowe Where idnadawcaFaktury="+id;
    QSqlQuery answer = Dao::execQuery(q);
    return answer;
}

QSqlQuery InvoiceSenderDao::getInvoiceSenderQuery()
{
    QString q = "SELECT idnadawcaFaktury,Nazwa,NumerRachunku,iddaneKontaktowe,adresLinia1,adresLinia2,telefon,email FROM nadawcaFaktury JOIN daneKontaktowe ON nadawcaFaktury.daneKontaktowe=daneKontaktowe.iddaneKontaktowe";
    QSqlQuery answer = Dao::execQuery(q);
    return answer;
}
QList<InvoiceSender> InvoiceSenderDao::getInvoiceSender()
{
    QList<InvoiceSender> list;
    QSqlQuery a=getInvoiceSenderQuery();
    InvoiceSender s;
    while(a.next())
    {
         s.id=a.value(0).toInt();
         s.name=a.value(1).toString();
         s.accountNumber=a.value(2).toString();
         CantactDetails details;
         details.id=a.value(3).toInt();
         details.addressLine1=a.value(4).toString();
         details.addressLine2=a.value(5).toString();
         details.phoneNumber=a.value(6).toString();
         details.email=a.value(7).toString();
         s.contactDetails=details;
         list.push_back(s);
     }
    return list;


}

InvoiceSender InvoiceSenderDao::getInvoiceSenderById(int id)
{
    QSqlQuery a=getInvoiceSenderByIdQuery(id);
    InvoiceSender s;
    if(a.first())
    {
         s.id=a.value(0).toInt();
         s.name=a.value(1).toString();
         s.accountNumber=a.value(2).toString();
         CantactDetails details;
         details.id=a.value(3).toInt();
         details.addressLine1=a.value(4).toString();
         details.addressLine2=a.value(5).toString();
         details.phoneNumber=a.value(6).toString();
         details.email=a.value(7).toString();
         s.contactDetails=details;
     }
   return s;
}
