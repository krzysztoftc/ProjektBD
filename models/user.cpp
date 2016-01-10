#include "user.h"

User::User()
{
    login ="";
    password = "";
    privilages = 0;
}

User::User(QString login, QString password, int privilages){
    this->login = login;
    this->password = password;
    this->privilages = privilages;
}
