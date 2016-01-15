#include "windows/loginwindow.h"
#include <QApplication>

#include "windows/choose_window.h"
#include "models/user.h"
#include "windows/projectlist.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login_controler login_controler;
    ChooseWindow cw;

    Database db;
    LoginWindow w;
    w.login_controler = &login_controler;

    QObject::connect(&login_controler, SIGNAL(login_ok(User)), &w, SLOT(login_ok()));
    QObject::connect(&login_controler, SIGNAL(login_incorect()), &w, SLOT(login_incorect()));
    QObject::connect(&login_controler, SIGNAL(login_ok(User)), &cw, SLOT(loged_user_slot(User)));

    w.show();
    //cw.loged_user_slot(User ("kowalski","haslo",1));

    ProjectList pl;
    pl.show();

    return a.exec();
}
