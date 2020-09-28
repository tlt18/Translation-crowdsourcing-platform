#include "mainuse.h"
#include "ui_mainuse.h"

MainUse::MainUse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainUse)
{
    ui->setupUi(this);

    //个人信息显示
    ui->lusename->setText(userlist.List[ID].Show_Name());
    ui->lpoint->setText(QString::number(userlist.List[ID].Show_Point()));
    ui->lqualification->setText(userlist.List[ID].Show_Qualification());
    ui->lbalance->setText(QString::number(userlist.List[ID].Show_Balance()));


    //全部任务显示
    ui->tableWidget->setRowCount(Task::Num+1);
    for(int i=0;i<Task::Num+1;i++)
    {
      ui->tableWidget->setItem(i,0,new QTableWidgetItem(tasklist.List[i].bookname));
      ui->tableWidget->setItem(i,1,new QTableWidgetItem(tasklist.List[i].tasktype));
      ui->tableWidget->setItem(i,2,new QTableWidgetItem(tasklist.List[i].salary));
      ui->tableWidget->setItem(i,3,new QTableWidgetItem(tasklist.List[i].r_state));
    }
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

}

MainUse::~MainUse()
{
    delete ui;
}

void MainUse::on_pushButton_clicked()//退出登录
{
    QMessageBox::warning(this, tr("提示！"),tr("成功退出！"),QMessageBox::Yes);
    close();
    delete this;
}


void MainUse::on_pushButton_2_clicked()//充值
{
    int add=(ui->lineEdit->text()).toInt();
    if(add<=0||add>10000)//判断充值数额合法性
        QMessageBox::warning(this, tr("提示！"),tr("请选择1-10000的金额充值！"),QMessageBox::Yes);
    else
    {
        userlist.List[ID].add_balance(add);
        //QMessageBox::warning(this, tr("提示！"),tr("充值成功！"),QMessageBox::Yes);
        MainUse* m=new MainUse;
        m->show();
        close();
        delete this;
    }
}

void MainUse::on_pushButton_3_clicked()//提现
{
    int sub=(ui->lineEdit_2->text()).toInt();
    if(sub<=0||sub>userlist.List[ID].Show_Balance())
        QMessageBox::warning(this, tr("提示！"),tr("提现失败！请输入合法金额！"),QMessageBox::Yes);
    else
    {
        userlist.List[ID].add_balance(-sub);
        QMessageBox::warning(this, tr("提示！"),tr("提现成功！"),QMessageBox::Yes);
        MainUse* m=new MainUse;
        m->show();
        close();
        delete this;
    }

}

void MainUse::on_pushButton_4_clicked()//修改密码
{
    QString pwd1=ui->lineEdit_3->text();
    QString pwd2=ui->lineEdit_4->text();
    if(pwd1!=pwd2) //判断密码是否重复输入
        QMessageBox::warning(this, tr("警告！"),tr("密码输入不一致！"),QMessageBox::Yes);
    else if(pwd1=="")//判断密码是否为空
        QMessageBox::warning(this, tr("警告！"),tr("新密码不能为空！"),QMessageBox::Yes);
    else
    {
        userlist.List[ID].chang_pwd(pwd1);
        QMessageBox::warning(this, tr("提示！"),tr("修改成功！请重新登录！"),QMessageBox::Yes);
        close();
        delete this;
    }
}

void MainUse::on_pushButton_5_clicked()//发布任务
{
    release_Task *re_T=new release_Task;
    re_T->show();
    close();
    delete this;
}

void MainUse::on_pushButton_6_clicked()
{
    currentline=ui->tableWidget->currentRow();
    if(currentline==-1)
        QMessageBox::warning(this, tr("提示！"),tr("请选中一个任务"),QMessageBox::Yes);
    else
    {
        Show_task *show_task=new Show_task;
        show_task->show();
    }



}
