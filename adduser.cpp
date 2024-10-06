#include "adduser.h"
#include "ui_adduser.h"
#include"globalusers.h"
#include"adminwindow.h"
#include<QString>
#include"edituser.h"
adduser::adduser(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adduser)
{
    ui->setupUi(this);
    ui->label_error->setVisible(false);
}

adduser::~adduser()
{
    delete ui;

}

void adduser::on_pushButton_clicked()
{
    QString name = ui->lineEdit_name->text();
    QString password = ui->lineEdit_pass->text();
    globalusersmap.insert(make_pair(name, password));
    ui->lineEdit_name->clear();
    ui->lineEdit_pass->clear();
    hide();
    adminWindow* aw = new adminWindow;
    aw->show();
}


void adduser::on_pushButton_edit_clicked()
{
    QString name = ui->lineEdit_name->text();
    QString password = ui->lineEdit_pass->text();
    auto it = globalusersmap.find(name);
    if (it != globalusersmap.end() && globalusersmap[name] == password)
    {
        globalusersmap.erase(name);
        edituser* eu = new edituser;
        ui->lineEdit_name->clear();
        ui->lineEdit_pass->clear();
        hide();
        eu->show();
    }
    else {
        ui->label_error->setVisible(true);
    }
}


void adduser::on_pushButton_remove_clicked()
{
    QString name = ui->lineEdit_name->text();
    QString password = ui->lineEdit_pass->text();
    auto it = globalusersmap.find(name);
    if (it != globalusersmap.end() && globalusersmap[name] == password)
    {
        globalusersmap.erase(name);
        ui->lineEdit_name->clear();
        ui->lineEdit_pass->clear();
    }
    else {
        ui->label_error->setVisible(true);
    }
}


void adduser::on_pushButton_back_clicked()
{
    hide();
    adminWindow* aw = new adminWindow;
    aw->show();
}


void adduser::on_pushButton_add_clicked()
{
    QString name = ui->lineEdit_name->text();
    QString password = ui->lineEdit_pass->text();
    globalusersmap.insert(make_pair(name, password));
    ui->lineEdit_name->clear();
    ui->lineEdit_pass->clear();
    hide();
    adminWindow* aw = new adminWindow;
    aw->show();
}

