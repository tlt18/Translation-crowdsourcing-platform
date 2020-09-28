#ifndef SHOW_TASK_H
#define SHOW_TASK_H

#include <QDialog>

namespace Ui {
class Show_task;
}

class Show_task : public QDialog
{
    Q_OBJECT

public:
    explicit Show_task(QWidget *parent = nullptr);
    ~Show_task();

private:
    Ui::Show_task *ui;
};

#endif // SHOW_TASK_H
