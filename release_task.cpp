#include "release_task.h"
#include "ui_release_task.h"
#include "QMessageBox"

release_Task::release_Task(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::release_Task)
{
    ui->setupUi(this);
}

release_Task::~release_Task()
{
    delete ui;
}

void release_Task::on_pushButton_2_clicked()
{
    MainUse* m=new MainUse;
    m->show();
    close();
    delete this;
}

void release_Task::on_pushButton_clicked()
{
    //判断输入信息的完备性
    QString bookname=ui->bookname->text();
    QString introduction=ui->introduction->text();
    QString content=ui->content->toPlainText();
    QString tasktype=ui->tasktype->currentText();
    int salary_charge=(ui->salary_charge->text()).toInt();
    int salary_worker=(ui->salary_worker->text()).toInt();

    QDate deadline=ui->deadline->date();
    if(bookname=="")//翻译书目不能为空
    {
        QMessageBox::warning(this, tr("警告！"),tr("翻译书目不能为空！"),QMessageBox::Yes);

    }
    else if(content=="")//翻译内容不能为空
    {
        QMessageBox::warning(this, tr("警告！"),tr("翻译内容不能为空！"),QMessageBox::Yes);

    }

    else if( (!(salary_charge>0&&salary_charge<=10000)) || (!(salary_worker>0&&salary_worker<=10000)))//请输入1-10000区间的薪酬！
    {
         QMessageBox::warning(this, tr("警告！"),tr("请输入1-10000区间的薪酬！"),QMessageBox::Yes);

    }

    else //成功创建任务
    {
       tasklist.release(ID,bookname,introduction,content,tasktype,salary_charge,salary_worker,deadline);
       QMessageBox::warning(this, tr("提示！"),tr("成功创建任务！"),QMessageBox::Yes);
       MainUse* m=new MainUse;
       m->show();
       close();
       delete this;


    }
}
