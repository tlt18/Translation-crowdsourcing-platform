#ifndef USER_H
#define USER_H

#include <QString>
#include <vector>
#include <QMessageBox>
//#include "mainuse.h"
using namespace std;

class User
{
public:
    User();
    void Set_Uname(QString uname);                                 //设置用户名
    void Set_Pwd(QString pwd);                                     //设置密码
    void Set_Qualification(int qualification);                     //设置资质
    void Uregister(QString uname,QString pwd,int qualification);   //注册成功时注入信息
    static int Num;                                                //成员编号
    int id;
    QString Show_Name();                                           //返回私有成员用户名
    QString Show_Pwd();                                            //返回私有数据成员密码
    int Show_Point();                                              //返回私有数据成员积分
    QString Show_Qualification();                                      //返回私有数据成员资质
    int Show_Balance();
    void add_balance(int add);
    void clear_balance();
    void chang_pwd(QString pwd);
private:
    QString Uname;
    QString Pwd;
    int Point;
    int Balance;
    int Qualification;

};



class UserList
{
public:
    vector<User> List;

    void add_new(QString uname,QString pwd,int qualification)
    {
        User u;
        u.Uregister(uname,pwd,qualification);
        List.push_back(u);
    }

    int U_Login(QString uname,QString pwd)//判断输入的用户名和密码是否匹配,匹配返回编号，不匹配返回-1
    {
        for(int i=0;i<=User::Num;i++)
           {
            if(List[i].Show_Name()==uname&&List[i].Show_Pwd()==pwd)
                {return i;}
           }
        return -1;
    }

    UserList() {}

};


#endif // USER_H
