#ifndef DIALOG_RAPORT_H
#define DIALOG_RAPORT_H

#include <QDialog>
#include <QDate>
#include <QPair>

namespace Ui {
class Dialog_raport;
}

class DialogRaport : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRaport(QWidget *parent = 0);
    ~DialogRaport();
    QDate startDate;
    QDate endDate;
signals:
    void selected_period(QDate from, QDate to);


private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog_raport *ui;
};

#endif // DIALOG_RAPORT_H
