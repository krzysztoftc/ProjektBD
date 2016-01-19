#include "acountant_module.h"
#include "ui_acountant_module.h"
#include "daos/clientcontractdao.h"
#include "daos/invoicedao.h"
AcountantModule::AcountantModule(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Acountant_module)
{
    ui->setupUi(this);
}

AcountantModule::~AcountantModule()
{
    delete ui;
}

void AcountantModule::on_pushButton_clicked()
{
    DialogRaport dialog_raport(this);
    dialog_raport.exec();
    generate_raport(dialog_raport.startDate,dialog_raport.endDate);

}

void AcountantModule::generate_raport(QDate from, QDate to){
    ClientContractDAO clientDAO;
    QList<ClientContract> contracts=clientDAO.getClientContracts(from,to);
    QList<Invoice> invoices;
    invoiceDAO invoiceDAO;
    invoices=invoiceDAO.getInvoices(from,to);
    qint64 bilans=0;
    ui->tableWidget->setRowCount(0);
    for(int i=0;i<contracts.length();i++)
    {
        int r=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(r);
        QTableWidgetItem *data=new QTableWidgetItem(contracts[i].endDate.toString("yyyy-MM-dd"));
        QTableWidgetItem *title=new QTableWidgetItem(contracts[i].project.name);
        QTableWidgetItem *price=new QTableWidgetItem("+"+ QString::number(contracts[i].price));
        QTableWidgetItem *sender=new QTableWidgetItem(contracts[i].client.name);
        ui->tableWidget->setItem(r, 0, data);
        ui->tableWidget->setItem(r, 1, sender);
        ui->tableWidget->setItem(r, 2, title);
        ui->tableWidget->setItem(r, 3, price);
        ui->tableWidget->item(r,0)->setBackground(Qt::green);
        ui->tableWidget->item(r,1)->setBackground(Qt::green);
        ui->tableWidget->item(r,2)->setBackground(Qt::green);
        ui->tableWidget->item(r,3)->setBackground(Qt::green);
        bilans+=contracts[i].price;
    }
    for(int i=0;i<invoices.length();i++)
    {
        int r=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(r);
        QTableWidgetItem *data=new QTableWidgetItem(invoices[i].paymentDate.toString("yyyy-MM-dd"));
        QTableWidgetItem *title=new QTableWidgetItem(invoices[i].title);
        QTableWidgetItem *price=new QTableWidgetItem("-"+QString::number(invoices[i].amount));
        QTableWidgetItem *sender=new QTableWidgetItem(invoices[i].invoiceSender.name);
        ui->tableWidget->setItem(r, 0, data);
        ui->tableWidget->setItem(r, 1, sender);
        ui->tableWidget->setItem(r, 2, title);
        ui->tableWidget->setItem(r, 3, price);
        ui->tableWidget->item(r,0)->setBackground(Qt::red);
        ui->tableWidget->item(r,1)->setBackground(Qt::red);
        ui->tableWidget->item(r,2)->setBackground(Qt::red);
        ui->tableWidget->item(r,3)->setBackground(Qt::red);
        bilans-=invoices[i].amount;
    }
    qDebug()<<bilans;
    ui->label_2->setText("Bilans: "+QString::number(bilans)+"zl");
    ui->tableWidget->setSortingEnabled(true);
}

