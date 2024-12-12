#ifndef STUDENT_SHOW_H
#define STUDENT_SHOW_H

#include <QDialog>
#include <QFont>
#include "student.h"
#include "QDebug"
#include "des.h"
#include <QDoubleValidator>
#include <QMessageBox>
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
    void dispdata(Student &student);
    ~Dialog();

signals:
    void updatestudent();

private slots:


    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_update_cj1_textChanged(const QString &arg1);

    void on_update_cj2_textChanged(const QString &arg1);

    void on_update_cj3_textChanged(const QString &arg1);

    void on_update_cj4_textChanged(const QString &arg1);

private:
    QDoubleValidator* validator = new QDoubleValidator(this);
    Student showstu;
    Ui::Dialog *ui;
};
#endif // STUDENT_SHOW_H
