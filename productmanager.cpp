#include "productmanager.h"
#include "ui_productmanager.h"
#include"globalusers.h"
#include"productclass.h"
#include"editproduct.h"
#include"adminwindow.h"
#include "productclass.h"

productmanager::productmanager(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::productmanager)
{
    ui->setupUi(this);
    ui->label_error->setVisible(false);
}

productmanager::~productmanager()
{
    delete ui;
}

void productmanager::on_pushButton_add_clicked()
{
    QString name = ui->lineEdit_name->text();
    int price = (ui->lineEdit_price->text().toInt());
    int quantity = (ui->lineEdit_quantity->text().toInt());
    productclass* product1 = new productclass(name, price, quantity);
    globalproducts.push_back(product1);
    ui->lineEdit_name->clear();
    ui->lineEdit_price->clear();
    ui->lineEdit_quantity->clear();
    //can be removed
    hide();
    adminWindow* aw=new adminWindow;
    aw->show();
}


void productmanager::on_pushButton_remove_clicked()
{
    int size = globalproducts.size();
    bool found = false;
    QString name = ui->lineEdit_name->text();
    for(int i =0; i<size; i++)
    {
        if(name == globalproducts[i]->name)
        {
            globalproducts.erase(globalproducts.begin()+i);
            ui->lineEdit_name->clear();
            ui->lineEdit_price->clear();
            ui->lineEdit_quantity->clear();
            found = true;
            break;
        }
    }
    if(!found)
    {
        ui->label_error->setVisible(true);
    }
}


void productmanager::on_pushButton_edit_clicked()
{
    int size = globalproducts.size();
    bool found = false;
    QString name = ui->lineEdit_name->text();
    for(int i =0; i<size; i++)
    {
        if(name == globalproducts[i]->name)
        {
            globalproducts.erase(globalproducts.begin()+i);
            ui->lineEdit_name->clear();
            ui->lineEdit_price->clear();
            ui->lineEdit_quantity->clear();
            found = true;
            break;
        }
    }
    if(found)
    {
        hide();
        editproduct* ep = new editproduct;
        ep->show();

    }
    else if(!found)
    {
        ui->label_error->setVisible(true);
    }
}

QString productmanager::getProduct(int i) {
    return globalproducts[i]->name;
}

int productmanager::getQuantity(int i) {
    return globalproducts[i]->quantity;
}

productclass* productmanager::returnProduct(int i) {
    return globalproducts[i];
}
void productmanager::decreaseQuantity(int i) {
    (globalproducts[i]->quantity)--;
}
