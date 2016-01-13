#include "project_manager_module.h"
#include "ui_project_manager_module.h"

project_manager_module::project_manager_module(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::project_manager_module)
{
    ui->setupUi(this);
}

project_manager_module::~project_manager_module()
{
    delete ui;
}
