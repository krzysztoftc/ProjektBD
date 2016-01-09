#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "controlers/login_controler.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT
    Login_controler login_controler;


public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_2_returnPressed();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
