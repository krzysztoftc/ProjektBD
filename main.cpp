#include "loginwindow.h"
#include <QApplication>

#include "windows/choose_window.h"
#include "models/user.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login_controler login_controler;
    Choose_window cw;

    LoginWindow w;
    w.login_controler = &login_controler;

    QObject::connect(&login_controler, SIGNAL(login_ok(User)), &w, SLOT(login_ok()));
    QObject::connect(&login_controler, SIGNAL(login_incorect()), &w, SLOT(login_incorect()));
    QObject::connect(&login_controler, SIGNAL(login_ok(User)), &cw, SLOT(loged_user(User)));







    w.show();

    return a.exec();
}
