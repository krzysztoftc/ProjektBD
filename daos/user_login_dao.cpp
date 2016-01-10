#include "user_login_dao.h"

User_login_dao::User_login_dao()
{

}

QSqlQuery User_login_dao::get_user_data(QString username){
   Dao::connect();
   QSqlQuery answer = Dao::execQuery("Select iduzytkownicy, idPracownika, idPoziomDostepu, login, haslo FROM uzytkownicy WHERE login like '"+username+"';");
   Dao::disconnect();
   return answer;
}

User User_login_dao::get_user(QString username){
    qDebug() << "here5\n";
    QSqlQuery answer = get_user_data(username);
    qDebug() << "here6\n";
    while(answer.next()){
        QString login = answer.value(3).toString();
        QString password = answer.value(4).toString();
        int privilages = answer.value(2).toInt();

        qDebug() << "Getted user data: " << login <<" pass: " <<password << " uprawnienia: "<<privilages<<endl;

        return User(login, password, privilages);
    }

    return User();
}
