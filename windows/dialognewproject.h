#ifndef DIALOGNEWPROJECT_H
#define DIALOGNEWPROJECT_H

#include <QDialog>
#include "daos/projectsddao.h"
#include "models/employee.h"

namespace Ui {
class DialogNewProject;
}

class DialogNewProject : public QDialog
{
    Q_OBJECT

    Project p;

public:
    explicit DialogNewProject(QWidget *parent = 0);
    void make_edit(Project p);
    ~DialogNewProject();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_editButton_clicked();

public slots:


signals:
    void sig_update_projects_list();

private:
    Ui::DialogNewProject *ui;
    QVector <Employee> pm_list;

    ProjectsDdao dao;

    void update_pm_list();

    void accept_changes(bool edit_not_add);
    // void (*foo)(int);


};

#endif // DIALOGNEWPROJECT_H
