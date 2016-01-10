#include "choose_window.h"
#include "ui_choose_window.h"

#include <QPixmap>

Choose_window::Choose_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::choose_window)
{

    ui->setupUi(this);


}

Choose_window::~Choose_window()
{
    delete ui;
}

void Choose_window::loged_user(User user){
    this->show();
    loged_user = user;
}
