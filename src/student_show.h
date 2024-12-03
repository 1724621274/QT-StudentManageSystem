#ifndef STUDENT_SHOW_H
#define STUDENT_SHOW_H

#include <QDialog>
#include <QFont>
#include "student.h"
#include "QDebug"
#include "des.h"
extern int stuID;//澹版槑鍏ㄥ眬鍙橀噺stuID
extern StudentManager stu;//澹版槑鍏ㄥ眬鍙橀噺stu
extern QString filename;//澹版槑鍏ㄥ眬鍙橀噺filename
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
#endif // STUDENT_SHOW_H
