#include "mainwindow.h"
#include "register.h"
#include "mainuse.h"
#include "login.h"
#include "task.h"
#include <QApplication>


UserList userlist;
Tasklist tasklist;
int currentline=-1;
int ID=-1;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login log;
    log.show();

    

    return a.exec();
}
