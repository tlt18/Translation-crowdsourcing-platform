#include "register.h"
#include "ui_register.h"
#include "QMessageBox"
extern UserList userlist;

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_clicked()//有问题的注册按钮
{
    QString uname=ui->UnamelineEdit->text();
    int flag=0;//flag=1:注册不成功 flag=0:注册成功

    if(User::Num!=-1)//判断是否重复注册
    {
        for(int i=0;i<=User::Num;i++)
            if(userlist.List[i].Show_Name()==uname)
                flag=1;
        if(flag==1)
            QMessageBox::warning(this, tr("警告！"),tr("用户名已经被注册！"),QMessageBox::Yes);
    }

    QString pwd1=ui->PwdlineEdit->text();
    QString pwd2=ui->PwdlineEdit2->text();
    if(pwd1!=pwd2) //判断密码是否重复输入
    {
        QMessageBox::warning(this, tr("警告！"),tr("密码输入不一致！"),QMessageBox::Yes);
        flag=1;
    }

    if(uname==""||pwd1=="")
    {
        QMessageBox::warning(this, tr("警告！"),tr("用户名和密码不能为空！"),QMessageBox::Yes);
    }
    else
    {
    int qualification=ui->QualifiacationBox->currentIndex( );
    if(flag==0)
    {
        userlist.add_new(uname,pwd1,qualification);
        QMessageBox::warning(this, tr("提示！"),tr("注册成功，请登录！"),QMessageBox::Yes);
        this->close();
        delete this;
    }
    }
}


