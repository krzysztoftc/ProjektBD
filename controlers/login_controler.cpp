#include "login_controler.h"

Login_controler::Login_controler()
{

}

User Login_controler::login_user(QString username, QString password){
    User_login_dao dao;
    User user = dao.get_user(username);

    qDebug() <<"login user: "<<username<<" pass: "<<password;

    if(user.login == username && user.password == password){
       qDebug() << "Pomyslnie zalogowano uzytkownika: "<<user.login <<" z uprawnieniami: "<<user.privilages<<endl;
    }

    else{
        qDebug() <<"Niepoprawne dane logowania!\n";
    }
    return user;
}
