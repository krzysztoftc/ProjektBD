#ifndef PROJECT_MANAGER_MODULE_H
#define PROJECT_MANAGER_MODULE_H

#include <QMainWindow>

namespace Ui {
class project_manager_module;
}

class projectManagerModule : public QMainWindow
{
    Q_OBJECT

public:
    explicit projectManagerModule(QWidget *parent = 0);
    ~projectManagerModule();

private:
    Ui::project_manager_module *ui;
};

#endif // PROJECT_MANAGER_MODULE_H
