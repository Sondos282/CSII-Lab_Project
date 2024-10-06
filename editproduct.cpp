#include "editproduct.h"
#include "ui_editproduct.h"
#include"globalusers.h"
#include"adminwindow.h"
editproduct::editproduct(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::editproduct)
{
    ui->setupUi(this);
}

editproduct::~editproduct()
{
    delete ui;
}

void editproduct::on_pushButton_clicked()
{
    QString name = ui->lineEdit_name->text();
    int price = (ui->lineEdit_price->text().toInt());
    int quantity = (ui->lineEdit_quantity->text().toInt());
    productclass* product1 = new productclass(name, price, quantity);
    globalproducts.push_back(product1);
    ui->lineEdit_name->clear();
    ui->lineEdit_price->clear();
    ui->lineEdit_quantity->clear();
    hide();
    adminWindow* aw = new adminWindow;
    aw->show();
}

