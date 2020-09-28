#ifndef TASK_H
#define TASK_H
#include <vector>
#include <QString>
#include <QDate>
using namespace std;

class Task
{
public:
    int state;//0招募负责人，1招募译者，2译者提交译文，3负责人提出修改意见，4译者再交译文，5负责人提交，6任务完成
    QString r_state;
    Task(int ID_release,QString bookname,QString introduction,QString content,QString tasktype,int salary_charge,int salary_worker,QDate deadline); //构造函数指明负责人，负责人和翻译人初始化为-1
//发布任务时所需要的信息
    int salary_charge;    //工资
    int salary_worker;    //工资
    QString salary;
    QString bookname;
    QString introduction;
    QString content;
    QString tasktype;
    QDate deadline;

    void Set_charge(int ID_charge);
    void Set_worker(int ID_worker);
    int ID_release;       //发布者编号
    int ID_charge;        //负责人编号
    int ID_worker[10];    //翻译者编号
    static int Num;       //总任务数
    int id;               //任务编号
    int Num_worker;       //当前翻译者数为（Num_worker+1）

};

class Tasklist
{
public:
    vector<Task>List;

    //发布并创建任务
    void release(int ID_release,QString bookname,QString introduction,QString content,QString tasktype,int salary_charge,int salary_worker,QDate deadline)
    {
        Task T(ID_release,bookname,introduction,content,tasktype,salary_charge,salary_worker,deadline);
        List.push_back(T);
    }


};




#endif // TASK_H
