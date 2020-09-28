#include "show_task.h"
#include "ui_show_task.h"

Show_task::Show_task(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Show_task)
{
    ui->setupUi(this);
}

Show_task::~Show_task()
{
    delete ui;
}
