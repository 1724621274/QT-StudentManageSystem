#ifndef ADD_STUDENT_H
#define ADD_STUDENT_H

#include <QDialog>
#include "student.h"
#include <QMessageBox>
#include <QDoubleValidator>
extern StudentManager stu;
namespace Ui {
class add_student;
}

class add_student : public QDialog
{
    Q_OBJECT

public:
    explicit add_student(QWidget *parent = nullptr);
    ~add_student();

private slots:
    void on_pushButton_fanhui_clicked();

    void on_pushButton_ok_clicked();

    void on_addcj1_textChanged(const QString &arg1);

    void on_addcj2_textChanged(const QString &arg1);

    void on_addcj3_textChanged(const QString &arg1);

    void on_addcj4_textChanged(const QString &arg1);

private:
    Ui::add_student *ui;
    QDoubleValidator *validator;
};

#endif // ADD_STUDENT_H
