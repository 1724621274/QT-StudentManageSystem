#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFont>
#include "student.h"
#include "QDebug"
#include "des.h"
extern int stuID;//声明全局变量stuID
extern StudentManager stu;//声明全局变量stu
extern QString filename;//声明全局变量filename
extern QString deskey;
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    void dispdata(Student *student);
    ~Dialog();

private slots:


    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
