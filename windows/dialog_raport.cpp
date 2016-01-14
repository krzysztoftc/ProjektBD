#include "dialog_raport.h"
#include "ui_dialog_raport.h"

DialogRaport::DialogRaport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_raport)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate().currentDate());
    ui->dateEdit_2->setDate(QDate().currentDate());

    emit selected_period(ui->dateEdit->date(), ui->dateEdit_2->date());
}

DialogRaport::~DialogRaport()
{
    delete ui;
}
