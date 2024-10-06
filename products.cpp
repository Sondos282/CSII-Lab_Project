#include "products.h"
#include "ui_products.h"
#include"users.h"
#include"mainwindow.h"
#include"globalusers.h"
#include"adminwindow.h"
#include <algorithm>
#include"userwindow.h"
products::products(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::products)
{
    ui->setupUi(this);
    QPixmap pix(":/new/prefix1/productsback.jpg");
    ui->label_background->setPixmap(pix);
    int numProducts = globalproducts.size();
    parentwindow ="user";
    if(numProducts>9)
    {
        numProducts=9;
    }

    for (int i = 0; i < numProducts; ++i) {
        QLabel *currentLabel = nullptr;
        switch (i) {
        case 0:
            currentLabel = ui->label;
            break;
        case 1:
            currentLabel = ui->label_2;
            break;
        case 2:
            currentLabel = ui->label_3;
            break;
        case 3:
            currentLabel = ui->label_4;
            break;
        case 4:
            currentLabel = ui->label_5;
            break;
        case 5:
            currentLabel = ui->label_6;
            break;
        case 6:
            currentLabel = ui->label_7;
            break;
        case 7:
            currentLabel = ui->label_8;
            break;
        case 8:
            currentLabel = ui->label_9;
            break;
        default:
            break;
        }

        if (currentLabel) {
            currentLabel->setText("<html>Name: " + globalproducts[i]->name +"<br>" +
                                  "Price: " + QString::number(globalproducts[i]->price) + "<br>"+
                                  "Quantity: " + QString::number(globalproducts[i]->quantity)+ "</html>");
        }
    }

    // if(globalproducts.size()==0)
    // {
    //     ui->label_background->setPixmap(pix);//does nothing
    // }
    // else if(globalproducts.size()==1)
    // {
    //     ui->label->setText("<html>Name: " + globalproducts[0]->name + "<br>" +
    //                        "Price: " + QString::number(globalproducts[0]->price) + "<br>" +
    //                        "Quantity: " + QString::number(globalproducts[0]->quantity) + "</html>");
    // }
    // else if(globalproducts.size()==2)
    // {
    //     ui->label->setText("Name: " + globalproducts[0]->name+"/n" + "Price: "+QString::number(globalproducts[0]->price)+"/n"+"Quantity: "+QString::number(globalproducts[0]->quantity));
    //     ui->label_2->setText("Name: " + globalproducts[1]->name+"/n" + "Price: "+QString::number(globalproducts[1]->price)+"/n"+"Quantity: "+QString::number(globalproducts[1]->quantity));
    // }
    // else if(globalproducts.size()==3)
    // {
    //     ui->label->setText("Name: " + globalproducts[0]->name+"/n" + "Price: "+QString::number(globalproducts[0]->price)+"/n"+"Quantity: "+QString::number(globalproducts[0]->quantity));
    //     ui->label_2->setText("Name: " + globalproducts[1]->name+"/n" + "Price: "+QString::number(globalproducts[1]->price)+"/n"+"Quantity: "+QString::number(globalproducts[1]->quantity));
    //     ui->label_3->setText("Name: " + globalproducts[2]->name+"/n" + "Price: "+QString::number(globalproducts[2]->price)+"/n"+"Quantity: "+QString::number(globalproducts[2]->quantity));

    // }
    // else if(globalproducts.size()==4)
    // {
    //     ui->label->setText("Name: " + globalproducts[0]->name+"/n" + "Price: "+QString::number(globalproducts[0]->price)+"/n"+"Quantity: "+QString::number(globalproducts[0]->quantity));
    //     ui->label_2->setText("Name: " + globalproducts[1]->name+"/n" + "Price: "+QString::number(globalproducts[1]->price)+"/n"+"Quantity: "+QString::number(globalproducts[1]->quantity));
    //     ui->label_3->setText("Name: " + globalproducts[2]->name+"/n" + "Price: "+QString::number(globalproducts[2]->price)+"/n"+"Quantity: "+QString::number(globalproducts[2]->quantity));
    //     ui->label_4->setText("Name: " + globalproducts[3]->name+"/n" + "Price: "+QString::number(globalproducts[3]->price)+"/n"+"Quantity: "+QString::number(globalproducts[3]->quantity));
    // }
    // else if(globalproducts.size()==5)
    // {
    //     ui->label->setText("Name: " + globalproducts[0]->name+"/n" + "Price: "+QString::number(globalproducts[0]->price)+"/n"+"Quantity: "+QString::number(globalproducts[0]->quantity));
    //     ui->label_2->setText("Name: " + globalproducts[1]->name+"/n" + "Price: "+QString::number(globalproducts[1]->price)+"/n"+"Quantity: "+QString::number(globalproducts[1]->quantity));
    //     ui->label_3->setText("Name: " + globalproducts[2]->name+"/n" + "Price: "+QString::number(globalproducts[2]->price)+"/n"+"Quantity: "+QString::number(globalproducts[2]->quantity));
    //     ui->label_4->setText("Name: " + globalproducts[3]->name+"/n" + "Price: "+QString::number(globalproducts[3]->price)+"/n"+"Quantity: "+QString::number(globalproducts[3]->quantity));
    //     ui->label_5->setText("Name: " + globalproducts[4]->name+"/n" + "Price: "+QString::number(globalproducts[4]->price)+"/n"+"Quantity: "+QString::number(globalproducts[4]->quantity));

    // }
    // else if(globalproducts.size()==6)
    // {
    //     ui->label->setText("Name: " + globalproducts[0]->name+"/n" + "Price: "+QString::number(globalproducts[0]->price)+"/n"+"Quantity: "+QString::number(globalproducts[0]->quantity));
    //     ui->label_2->setText("Name: " + globalproducts[1]->name+"/n" + "Price: "+QString::number(globalproducts[1]->price)+"/n"+"Quantity: "+QString::number(globalproducts[1]->quantity));
    //     ui->label_3->setText("Name: " + globalproducts[2]->name+"/n" + "Price: "+QString::number(globalproducts[2]->price)+"/n"+"Quantity: "+QString::number(globalproducts[2]->quantity));
    //     ui->label_4->setText("Name: " + globalproducts[3]->name+"/n" + "Price: "+QString::number(globalproducts[3]->price)+"/n"+"Quantity: "+QString::number(globalproducts[3]->quantity));
    //     ui->label_5->setText("Name: " + globalproducts[4]->name+"/n" + "Price: "+QString::number(globalproducts[4]->price)+"/n"+"Quantity: "+QString::number(globalproducts[4]->quantity));
    //     ui->label_6->setText("Name: " + globalproducts[5]->name+"/n" + "Price: "+QString::number(globalproducts[5]->price)+"/n"+"Quantity: "+QString::number(globalproducts[5]->quantity));

    // }
    // else if(globalproducts.size()==7)
    // {
    //     ui->label->setText("Name: " + globalproducts[0]->name+"/n" + "Price: "+QString::number(globalproducts[0]->price)+"/n"+"Quantity: "+QString::number(globalproducts[0]->quantity));
    //     ui->label_2->setText("Name: " + globalproducts[1]->name+"/n" + "Price: "+QString::number(globalproducts[1]->price)+"/n"+"Quantity: "+QString::number(globalproducts[1]->quantity));
    //     ui->label_3->setText("Name: " + globalproducts[2]->name+"/n" + "Price: "+QString::number(globalproducts[2]->price)+"/n"+"Quantity: "+QString::number(globalproducts[2]->quantity));
    //     ui->label_4->setText("Name: " + globalproducts[3]->name+"/n" + "Price: "+QString::number(globalproducts[3]->price)+"/n"+"Quantity: "+QString::number(globalproducts[3]->quantity));
    //     ui->label_5->setText("Name: " + globalproducts[4]->name+"/n" + "Price: "+QString::number(globalproducts[4]->price)+"/n"+"Quantity: "+QString::number(globalproducts[4]->quantity));
    //     ui->label_6->setText("Name: " + globalproducts[5]->name+"/n" + "Price: "+QString::number(globalproducts[5]->price)+"/n"+"Quantity: "+QString::number(globalproducts[5]->quantity));
    //     ui->label_7->setText("Name: " + globalproducts[6]->name+"/n" + "Price: "+QString::number(globalproducts[6]->price)+"/n"+"Quantity: "+QString::number(globalproducts[6]->quantity));

    // }
    // else if(globalproducts.size()==8)
    // {
    //     ui->label->setText("Name: " + globalproducts[0]->name+"/n" + "Price: "+QString::number(globalproducts[0]->price)+"/n"+"Quantity: "+QString::number(globalproducts[0]->quantity));
    //     ui->label_2->setText("Name: " + globalproducts[1]->name+"/n" + "Price: "+QString::number(globalproducts[1]->price)+"/n"+"Quantity: "+QString::number(globalproducts[1]->quantity));
    //     ui->label_3->setText("Name: " + globalproducts[2]->name+"/n" + "Price: "+QString::number(globalproducts[2]->price)+"/n"+"Quantity: "+QString::number(globalproducts[2]->quantity));
    //     ui->label_4->setText("Name: " + globalproducts[3]->name+"/n" + "Price: "+QString::number(globalproducts[3]->price)+"/n"+"Quantity: "+QString::number(globalproducts[3]->quantity));
    //     ui->label_5->setText("Name: " + globalproducts[4]->name+"/n" + "Price: "+QString::number(globalproducts[4]->price)+"/n"+"Quantity: "+QString::number(globalproducts[4]->quantity));
    //     ui->label_6->setText("Name: " + globalproducts[5]->name+"/n" + "Price: "+QString::number(globalproducts[5]->price)+"/n"+"Quantity: "+QString::number(globalproducts[5]->quantity));
    //     ui->label_7->setText("Name: " + globalproducts[6]->name+"/n" + "Price: "+QString::number(globalproducts[6]->price)+"/n"+"Quantity: "+QString::number(globalproducts[6]->quantity));
    //     ui->label_8->setText("Name: " + globalproducts[7]->name+"/n" + "Price: "+QString::number(globalproducts[7]->price)+"/n"+"Quantity: "+QString::number(globalproducts[7]->quantity));

    // }
    // else
    // {
    //     ui->label->setText("Name: " + globalproducts[0]->name+ "/n" + "Price: "+QString::number(globalproducts[0]->price)+"/n"+"Quantity: "+QString::number(globalproducts[0]->quantity));
    //     ui->label_2->setText("Name: " + globalproducts[1]->name+"/n" + "Price: "+QString::number(globalproducts[1]->price)+"/n"+"Quantity: "+QString::number(globalproducts[1]->quantity));
    //     ui->label_3->setText("Name: " + globalproducts[2]->name+"/n" + "Price: "+QString::number(globalproducts[2]->price)+"/n"+"Quantity: "+QString::number(globalproducts[2]->quantity));
    //     ui->label_4->setText("Name: " + globalproducts[3]->name+"/n" + "Price: "+QString::number(globalproducts[3]->price)+"/n"+"Quantity: "+QString::number(globalproducts[3]->quantity));
    //     ui->label_5->setText("Name: " + globalproducts[4]->name+"/n" + "Price: "+QString::number(globalproducts[4]->price)+"/n"+"Quantity: "+QString::number(globalproducts[4]->quantity));
    //     ui->label_6->setText("Name: " + globalproducts[5]->name+"/n" + "Price: "+QString::number(globalproducts[5]->price)+"/n"+"Quantity: "+QString::number(globalproducts[5]->quantity));
    //     ui->label_7->setText("Name: " + globalproducts[6]->name+"/n" + "Price: "+QString::number(globalproducts[6]->price)+"/n"+"Quantity: "+QString::number(globalproducts[6]->quantity));
    //     ui->label_8->setText("Name: " + globalproducts[7]->name+"/n" + "Price: "+QString::number(globalproducts[7]->price)+"/n"+"Quantity: "+QString::number(globalproducts[7]->quantity));
    //     ui->label_9->setText("Name: " + globalproducts[8]->name+"/n" + "Price: "+QString::number(globalproducts[8]->price)+"/n"+"Quantity: "+QString::number(globalproducts[8]->quantity));

    // }
}

products::~products()
{
    delete ui;
}

void products::on_pushButton_clicked()
{
    hide();
    if(parentwindow =="admin")
    {
        adminWindow* aw= new adminWindow;
        aw->show();
    }
    else
    {
        userWindow* uw = new userWindow;
        uw->show();
    }

}

void products::setparent(QString x)
{
    parentwindow = x;
}
