#ifndef LOGIN_CONTROLER_H
#define LOGIN_CONTROLER_H

#include "daos/user_login_dao.h"
#include "models/user.h"
#include <QString>
#include <QObject>
#include "loginwindow.h"

class Login_controler: public QObject
{
    Q_OBJECT
   // LoginWindow w;
    User_login_dao dao;

public:
    Login_controler();
    User login_user(QString username, QString pasword);
  // ~Login_controler();
signals:
    void login_ok();
};

#endif // LOGIN_CONTROLER_H
