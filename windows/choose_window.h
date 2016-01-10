#ifndef CHOOSE_WINDOW_H
#define CHOOSE_WINDOW_H

#include <QMainWindow>
#include "models/user.h"
#include <QMessageBox>
#include "acountant_module.h"

namespace Ui {
class choose_window;
}

class Choose_window : public QMainWindow
{
    Q_OBJECT

    User loged_user;
    Acountant_module am;


public:
    explicit Choose_window(QWidget *parent = 0);
    ~Choose_window();

public slots:
    void loged_user_slot(User user);

signals:
    void sig_open_acountat_mod (User user);
private slots:
    void on_pushButton_clicked();

private:
    Ui::choose_window *ui;
};

#endif // CHOOSE_WINDOW_H
