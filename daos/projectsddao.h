#ifndef PROJECTSDDAO_H
#define PROJECTSDDAO_H

#include <QSqlQuery>
#include "dao.h"
#include "models/project.h"
#include "models/employee.h"

class ProjectsDdao : public Dao
{
public:
    ProjectsDdao();
    QSqlQuery get_project_list_q();
    QList <Project> get_project_list();

    QSqlQuery get_pm_list_q();
    QList <Employee> get_pm_list();
};

#endif // PROJECTSDDAO_H
