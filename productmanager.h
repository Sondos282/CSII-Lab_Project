#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H

#include <QDialog>
#include <productclass.h>

namespace Ui {
class productmanager;
}

class productmanager : public QDialog
{
    Q_OBJECT

public:
    explicit productmanager(QWidget *parent = nullptr);
    QString getProduct(int i);
    int getQuantity(int i);
    productclass* returnProduct(int i);
    void decreaseQuantity(int i);
    ~productmanager();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_remove_clicked();

    void on_pushButton_edit_clicked();

private:
    Ui::productmanager *ui;
};

#endif // PRODUCTMANAGER_H
