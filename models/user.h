#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    QString login;
    QString password;
    int privilages;

    User();
    User(QString login, QString password, int privilages);
};

#endif // USER_H
