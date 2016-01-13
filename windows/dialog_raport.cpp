#include "dialog_raport.h"
#include "ui_dialog_raport.h"

Dialog_raport::Dialog_raport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_raport)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate().currentDate());
    ui->dateEdit_2->setDate(QDate().currentDate());

    emit selected_period(ui->dateEdit->date(), ui->dateEdit_2->date());
}

Dialog_raport::~Dialog_raport()
{
    delete ui;
}
