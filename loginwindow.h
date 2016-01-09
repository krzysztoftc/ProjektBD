#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "controlers/login_controler.h"
#include <QObject>

namespace Ui {
class LoginWindow;
}

class Login_controler;

class LoginWindow : public QMainWindow
{
    Q_OBJECT



public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();
    Login_controler *login_controler;

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_2_returnPressed();

public slots:
    void login_ok();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
