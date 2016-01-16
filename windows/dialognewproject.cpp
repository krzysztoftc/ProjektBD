#include "dialognewproject.h"
#include "ui_dialognewproject.h"

DialogNewProject::DialogNewProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNewProject)
{
    ui->setupUi(this);

    update_pm_list();
}

DialogNewProject::~DialogNewProject()
{
    delete ui;
}

void DialogNewProject::update_pm_list(){
    pm_list = dao.get_pm_list().toVector();

     ui->comboBox->insertItem(0, "");
    foreach (const Employee &e, pm_list) {
        const QString item (e.name + " " + e.surname);
        unsigned int r = ui->comboBox->count();
        ui->comboBox->insertItem(r, item,QVariant((long long)e.pesel));
    }
}

void DialogNewProject::on_pushButton_clicked()
{
    accept_changes(false);
}

void DialogNewProject::on_pushButton_2_clicked()
{
    this->close();
}

void DialogNewProject::make_edit(Project p){
    this->p = p;
    ui->pushButton->setText("Zapisz");
    ui->lineEdit->setText(p.name);
    ui->textEdit->setText(p.description);
    int index = ui->comboBox->findData(QVariant((long long)p.project_manager));
    ui->comboBox->setCurrentIndex(index);
    qDebug()<<"Pm Pesel: "<<p.project_manager<<" Selecting pm on index: "<<index;
    disconnect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_clicked()));
    connect (ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(on_editButton_clicked()));
}

void DialogNewProject::on_editButton_clicked(){
    qDebug()<<"Edit";

    accept_changes(true);
}

void DialogNewProject::accept_changes(bool edit_not_add){
    QString project_name = ui->lineEdit->text();
    QString project_desc = ui->textEdit->toPlainText();
    int selected_pm = ui->comboBox->currentIndex();
    qDebug()<<ui->comboBox->currentText()<<" " <<ui->comboBox->currentData();
    if (project_name.isEmpty() || project_desc.isEmpty() || selected_pm == 0){
        QMessageBox::critical(this, "Niepoprawne dane", "Wypelnij wszystkie pola");
    }
    else{
        Employee pm = pm_list.at(selected_pm-1);
        p.name = project_name;
        p.description = project_desc;
        p.manager = pm;
        p.project_manager = pm.pesel;

        if(edit_not_add) dao.update_project(p);
        else dao.add_project(p);

        qDebug()<<"Update sig";
        emit sig_update_projects_list();
        this->close();
    }

}
