#ifndef USER_LOGIN_DAO_H
#define USER_LOGIN_DAO_H

#include <QSqlQuery>
#include "dao.h"
#include "../models/user.h"

class User_login_dao : public Dao
{
public:
    User_login_dao();
    QSqlQuery get_user_data(QString username);
    User get_user(QString username);
};

#endif // USER_LOGIN_DAO_H
