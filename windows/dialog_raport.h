#ifndef DIALOG_RAPORT_H
#define DIALOG_RAPORT_H

#include <QDialog>

namespace Ui {
class Dialog_raport;
}

class Dialog_raport : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_raport(QWidget *parent = 0);
    ~Dialog_raport();

private:
    Ui::Dialog_raport *ui;
};

#endif // DIALOG_RAPORT_H
