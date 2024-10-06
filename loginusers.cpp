#include "loginusers.h"
#include "ui_loginusers.h"

loginUsers::loginUsers(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loginUsers)
{
    ui->setupUi(this);
}

loginUsers::~loginUsers()
{
    delete ui;
}
