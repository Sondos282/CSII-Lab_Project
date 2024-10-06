#include "addproduct.h"
#include "ui_addproduct.h"
#include "shoppingcart.h"
#include "globalusers.h"
#include "userwindow.h"
#include "productmanager.h"
#include "checkouttt.h"
#include <QString>

addProduct::addProduct(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addProduct)
{
    ui->setupUi(this);
    for(int i = 0; i < globalproducts.size(); i++) {
        ui->comboBox->addItem(globalproducts[i]->name);
    }
    productmanager* gm = new productmanager;
    cart = new shoppingCart(gm);
    ui->label_add->setVisible(false);
    ui->label_remove->setVisible(false);
}

addProduct::~addProduct()
{
    delete ui;
}

void addProduct::on_pushButton_add_clicked()
{
    cart->addItem(ui->comboBox->currentText());
    ui->label_remove->setVisible(false);
    ui->label_add->setVisible(true);
    ui->label_price->setText("Your total cart price is: " + QString::number(cart->getTotal()));
}


void addProduct::on_pushButton_remove_clicked()
{
    cart->remove(ui->comboBox->currentText());
    ui->label_add->setVisible(false);
    ui->label_remove->setVisible(true);
    ui->label_price->setText("Your total cart price is: " + QString::number(cart->getTotal()));
}


void addProduct::on_pushButton_back_clicked()
{
    hide();
    userWindow* u = new userWindow;
    u->show();
}


void addProduct::on_pushButton_checkout_clicked()
{
    hide();
    Checkouttt* ch = new Checkouttt;
    ch->show();
}

