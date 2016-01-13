#ifndef USER_H
#define USER_H

#include "models/person.h"
#include <QString>


class User :public Person
{
public:
    QString login;
    QString password;
    int privilages;

    User();
    User(QString login, QString password, int privilages);
};

#endif // USER_H
