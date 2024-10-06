#include "shoppingcart.h"
#include "productmanager.h"
#include "globalusers.h"
#include <QString>
#include <QVector>
using namespace std;

shoppingCart::shoppingCart(productmanager* pm) {
    currentpm = pm;
    total = 0;
}

void shoppingCart:: addItem(QString a) {

    int size = globalproducts.size();

    for (int i = 0; i < size; i++)
    {
        if (a == currentpm->getProduct(i))
        {
            if (currentpm->getQuantity(i) > 0) {

                items.push_back(currentpm->returnProduct(i));
                currentpm->decreaseQuantity(i);

                total = total + currentpm->returnProduct(i)->price;
                break;
            }
            else if (currentpm->getQuantity(i) == 0)
                QString n = "The product " + (currentpm->getProduct(i)) + " is out of stock.";
        }
    }
}

void shoppingCart::remove(QString r) {

    int size = globalproducts.size();
    for (int i = 0; i < size; i++)
    {
        if (r == items[i]->name)
        {
            items.erase(items.begin() + i);
            (currentpm->returnProduct(i))->quantity++;
            total = total - (currentpm->returnProduct(i))->price;
            break;
        }
    }
}

int shoppingCart::getTotal() {
    return total;
}
