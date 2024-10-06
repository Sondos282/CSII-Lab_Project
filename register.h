#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include "users.h"

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_pushButton_register_clicked();

private:
    Ui::Register *ui;
    Users* u;
};

#endif // REGISTER_H
