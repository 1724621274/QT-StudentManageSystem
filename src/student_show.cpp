#include "student_show.h"
#include "ui_student_show.h"

Dialog::Dialog(QWidget *parent): QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    //设置数据验证器：最多两位小数
    validator = new QDoubleValidator(0.0, 100.0, 2);
    ui->update_cj1->setValidator(validator);
    ui->update_cj2->setValidator(validator);
    ui->update_cj3->setValidator(validator);
    ui->update_cj4->setValidator(validator);
}

Dialog::~Dialog()
{
    delete ui;
    delete validator;
}


void Dialog::dispdata(Student &student){
    showstu=student;
    ui->name->setText("姓名："+student.getName());
    ui->xingbie->setText("性别："+stu.gender_int_to_str[student.getGender()]);
    ui->xuehao->setText("学号："+QString::number(student.getStudentId()));
    ui->nianji->setText("年级："+QString::number(student.getGrade()));
    ui->zhuanye->setText("专业："+stu.major_int_to_str[student.getMajorId()]);
    ui->banji->setText("班级："+QString::number(student.getClassNumber()));
    ui->qinshi->setText("寝室："+QString::number(student.getDormitoryNumber()));
    ui->chuanghao->setText("床号："+QString::number(student.getBedNumber()));
    ui->cj1->setText("成绩1："+QString::number(student.getScore1()));
    ui->cj2->setText("成绩2："+QString::number(student.getScore2()));
    ui->cj3->setText("成绩3："+QString::number(student.getScore3()));
    ui->cj4->setText("成绩4："+QString::number(student.getScore4()));
    ui->pingjun->setText("平均分："+QString::number(student.getAverageScore()));
}

void Dialog::on_pushButton_2_clicked()
{
    this->close();
}


void Dialog::on_pushButton_clicked()
{
    ui->tishi->setText("");
    ui->biaoti->setText("修改学号:"+QString::number(showstu.getStudentId())+"学生信息");
    ui->stackedWidget->setCurrentIndex(1);

    ui->update_name->setText(showstu.getName());
    ui->update_xingbie->setCurrentIndex(showstu.getGender()?0:1);
    ui->update_xuehao->setText("学号："+QString::number(showstu.getStudentId()));
    ui->update_nianji->setText(QString::number(showstu.getGrade()));

    ui->update_zhuanye->setCurrentIndex(showstu.getMajorId()-1);
    ui->update_banji->setText(QString::number(showstu.getClassNumber()));
    ui->update_qinshi->setText(QString::number(showstu.getDormitoryNumber()));
    ui->update_chuanghao->setCurrentIndex(showstu.getBedNumber()-1);

    ui->update_cj1->setText(QString::number(showstu.getScore1()));
    ui->update_cj2->setText(QString::number(showstu.getScore2()));
    ui->update_cj3->setText(QString::number(showstu.getScore3()));
    ui->update_cj4->setText(QString::number(showstu.getScore4()));
    ui->update_pingjun->setText("平均分："+QString::number(showstu.getAverageScore()));
}


void Dialog::on_pushButton_6_clicked()
{
    ui->tishi->setText("");
    ui->biaoti->setText("学生个人信息显示");
    ui->stackedWidget->setCurrentIndex(0);
}


void Dialog::on_pushButton_5_clicked()
{
    //判断有没有填完整信息
    if(ui->update_name->text()==""||ui->update_nianji->text()==""||
       ui->update_banji->text()==""||ui->update_qinshi->text()==""||
       ui->update_cj1->text()==""||ui->update_cj2->text()==""||
       ui->update_cj3->text()==""||ui->update_cj4->text()=="")
    {
        ui->tishi->setStyleSheet("color : red");
        ui->tishi->setText("请将数据填写完整");
        return;
    }
    bool xb=ui->update_xingbie->currentIndex()==0?1:0;
    Student updatestu(ui->update_name->text(),xb,showstu.getStudentId(),
                      ui->update_nianji->text().toInt(),ui->update_zhuanye->currentIndex()+1,
                      ui->update_banji->text().toInt(),ui->update_qinshi->text().toInt(),
                      ui->update_chuanghao->currentIndex()+1,ui->update_cj1->text().toDouble(),
                      ui->update_cj2->text().toDouble(),ui->update_cj3->text().toDouble(),
                      ui->update_cj4->text().toDouble());

    stu.updateStudent(showstu.getStudentId(),updatestu);
    ui->tishi->setStyleSheet("color : green");
    ui->tishi->setText("信息修改成功！！！");
    ui->biaoti->setText("学生个人信息显示");
    ui->stackedWidget->setCurrentIndex(0);
    dispdata(updatestu);
    emit updatestudent();//发送修改成功信号
}


void Dialog::on_update_cj1_textChanged(const QString &arg1)
{
    if(arg1.toDouble()>100||arg1.toDouble()<0)
    {
        //ui->addcj1->setStyleSheet("color: red;");
        ui->update_cj1->setText("");
        QMessageBox::warning(this, "输入错误", "输入格式不符合要求，请输入0~100的小数");
    }
    ui->update_pingjun->setText("平均分:"+QString::number((ui->update_cj1->text().toDouble()+ui->update_cj2->text().toDouble()+ui->update_cj3->text().toDouble()+ui->update_cj4->text().toDouble())/4.0));
}


void Dialog::on_update_cj2_textChanged(const QString &arg1)
{
    if(arg1.toDouble()>100||arg1.toDouble()<0)
    {
        //ui->addcj1->setStyleSheet("color: red;");
        ui->update_cj2->setText("");
        QMessageBox::warning(this, "输入错误", "输入格式不符合要求，请输入0~100的小数");
    }
    ui->update_pingjun->setText("平均分:"+QString::number((ui->update_cj1->text().toDouble()+ui->update_cj2->text().toDouble()+ui->update_cj3->text().toDouble()+ui->update_cj4->text().toDouble())/4.0));
}


void Dialog::on_update_cj3_textChanged(const QString &arg1)
{
    if(arg1.toDouble()>100||arg1.toDouble()<0)
    {
        //ui->addcj1->setStyleSheet("color: red;");
        ui->update_cj3->setText("");
        QMessageBox::warning(this, "输入错误", "输入格式不符合要求，请输入0~100的小数");
    }
    ui->update_pingjun->setText("平均分:"+QString::number((ui->update_cj1->text().toDouble()+ui->update_cj2->text().toDouble()+ui->update_cj3->text().toDouble()+ui->update_cj4->text().toDouble())/4.0));
}


void Dialog::on_update_cj4_textChanged(const QString &arg1)
{
    if(arg1.toDouble()>100||arg1.toDouble()<0)
    {
        //ui->addcj1->setStyleSheet("color: red;");
        ui->update_cj4->setText("");
        QMessageBox::warning(this, "输入错误", "输入格式不符合要求，请输入0~100的小数");
    }
    ui->update_pingjun->setText("平均分:"+QString::number((ui->update_cj1->text().toDouble()+ui->update_cj2->text().toDouble()+ui->update_cj3->text().toDouble()+ui->update_cj4->text().toDouble())/4.0));
}

