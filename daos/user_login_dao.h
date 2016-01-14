#ifndef USER_LOGIN_DAO_H
#define USER_LOGIN_DAO_H

#include <QSqlQuery>
#include "dao.h"
#include "../models/user.h"

class UserLoginDao : public Dao
{
public:
    UserLoginDao();
    QSqlQuery get_user_data(QString username);
    User get_user(QString username);
};

#endif // USER_LOGIN_DAO_H
