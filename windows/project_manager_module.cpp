#include "project_manager_module.h"
#include "ui_project_manager_module.h"

projectManagerModule::projectManagerModule(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::project_manager_module)
{
    ui->setupUi(this);
}

projectManagerModule::~projectManagerModule()
{
    delete ui;
}
