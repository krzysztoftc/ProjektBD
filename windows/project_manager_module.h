#ifndef PROJECT_MANAGER_MODULE_H
#define PROJECT_MANAGER_MODULE_H

#include <QMainWindow>

namespace Ui {
class project_manager_module;
}

class project_manager_module : public QMainWindow
{
    Q_OBJECT

public:
    explicit project_manager_module(QWidget *parent = 0);
    ~project_manager_module();

private:
    Ui::project_manager_module *ui;
};

#endif // PROJECT_MANAGER_MODULE_H
