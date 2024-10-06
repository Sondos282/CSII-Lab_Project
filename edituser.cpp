#include "edituser.h"
#include "ui_edituser.h"
#include"globalusers.h"
#include"adminwindow.h"
edituser::edituser(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::edituser)
{
    ui->setupUi(this);
}

edituser::~edituser()
{
    delete ui;
}

void edituser::on_pushButton_edit_clicked()
{
    QString name = ui->lineEdit_name2->text();
    QString password = ui->lineEdit_pass2->text();
    globalusersmap.insert(make_pair(name, password));
    hide();
    adminWindow* aw = new adminWindow;
    aw->show();
}

