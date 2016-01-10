#ifndef CHOOSE_MODULE_H
#define CHOOSE_MODULE_H

#include <QDialog>

namespace Ui {
class Choose_module;
}

class Choose_module : public QDialog
{
    Q_OBJECT

public:
    explicit Choose_module(QWidget *parent = 0);
    ~Choose_module();

private:
    Ui::Choose_module *ui;
};

#endif // CHOOSE_MODULE_H
