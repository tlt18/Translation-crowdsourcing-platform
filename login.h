#ifndef LOGIN_H
#define LOGIN_H
#include "user.h"
#include <QDialog>
#include "mainuse.h"
#include "register.h"
extern int ID;

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
