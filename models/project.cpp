#include "project.h"

Project::Project(int project_id, QString name, QString description, int project_manager, Person manager)
{
    this->project_id = project_id;
    this->name = name;
    this->description = description;
    this->project_manager = project_manager;
    this->manager = manager;
}

Project::Project(){

}
