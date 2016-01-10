#ifndef CHOOSE_WINDOW_H
#define CHOOSE_WINDOW_H

#include <QMainWindow>
#include "models/user.h"

namespace Ui {
class choose_window;
}

class Choose_window : public QMainWindow
{
    Q_OBJECT

    User loged_user;

public:
    explicit Choose_window(QWidget *parent = 0);
    ~Choose_window();

public slots:
    void loged_user(User user);

signals:
    void sig_open_acountat_mod (User user);
private:
    Ui::choose_window *ui;
};

#endif // CHOOSE_WINDOW_H
