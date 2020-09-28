#include "task.h"
int Task::Num=-1;
Task::Task(int ID_release,QString bookname,QString introduction,QString content,QString tasktype,int salary_charge,int salary_worker,QDate deadline)
{
    this->ID_release=ID_release;
    ID_charge=-1;
    for(int i=0;i<10;i++)
       ID_worker[i]=-1;
    Num_worker=-1;
    //各项初始化
    this->bookname=bookname;
    this->introduction=introduction;
    this->content=content;
    this->tasktype=tasktype;
    this->salary_charge=salary_charge;
    this->salary_worker=salary_worker;
    this->deadline=deadline;
    salary=QString::number(salary_charge)+"/"+QString::number(salary_worker);
    r_state="招募负责人";

    state=0;//状态认定

    Num++;
    id=Num;

}

void Task::Set_charge(int ID_charge)
{
    this->ID_charge=ID_charge;
}

void Task::Set_worker(int ID_worker)
{
    Num++;
    this->ID_worker[Num]=ID_worker;
}
