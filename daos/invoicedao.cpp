#include "invoicedao.h"

invoiceDAO::invoiceDAO()
{

}
QSqlQuery invoiceDAO::getInvoiceByIdQuery(int id)
{
    QString q = "SELECT * FROM faktury WHERE idFaktury="+id;
    QSqlQuery answer = Dao::execQuery(q);

    qDebug()<<"answer: "+answer.executedQuery();
    return answer;
}

QSqlQuery invoiceDAO::getInvoicesQuery()

{
    QString q="SELECT idFaktury, kwota, tytulOplaty, terminPlatnosci, dataOplacenia, nadawcaFaktury.idnadawcaFaktury, Nazwa, NumerRachunku, iddaneKontaktowe, adresLinia1, adresLinia2, telefon, email FROM faktury JOIN nadawcaFaktury ON faktury.idNadawcaFaktury = nadawcaFaktury.idnadawcaFaktury JOIN daneKontaktowe ON daneKontaktowe.iddaneKontaktowe = nadawcaFaktury.daneKontaktowe";
    QSqlQuery answer=Dao::execQuery(q);
    return answer;

}
QSqlQuery invoiceDAO::getInvoicesQuery(QDate startDate,QDate endDate)
{

    //QString stDate=(QString)(startDate.year())+"-"+(QString)(startDate.month())+"-"+(QString)(startDate.day());
    //QString enDate=(QString)(endDate.year())+"-"+(QString)(endDate.month())+"-"+(QString)(endDate.day());
    QString q="SELECT idFaktury, kwota, tytulOplaty, terminPlatnosci, dataOplacenia, nadawcaFaktury.idnadawcaFaktury, Nazwa, NumerRachunku, iddaneKontaktowe, adresLinia1, adresLinia2, telefon, email FROM faktury JOIN nadawcaFaktury ON faktury.idNadawcaFaktury = nadawcaFaktury.idnadawcaFaktury JOIN daneKontaktowe ON daneKontaktowe.iddaneKontaktowe = nadawcaFaktury.daneKontaktowe WHERE dataOplacenia>'"+startDate.toString("yyyy-MM-dd")+"'and dataOplacenia<'"+endDate.toString("yyyy-MM-dd")+"'";
    qDebug()<<q;
    QSqlQuery answer=Dao::execQuery(q);
    return answer;
}

QList<Invoice> invoiceDAO::getInvoices()
{
    QSqlQuery a=getInvoicesQuery();
    QList<Invoice> il=parse(a);
    return il;

}
QList<Invoice>invoiceDAO::getInvoices(QDate from,QDate to)
{
    QSqlQuery a=getInvoicesQuery(from,to);
    QList<Invoice> il=parse(a);
    return il;
}

QList<Invoice> invoiceDAO::parse(QSqlQuery a)
{
    QList<Invoice> il;
    while(a.next())
    {
        Invoice i;
        i.id=a.value(0).toInt();
        i.amount=a.value(1).toInt();
        i.title=a.value(2).toString();
        i.dateOfPayment=a.value(3).toDate();
        i.paymentDate=a.value(4).toDate();
        InvoiceSender in;
        in.id=a.value(5).toInt();
        in.name=a.value(6).toString();
        in.accountNumber=a.value(7).toString();

        CantactDetails contact;
        contact.id=a.value(8).toInt();
        contact.addressLine1=a.value(9).toString();
        contact.addressLine2=a.value(10).toString();
        contact.phoneNumber=a.value(11).toString();
        contact.email=a.value(12).toString();
        in.contactDetails=contact;
        i.invoiceSender=in;
        qDebug()<<"invoice id: "<<i.id;
        il.push_back(i);
    }
    return il;
}

Invoice invoiceDAO::getInvoiceById(int id)
{
    QSqlQuery a=getInvoiceByIdQuery(id);
    Invoice i;
    i.id=a.value(0).toInt();
    InvoiceSenderDao isDAO;

    i.invoiceSender=isDAO.getInvoiceSenderById(a.value(1).toInt());
    i.amount=a.value(2).toInt();
    i.title=a.value(3).toString();
    i.dateOfPayment=a.value(4).toDate();
    i.paymentDate=a.value(5).toDate();
    return i;
}
