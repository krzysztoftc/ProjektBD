#include "choose_window.h"
#include "ui_choose_window.h"

#include <QPixmap>

choose_window::choose_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::choose_window)
{

    ui->setupUi(this);

}

choose_window::~choose_window()
{
    delete ui;
}
