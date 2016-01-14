#include "acountant_module.h"
#include "ui_acountant_module.h"

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
}

void AcountantModule::generate_raport(QDate from, QDate to){

}
