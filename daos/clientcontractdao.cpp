#include "clientcontractdao.h"

ClientContractDAO::ClientContractDAO()
{

}


QSqlQuery ClientContractDAO::getClientContractByIdQuery(int id)
{
    QString q = "SELECT * FROM umowyKlienci WHERE idUmowyKlienct="+id;
    QSqlQuery answer = Dao::execQuery(q);
    return answer;
}

QSqlQuery ClientContractDAO::getClientContractsQuery()
{
    QString q = "SELECT idumowyKlienta, dataZawarcia, dataWygasniecia, wartosc, nip, nazwa, iddaneKontaktowe, adresLinia1, adresLinia2, telefon, email FROM umowyKlienci JOIN klienci ON umowyKlienci.klient = klienci.nip JOIN daneKontaktowe ON klienci.daneKontaktowe = daneKontaktowe.iddaneKontaktowe";
    QSqlQuery answer = Dao::execQuery(q);
    return answer;
}
QSqlQuery ClientContractDAO::getClientContractsQuery(QDate startDate,QDate endDate)
{

    QString q = "SELECT idumowyKlienta, dataZawarcia, dataWygasniecia, wartosc, nip, nazwa, iddaneKontaktowe, adresLinia1, adresLinia2, telefon, email,nazwaProjektu FROM umowyKlienci JOIN klienci ON umowyKlienci.klient = klienci.nip JOIN daneKontaktowe ON klienci.daneKontaktowe = daneKontaktowe.iddaneKontaktowe Join projekty ON umowyKlienci.projekt=projekty.idProjekty WHERE dataZawarcia>'"+startDate.toString("yyyy-MM-dd")+"'and dataZawarcia<'"+endDate.toString("yyyy-MM-dd")+"'";
    QSqlQuery answer = Dao::execQuery(q);
    return answer;
}

ClientContract ClientContractDAO::getClientContractById(int id)
{
    QSqlQuery answer =getClientContractByIdQuery(id);
    ClientContract c;
    c.id=answer.value(0).toInt();
    c.startDate=answer.value(1).toDate();
    c.endDate=answer.value(2).toDate();
    c.price=answer.value(5).toInt();
    ClientDAO clientDao;
    c.client=clientDao.getClientById(answer.value(3).toLongLong());

    return c;

}

QList<ClientContract> ClientContractDAO::getClientContracts()
{
    QList<ClientContract> list;
    QSqlQuery answer =getClientContractsQuery();
    list=parse(answer);
    return list;
}
QList<ClientContract> ClientContractDAO::getClientContracts(QDate startDate,QDate endDate)
{
    QList<ClientContract> list;
    QSqlQuery answer =getClientContractsQuery(startDate,endDate);
    list=parse(answer);
    return list;
}

QList<ClientContract> ClientContractDAO::parse(QSqlQuery answer)
{
    QList<ClientContract> list;
    ClientContract c;
    while(answer.next())
    {
        c.id=answer.value(0).toInt();
        c.startDate=answer.value(1).toDate();
        c.endDate=answer.value(2).toDate();
        c.price=answer.value(3).toInt();
        Client client;
        client.NIP=answer.value(4).toLongLong();
        client.name=answer.value(5).toString();
        CantactDetails details;
        details.id=answer.value(6).toInt();
        details.addressLine1=answer.value(7).toString();
        details.addressLine2=answer.value(8).toString();
        details.phoneNumber=answer.value(9).toString();
        details.email=answer.value(10).toString();
        Project p;
        p.name=answer.value(11).toString();
        c.project=p;
        client.contactDetails=details;
        c.client=client;
        list.push_back(c);
    }
    return list;
}
