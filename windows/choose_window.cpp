#include "choose_window.h"
#include "ui_choose_window.h"

#include <QPixmap>

ChooseWindow::ChooseWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::choose_window)
{

    ui->setupUi(this);


}

ChooseWindow::~ChooseWindow()
{
    delete ui;
}

void ChooseWindow::loged_user_slot(User user){
    this->show();
    loged_user = user;
}

void ChooseWindow::on_pushButton_clicked()
{
    if (loged_user.privilages < 2){
    emit sig_open_acountat_mod(loged_user);
        am.show();
    }
    else
        QMessageBox::critical(this, "Brak uprawnień", "Brak dostępu do modułu");
}
