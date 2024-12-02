#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent): QDialog(parent), ui(new Ui::Dialog)
{

    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::dispdata(Student *student){
    ui->name->setText("姓名："+student->getName());
    ui->xingbie->setText("性别："+stu.gender_int_to_str[student->getGender()]);
    ui->xuehao->setText("学号："+QString::number(student->getStudentId()));
    ui->nianji->setText("年级："+QString::number(student->getGrade()));
    ui->zhuanye->setText("专业："+stu.major_int_to_str[student->getMajorId()]);
    ui->banji->setText("班级："+QString::number(student->getClassNumber()));
    ui->qinshi->setText("寝室："+QString::number(student->getDormitoryNumber()));
    ui->chuanghao->setText("床号："+QString::number(student->getBedNumber()));
    ui->cj1->setText("成绩1："+QString::number(student->getScore1()));
    ui->cj2->setText("成绩2："+QString::number(student->getScore2()));
    ui->cj3->setText("成绩3："+QString::number(student->getScore3()));
    ui->cj4->setText("成绩4："+QString::number(student->getScore4()));
    ui->pingjun->setText("平均分："+QString::number(student->getAverageScore()));
}

void Dialog::on_pushButton_2_clicked()
{
    this->close();
}

