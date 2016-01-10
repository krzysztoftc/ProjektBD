#include "dialog_raport.h"
#include "ui_dialog_raport.h"

#include <QDate>

Dialog_raport::Dialog_raport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_raport)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate().currentDate());
    ui->dateEdit_2->setDate(QDate().currentDate());

}

Dialog_raport::~Dialog_raport()
{
    delete ui;
}
