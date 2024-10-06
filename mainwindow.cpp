#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userlogin.h"
#include <QPixmap>
#include"loginadmin.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/new/prefix1/mainbackground.jpg");
    ui->label_background->setPixmap(pix);
    ui->pushButton_user->setStyleSheet("background: transparent; border: none;");
    ui->pushButton_admin->setStyleSheet("background: transparent; border: none;");
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_pushButton_user_clicked()
{
    hide();
    userlogin* log = new userlogin();
    log->show();
}


void MainWindow::on_pushButton_admin_clicked()
{
    hide();
    loginAdmin* admin = new loginAdmin();
    admin->show();
}

