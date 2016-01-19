#ifndef INVOICESENDERDAO_H
#define INVOICESENDERDAO_H
#include "dao.h"
#include <QSqlQuery>
#include "models/invoicesender.h"
#include "daos/contactdetailsdao.h"
#include "models/cantactdetails.h"

class InvoiceSenderDao : public Dao
{
    QSqlQuery getInvoiceSenderByIdQuery(int id);
    QSqlQuery getInvoiceSenderQuery();
public:
    InvoiceSenderDao();
    QList<InvoiceSender> getInvoiceSender();
    InvoiceSender getInvoiceSenderById(int id);

};

#endif // INVOICESENDERDAO_H
