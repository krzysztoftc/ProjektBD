#ifndef LOGIN_CONTROLER_H
#define LOGIN_CONTROLER_H

#include "daos/user_login_dao.h"
#include "models/user.h"
#include <QString>


class Login_controler
{
    User_login_dao dao;
public:
    Login_controler();
    User login_user(QString username, QString pasword);
};

#endif // LOGIN_CONTROLER_H
