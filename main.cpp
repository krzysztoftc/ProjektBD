#include "loginwindow.h"
#include <QApplication>

#include "windows/choose_window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login_controler login_controler;
    LoginWindow w;
    w.login_controler = &login_controler;
    QObject::connect(&login_controler, SIGNAL(login_ok()), &w, SLOT(login_ok()));

    w.show();

    choose_window cm;
    cm.show();

    return a.exec();
}
