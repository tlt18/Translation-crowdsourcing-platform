#include "user.h"

//用户类构造函数
User::User()
{
}

void User::Set_Uname(QString uname)
{
    Uname=uname;
}

void User::Set_Pwd(QString pwd)
{
    Pwd=pwd;
}

void User::Set_Qualification(int qualification)
{
    Qualification=qualification;
}

void User::Uregister(QString uname,QString pwd,int qualification)
{
    Set_Uname(uname);
    Set_Pwd(pwd);
    Set_Qualification(qualification);
    Point=qualification+3;
    Balance=0;
    Num++;
    id=Num;
}

QString User::Show_Name()
{
    return Uname;
}

QString User::Show_Pwd()
{
    return Pwd;
}

int User::Show_Point()
{
    return Point;
}

QString User::Show_Qualification()
{
    if(Qualification==0)
       return "英语专业八级";
    if(Qualification==1)
        return "托福110+";
    if(Qualification==2)
        return "SAT2200+";
    else
        return "无";
}

int User::Show_Balance()
{
    return Balance;
}

void User::add_balance(int add)
{
    Balance+=add;
}

void User::clear_balance()
{
    Balance=0;
}

void User::chang_pwd(QString pwd)
{
    Pwd=pwd;
}

int User::Num=-1;
