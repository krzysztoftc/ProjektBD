#include "login_controler.h"

Login_controler::Login_controler()
{
   // w.show();
}

User Login_controler::login_user(QString username, QString password){
    UserLoginDao dao;
    User user = dao.get_user(username);

    qDebug() <<"login user: "<<username<<" pass: "<<password;

    if(user.login == username && user.password == password){
       qDebug() << "Pomyslnie zalogowano uzytkownika: "<<user.login <<" z uprawnieniami: "<<user.privilages<<endl;
       qDebug() << "Emiting signal login_ok()!\n";
       emit login_ok(user);
       qDebug() << "Signal emited!\n";
    }

    else{
        qDebug() <<"Niepoprawne dane logowania!\n";
        emit login_incorect();
    }

    loged_user = user;

    return user;
}

//Login_controler::~Login_controler(){

//}
