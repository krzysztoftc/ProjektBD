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

void Choose_window::loged_user_slot(User user){
    this->show();
    loged_user = user;
}

void Choose_window::on_pushButton_clicked()
{
    if (loged_user.privilages < 2){
    emit sig_open_acountat_mod(loged_user);
        am.show();
    }
    else
        QMessageBox::critical(this, "Brak uprawnień", "Brak dostępu do modułu");
}
