#include "checkouttt.h"
#include "ui_checkouttt.h"
#include "addproduct.h"

Checkouttt::Checkouttt(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Checkouttt)
{
    ui->setupUi(this);
    ui->lineEdit_num->setVisible(false);
    ui->lineEdit_pass->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->label_errornum->setVisible(false);
    ui->label_errorpass->setVisible(false);
}

Checkouttt::~Checkouttt()
{
    delete ui;
}

void Checkouttt::on_pushButton_back_clicked()
{
    hide();
    addProduct* ap = new addProduct();
    ap->show();
}


void Checkouttt::on_pushButton_confirm_clicked()
{
    if(ui->radioButton_cash->isChecked()) {
        ui->label_4->setVisible(true);
    }
    else if(ui->radioButton_visa->isChecked()) {
        ui->lineEdit_num->setVisible(true);
        ui->lineEdit_pass->setVisible(true);
        ui->label_2->setVisible(true);
        ui->label_3->setVisible(true);
        if(ui->label_2->text() == "") {
            ui->label_errornum->setVisible(true);
        }
        else if(ui->label_3->text() == "") {
            ui->label_errorpass->setVisible(true);
        }
        else {
            ui->label_4->setVisible(true);
        }
    }
}

