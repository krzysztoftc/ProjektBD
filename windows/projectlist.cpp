#include "projectlist.h"
#include "ui_projectlist.h"

#include "models/project.h"
#include <QListIterator>
#include <String>
#include <QDebug>

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
    QVector<Project> list;
    list = dao.get_project_list().toVector();
    qDebug()<<"Getted "<<list.size()<<" projects\n";

    QVectorIterator<Project> it(list);
    it.toFront();


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
