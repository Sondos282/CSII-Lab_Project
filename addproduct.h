#ifndef ADDPRODUCT_H
#define ADDPRODUCT_H

#include <QDialog>
#include "shoppingcart.h"

namespace Ui {
class addProduct;
}

class addProduct : public QDialog
{
    Q_OBJECT

public:
    explicit addProduct(QWidget *parent = nullptr);
    ~addProduct();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_remove_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_checkout_clicked();

private:
    Ui::addProduct *ui;
    shoppingCart* cart;
};

#endif // ADDPRODUCT_H
