#ifndef PROJECT_H
#define PROJECT_H

#include <QString>
#include <models/person.h>
class Project
{
public:
    Project();
    Project(int project_id, QString name, QString description, int project_manager, Person manager);
    QString name;
    QString description;
    long long project_manager;
    int project_id;
    Person manager;
};

#endif // PROJECT_H
