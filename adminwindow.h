#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>

namespace Ui {
class adminWindow;
}

class adminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit adminWindow(QWidget *parent = nullptr);
    ~adminWindow();

private slots:
    void on_pushButton_continue_clicked();

    void on_pushButton_continue_2_clicked();

private:
    Ui::adminWindow *ui;
};

#endif // ADMINWINDOW_H
