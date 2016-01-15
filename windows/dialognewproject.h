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

public:
    explicit DialogNewProject(QWidget *parent = 0);
    ~DialogNewProject();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void sig_update_projects_list();

private:
    Ui::DialogNewProject *ui;
    QVector <Employee> pm_list;

    ProjectsDdao dao;

    void update_pm_list();

};

#endif // DIALOGNEWPROJECT_H
