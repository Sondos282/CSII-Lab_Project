#include "register.h"
#include "ui_register.h"
#include "userlogin.h"
#include "users.h"
#include"globalusers.h"
Register::Register(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->label_errorpass->setVisible(false);
    ui->label_erroruser->setVisible(false);
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_register_clicked()
{
    if (ui->lineEdit_username->text() == "") {
        ui->label_erroruser->setVisible(true);
    }
    else if(ui->lineEdit_password->text() == "") {
        ui->label_errorpass->setVisible(true);
    }
    else {
        globalusersmap.insert({ui->lineEdit_username->text(), ui->lineEdit_password->text()});
        hide();
        userlogin* loginWindow = new userlogin();
        loginWindow->show();
    }
}

