#include "projectlist.h"
#include "ui_projectlist.h"

#include "models/project.h"
#include <QListIterator>
#include <String>
#include <QDebug>
#include "daos/invoicedao.h"
using namespace std;

ProjectList::ProjectList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectList)
{
    ui->setupUi(this);

    update_list();
}

ProjectList::~ProjectList()
{
    delete ui;
}

void ProjectList::update_list(){
    list = dao.get_project_list().toVector();
    qDebug()<<"Getted "<<list.size()<<" projects\n";

    QVectorIterator<Project> it(list);
    it.toFront();

    while(ui->tableWidget->rowCount()>0)
           ui->tableWidget->removeRow(0);

   // while (it.hasNext()){
    foreach (const Project &p, list) {
        //Project p = it.next();
        int r = ui->tableWidget->rowCount();
        ui -> tableWidget->insertRow(r);
        QTableWidgetItem *name = new QTableWidgetItem(p.name);
        QTableWidgetItem *desc = new QTableWidgetItem(p.description);
        QTableWidgetItem *pm = new QTableWidgetItem(p.manager.name + " " + p.manager.surname);

        ui->tableWidget->setItem(r, 0, name);
        ui->tableWidget->setItem(r, 1, desc);
        ui->tableWidget->setItem(r, 2, pm);
    }
}

void ProjectList::on_pushButton_clicked()
{
    this->close();
}

void ProjectList::on_pushButton_2_clicked()
{
    DialogNewProject d;
    connect(&d,SIGNAL(sig_update_projects_list()),this,SLOT(slot_update_projects_list()));
    d.exec();
//    update_list();
}

void ProjectList::slot_update_projects_list(){
    qDebug()<<"Signal getted";
    update_list();
}

void ProjectList::on_tableWidget_itemSelectionChanged()
{
    ui->pushButton_3->setEnabled(true);
}

void ProjectList::on_pushButton_3_clicked()
{
    Project p = list.at(ui->tableWidget->currentRow());
    qDebug()<<"Selected project manager: "<<p.manager.name<<" "<<p.manager.surname;
    DialogNewProject d;
    connect(&d,SIGNAL(sig_update_projects_list()),this,SLOT(slot_update_projects_list()));
    d.make_edit(p);
    d.exec();
}
