#ifndef ACOUNTANT_MODULE_H
#define ACOUNTANT_MODULE_H

#include <QMainWindow>
#include "dialog_raport.h"

namespace Ui {
class Acountant_module;
}

class Acountant_module : public QMainWindow
{
    Q_OBJECT

 //Dialog_raport dialog_raport;

public:
    explicit Acountant_module(QWidget *parent = 0);
    ~Acountant_module();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Acountant_module *ui;
};

#endif // ACOUNTANT_MODULE_H
