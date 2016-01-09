#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "repository/database.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_clicked()
{
    login_controler.login_user(ui->lineEdit->text(),ui->lineEdit_2->text());
}


void LoginWindow::on_lineEdit_2_returnPressed()
{
    login_controler.login_user(ui->lineEdit->text(),ui->lineEdit_2->text());
}

