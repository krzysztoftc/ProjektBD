#ifndef LOGIN_CONTROLER_H
#define LOGIN_CONTROLER_H

#include "daos/user_login_dao.h"
#include "models/user.h"
#include <QString>
#include <QObject>
#include "windows/loginwindow.h"
#include <QMessageBox>

class Login_controler: public QObject
{
    Q_OBJECT
   // LoginWindow w;
    UserLoginDao dao;
    User loged_user;

public:
    Login_controler();
    User login_user(QString username, QString pasword);
  // ~Login_controler();
signals:
    void login_ok(User user);
    void login_incorect();
};

#endif // LOGIN_CONTROLER_H
