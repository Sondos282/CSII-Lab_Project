#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <QDialog>

namespace Ui {
class products;
}

class products : public QDialog
{
    Q_OBJECT

public:
    explicit products(QWidget *parent = nullptr);
    void setparent(QString x);
    QString parentwindow;
    ~products();

private slots:
    void on_pushButton_clicked();

private:
    Ui::products *ui;
};

#endif // PRODUCTS_H
