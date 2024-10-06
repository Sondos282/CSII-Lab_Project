#ifndef USERLOGIN_H
#define USERLOGIN_H
#include"users.h"
#include <QDialog>

namespace Ui {
class userlogin;
}

class userlogin : public QDialog
{
    Q_OBJECT

public:
    explicit userlogin(QWidget *parent = nullptr);
    ~userlogin();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_register_clicked();

private:
    Ui::userlogin *ui;
};

#endif // USERLOGIN_H
