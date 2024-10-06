#include "userlogin.h"
#include "ui_userlogin.h"
#include "Users.h"
#include "userwindow.h"
#include "Register.h"
#include"globalusers.h"
#include "addproduct.h"
#include <QPixmap>

userlogin::userlogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::userlogin)
{
    ui->setupUi(this);
    // QPixmap pix(":/new/prefix1/userback.jpg");
    // ui->label_background->setPixmap(pix);
    ui->label_error->setVisible(false);
    ui->label_erroruser->setVisible(false);
    ui->label_errorpass->setVisible(false);
}

userlogin::~userlogin()
{
    delete ui;
}

void userlogin::on_pushButton_login_clicked()
{
    QString name = ui->lineEdit_username->text();
    QString pass = ui->lineEdit_password->text();
    bool found = false;

    auto it = globalusersmap.find(name);
    if (it != globalusersmap.end() && it->second== pass) {
        found = true;
    }

    if(found)
    {
            hide();
            addProduct* user = new addProduct();
            user->show();
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


void userlogin::on_pushButton_register_clicked()
{
    hide();
    Register* registeration = new Register();
    registeration->show();
}

