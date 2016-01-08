#include "choose_module.h"
#include "ui_choose_module.h"

Choose_module::Choose_module(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Choose_module)
{
    ui->setupUi(this);

    QPixmap pixmap("graphics/boos.png");
    ui->label->setPixmap(pixmap);


    ui->label->show();
}

Choose_module::~Choose_module()
{
    delete ui;
}
