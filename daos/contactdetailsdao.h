#ifndef CONTACTDETAILSDAO_H
#define CONTACTDETAILSDAO_H
#include <models/cantactdetails.h>
#include <QSqlQuery>
#include <daos/dao.h>
class ContactDetailsDAO:public Dao
{
private:
    QSqlQuery getContactDetailsByIdQuery(int id);
    QSqlQuery getContactDetailsQuery();
public:
    ContactDetailsDAO();
    CantactDetails getContactDetailsById(int id);
    QList<CantactDetails> getContactDetails();
};

#endif // CONTACTDETAILSDAO_H
