#include "acountant_module.h"
#include "ui_acountant_module.h"

Acountant_module::Acountant_module(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Acountant_module)
{
    ui->setupUi(this);
}

Acountant_module::~Acountant_module()
{
    delete ui;
}

void Acountant_module::on_pushButton_clicked()
{
//    Dialog_raport dialog_raport;

   // dialog_raport.show();
}
