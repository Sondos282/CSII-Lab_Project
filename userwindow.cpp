#include "userwindow.h"
#include "ui_userwindow.h"
#include"products.h"
#include"userlogin.h"
#include "addproduct.h"
#include <QPixmap>

userWindow::userWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::userWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Manage products");
    ui->comboBox->addItem("Checkout");
}

userWindow::~userWindow()
{
    delete ui;
}

void userWindow::on_pushButton_clicked() //continue
{
    if(ui->comboBox->currentIndex()==0)
    {
        hide();
        addProduct* ap = new addProduct;
        ap->show();
    }


}


void userWindow::on_pushButton_2_clicked()
{
    userlogin* ul = new userlogin;
    hide();
    ul->show();
}

