#ifndef PROJECTSDDAO_H
#define PROJECTSDDAO_H

#include <QSqlQuery>
#include "dao.h"
#include "models/project.h"
#include "models/employee.h"
#include <QMessageBox>

class ProjectsDdao : public Dao
{
    QSqlQuery get_project_list_q();
    //QSqlQuery get_project_by_id_q(int id);
    QSqlQuery get_pm_list_q();
public:
    ProjectsDdao();

    QList <Project> get_project_list();

    //Project get_project_by_id();
    QList <Employee> get_pm_list();

    int add_project(Project p);
};

#endif // PROJECTSDDAO_H
