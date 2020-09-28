#include "login.h"
#include "ui_login.h"

#include "QMessageBox"
extern UserList userlist;
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_2_clicked()
{
    Register *reg=new Register(this);
    reg->show();
}

void Login::on_pushButton_clicked()
{
    //判断用户名和密码是否正确
    if(User::Num==-1)
        QMessageBox::warning(this, tr("警告！"),tr("尚未有注册用户！"),QMessageBox::Yes);
    else
    {
        ID=userlist.U_Login ( ui->UseNamelineEdit->text() , ui->PwdlineEdit->text());
        if(ID==-1)
        {
            QMessageBox::warning(this, tr("警告！"),tr("用户名或密码错误！"),QMessageBox::Yes);
            // 清空内容并定位光标
            ui->UseNamelineEdit->clear();
            ui->PwdlineEdit->clear();
            ui->UseNamelineEdit->setFocus();
        }
        else
        {
            MainUse* m=new MainUse;
            m->show();
            ui->UseNamelineEdit->clear();
            ui->PwdlineEdit->clear();
            ui->UseNamelineEdit->setFocus();


        }

    }


}
