#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "productmanager.h"
#include "productclass.h"
#include <QVector>
using namespace std;

class shoppingCart
{
public:
    shoppingCart(productmanager* pm);
    void addItem(QString n);
    void remove(QString r);
    int getTotal();

private:
    QVector<productclass* > items;
    productmanager* currentpm;
    int total;
};

#endif // SHOPPINGCART_H
