#ifndef MAINUSE_H
#define MAINUSE_H
//#include "login.h"
#include <QDialog>
#include "user.h"
#include <release_task.h>
#include "task.h"
#include "show_task.h"
extern int ID;
extern UserList userlist;
extern Tasklist tasklist;
extern int currentline;

namespace Ui {
class MainUse;
}

class MainUse : public QDialog
{
    Q_OBJECT

public:
    explicit MainUse(QWidget *parent = nullptr);
    ~MainUse();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainUse *ui;
};

#endif   // MAINUSE_H
