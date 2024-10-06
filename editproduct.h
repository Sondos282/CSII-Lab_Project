#ifndef EDITPRODUCT_H
#define EDITPRODUCT_H

#include <QDialog>

namespace Ui {
class editproduct;
}

class editproduct : public QDialog
{
    Q_OBJECT

public:
    explicit editproduct(QWidget *parent = nullptr);
    ~editproduct();

private slots:
    void on_pushButton_clicked();

private:
    Ui::editproduct *ui;
};

#endif // EDITPRODUCT_H
