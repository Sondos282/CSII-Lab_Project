#ifndef LOGINUSERS_H
#define LOGINUSERS_H

#include <QDialog>

namespace Ui {
class loginUsers;
}

class loginUsers : public QDialog
{
    Q_OBJECT

public:
    explicit loginUsers(QWidget *parent = nullptr);
    ~loginUsers();

private:
    Ui::loginUsers *ui;
};

#endif // LOGINUSERS_H
