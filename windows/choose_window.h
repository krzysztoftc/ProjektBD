#ifndef CHOOSE_WINDOW_H
#define CHOOSE_WINDOW_H

#include <QMainWindow>

namespace Ui {
class choose_window;
}

class choose_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit choose_window(QWidget *parent = 0);
    ~choose_window();

private:
    Ui::choose_window *ui;
};

#endif // CHOOSE_WINDOW_H
