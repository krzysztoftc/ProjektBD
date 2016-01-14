#include "projectsddao.h"

ProjectsDdao::ProjectsDdao()
{

}

QSqlQuery ProjectsDdao::get_project_list_q(){
    QString q = "SELECT idProjekty, nazwaProjektu, opisProjektu, projectManager, imie, nazwisko FROM projekty JOIN pracownicy ON projekty.projectManager = pracownicy.pesel WHERE 1";
    Dao::connect();
    QSqlQuery answer = Dao::execQuery(q);
    Dao::disconnect();
    return answer;
}

QList<Project> ProjectsDdao::get_project_list(){
    QSqlQuery a = get_project_list_q();
    QList<Project> pl;

    while(a.next()){
        Project p;
        p.project_id = a.value(0).toInt();
        p.name = a.value(1).toString();
        p.description = a.value(2).toString();
        p.project_manager = a.value(3).toLongLong();
        qDebug()<<"Menadzer id: "<<a.value(3).toLongLong();
        Person per;
        per.name = a.value(4).toString();
        per.surname = a.value(5).toString();
        per.pesel = a.value(3).toLongLong();
        p.manager = per;
        pl.push_back(p);
   }

    return pl;
}
