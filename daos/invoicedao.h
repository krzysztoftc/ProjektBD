#ifndef INVOICEDAO_H
#define INVOICEDAO_H
#include "invoicesenderdao.h"
#include <QSqlQuery>
#include "models/invoice.h"
#include "dao.h"

class invoiceDAO: public Dao
{
    QSqlQuery getInvoiceByIdQuery(int id);
    QSqlQuery getInvoicesQuery();
    QSqlQuery getInvoicesQuery(QDate from,QDate to);
    QList<Invoice> parse(QSqlQuery answer);
public:
    QList<Invoice> getInvoices();
    QList<Invoice> getInvoices(QDate from,QDate to);

    Invoice getInvoiceById(int id);

    invoiceDAO();
};

#endif // INVOICEDAO_H
