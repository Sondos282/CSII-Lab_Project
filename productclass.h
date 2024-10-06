#ifndef PRODUCTCLASS_H
#define PRODUCTCLASS_H
#include<QString>
class productclass
{
public:
    productclass(QString n, int p, int q);
    QString name;
    int price;
    int quantity;
};

#endif // PRODUCTCLASS_H
