#ifndef ACOUNTANT_MODULE_H
#define ACOUNTANT_MODULE_H

#include <QMainWindow>
#include "dialog_raport.h"

namespace Ui {
class Acountant_module;
}

class AcountantModule : public QMainWindow
{
    Q_OBJECT

    //Dialog_raport dialog_raport;

public:
    explicit AcountantModule(QWidget *parent = 0);
    ~AcountantModule();

private slots:
    void on_pushButton_clicked();

public slots:
    void generate_raport (QDate from, QDate to);

private:
    Ui::Acountant_module *ui;
};

#endif // ACOUNTANT_MODULE_H
