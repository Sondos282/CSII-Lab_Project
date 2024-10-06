#ifndef CHECKOUTTT_H
#define CHECKOUTTT_H

#include <QDialog>

namespace Ui {
class Checkouttt;
}

class Checkouttt : public QDialog
{
    Q_OBJECT

public:
    explicit Checkouttt(QWidget *parent = nullptr);
    ~Checkouttt();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_confirm_clicked();

private:
    Ui::Checkouttt *ui;
};

#endif // CHECKOUTTT_H
