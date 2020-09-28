#ifndef RELEASE_TASK_H
#define RELEASE_TASK_H
#include <QString>
#include "task.h"
#include <QDialog>
#include "mainuse.h"
extern Tasklist tasklist;
extern int ID;

namespace Ui {
class release_Task;
}

class release_Task : public QDialog
{
    Q_OBJECT

public:
    explicit release_Task(QWidget *parent = nullptr);
    ~release_Task();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::release_Task *ui;
};

#endif // RELEASE_TASK_H
