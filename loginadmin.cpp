#include "loginadmin.h"
#include "ui_loginadmin.h"
#include "adminwindow.h"

loginAdmin::loginAdmin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loginAdmin)
{
    ui->setupUi(this);
    ui->label_error->setVisible(false);
    ui->label_errorpass->setVisible(false);
    ui->label_erroruser->setVisible(false);
}

loginAdmin::~loginAdmin()
{
    delete ui;
}

void loginAdmin::on_pushButton_login_clicked()
{
    if(ui->lineEdit_username->text() == "admin" && ui->lineEdit_password->text() == "password") {
        hide();
        adminWindow* admin = new adminWindow();
        admin->show();
    }
    else if (ui->lineEdit_username->text() == "") {
        ui->label_erroruser->setVisible(true);
    }
    else if(ui->lineEdit_password->text() == "") {
        ui->label_errorpass->setVisible(true);
    }
    else {
        ui->label_error->setVisible(true);
    }
}

QString loginAdmin::getAdminName() {
    return (ui->lineEdit_username->text());
}

