#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "loginadmin.h"
#include"productmanager.h"
#include"adduser.h"
#include"products.h"
#include"mainwindow.h"
#include "edituser.h"

adminWindow::adminWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminWindow)
{
    loginAdmin l;

    ui->setupUi(this);
    //ui->label_welcome->setText("Welcome " + l.getAdminName());

    ui->comboBox->addItem("Add user");
    ui->comboBox->addItem("Edit user");
    ui->comboBox->addItem("Remove user");
    ui->comboBox->addItem("Add item");
    ui->comboBox->addItem("Remove item");
    ui->comboBox->addItem("Edit item");
    ui->comboBox->addItem("View products");

}

adminWindow::~adminWindow()
{
    delete ui;
}

void adminWindow::on_pushButton_continue_clicked()
{
    if(ui->comboBox->currentIndex()==0||ui->comboBox->currentIndex()==2)
    {
        adduser* au = new adduser;
        hide();
        au->show();
    }
    else if(ui->comboBox->currentIndex()==1) {
        edituser* eu = new edituser;
        hide();
        eu->show();
    }
    else if(ui->comboBox->currentIndex()==6)
    {
        products* p = new products;
        p->setparent("admin");
        hide();
        p->show();
    }
    else
    {
        productmanager* pm = new productmanager;
        hide();
        pm->show();
    }
}


void adminWindow::on_pushButton_continue_2_clicked()
{
    hide();
    MainWindow* mw = new MainWindow;
    mw->show();
}

