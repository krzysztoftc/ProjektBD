#include "contactdetailsdao.h"

ContactDetailsDAO::ContactDetailsDAO()
{

}

QSqlQuery ContactDetailsDAO::getContactDetailsByIdQuery(int id)
{
    QString q = "SELECT * FROM daneKontaktowe WHERE iddaneKontaktowe="+id;
    QSqlQuery answer = Dao::execQuery(q);
    return answer;
}

QSqlQuery ContactDetailsDAO::getContactDetailsQuery()
{
    QString q = "SELECT * FROM daneKontaktowe";
    QSqlQuery answer = Dao::execQuery(q);
    return answer;
}

CantactDetails ContactDetailsDAO::getContactDetailsById(int id)
{
    QSqlQuery a=getContactDetailsByIdQuery(id);
    CantactDetails c;
    c.id=a.value(0).toInt();
    c.addressLine1=a.value(1).toString();
    c.addressLine2=a.value(2).toString();
    c.phoneNumber=a.value(3).toString();
    c.email=a.value(4).toString();
    return c;
}

QList<CantactDetails> ContactDetailsDAO::getContactDetails()
{
    QList<CantactDetails> list;
    return list;
}
