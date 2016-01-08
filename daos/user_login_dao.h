#ifndef USER_LOGIN_DAO_H
#define USER_LOGIN_DAO_H

#include <QSqlQuery>

class User_login_dao : public Dao
{
public:
    User_login_dao();
    QSqlQuery get_user_data(QString username);
};

#endif // USER_LOGIN_DAO_H
