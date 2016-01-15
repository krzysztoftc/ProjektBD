#ifndef PROJECTLIST_H
#define PROJECTLIST_H

#include <QWidget>
#include "daos/projectsddao.h"
#include "models/project.h"
#include "windows/dialognewproject.h"

namespace Ui {
class ProjectList;
}

class ProjectList : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectList(QWidget *parent = 0);
    ~ProjectList();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void slot_update_projects_list();

private:
    Ui::ProjectList *ui;
    void update_list();
    ProjectsDdao dao;
};

#endif // PROJECTLIST_H
