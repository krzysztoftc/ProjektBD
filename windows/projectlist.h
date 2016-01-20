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

    void update_list();


    ~ProjectList();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableWidget_itemSelectionChanged();

    void on_pushButton_3_clicked();

public slots:

    void slot_update_projects_list();

private:
    Ui::ProjectList *ui;

    ProjectsDdao dao;
    QVector<Project> list;

    DialogNewProject d;

};

#endif // PROJECTLIST_H
