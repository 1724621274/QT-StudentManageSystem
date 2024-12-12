#include "add_student.h"
#include "ui_add_student.h"

add_student::add_student(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_student)
{
    ui->setupUi(this);
    QIcon icon(":/img/icons/logo.png");
    this->setWindowIcon(icon);
    this->setModal(true);
    //设置数据验证器：最多两位小数
    validator = new QDoubleValidator(0.0, 100.0, 2);
    ui->addcj1->setValidator(validator);
    ui->addcj2->setValidator(validator);
    ui->addcj3->setValidator(validator);
    ui->addcj4->setValidator(validator);
}

add_student::~add_student()
{
    delete ui;
    delete validator;
}

void add_student::on_pushButton_fanhui_clicked()
{
    this->close();
}


void add_student::on_pushButton_ok_clicked()
{
    //性别标识
    bool xb=false;

    //判断有没有填完整信息
    if(ui->addname->text()==""||ui->addxingbie->currentIndex()==0||
       ui->addnianji->text()==""||ui->addxuehao->text()==""||
       ui->addbanji->text()==""||ui->addzhuanye->currentIndex()==0||
       ui->addqinshi->text()==""||ui->addchuanghao->currentIndex()==0||
       ui->addcj1->text()==""||ui->addcj2->text()==""||
       ui->addcj3->text()==""||ui->addcj4->text()=="")
    {
        ui->tishi->setStyleSheet("color : red");
        ui->tishi->setText("请将数据填写完整");
        return;
    }

    //判断当前学号是否存在
    if(stu.findStudentByStudentId(ui->addxuehao->text().toLongLong())!=nullptr)
    {
        ui->tishi->setStyleSheet("color : red");
        ui->tishi->setText("当前学号已经存在");
        return;
    }

    //判别性别
    if(ui->addxingbie->currentIndex()==1)xb=true;
    else if(ui->addxingbie->currentIndex()==2)xb=false;
    Student student(ui->addname->text(),xb,ui->addxuehao->text().toLongLong(),
                    ui->addnianji->text().toInt(),ui->addzhuanye->currentIndex(),
                    ui->addbanji->text().toInt(),ui->addqinshi->text().toInt(),
                    ui->addchuanghao->currentIndex(),ui->addcj1->text().toDouble(),
                    ui->addcj2->text().toDouble(),ui->addcj3->text().toDouble(),
                    ui->addcj4->text().toDouble());

    //添加到stu中
    stu.addStudent(student);

    //提示添加成功
    ui->tishi->setStyleSheet("color : green");
    ui->tishi->setText("学号:"+ui->addxuehao->text()+" 添加成功");

    //清空输入文本
    ui->addname->setText("");
    ui->addxingbie->setCurrentIndex(0);
    ui->addnianji->setText("");
    ui->addxuehao->setText("");
    ui->addbanji->setText("");
    ui->addzhuanye->setCurrentIndex(0);
    ui->addqinshi->setText("");
    ui->addchuanghao->setCurrentIndex(0);
    ui->addcj1->setText("");
    ui->addcj2->setText("");
    ui->addcj3->setText("");
    ui->addcj4->setText("");
}

//成绩输入框槽函数1
void add_student::on_addcj1_textChanged(const QString &arg1)
{
    if(arg1.toDouble()>100||arg1.toDouble()<0)
    {
        //ui->addcj1->setStyleSheet("color: red;");
        ui->addcj1->setText("");
        QMessageBox::warning(this, "输入错误", "输入格式不符合要求，请输入0~100的小数");
    }
}

//成绩输入框槽函数2
void add_student::on_addcj2_textChanged(const QString &arg1)
{
    if(arg1.toDouble()>100||arg1.toDouble()<0)
    {
        //ui->addcj1->setStyleSheet("color: red;");
        ui->addcj2->setText("");
        QMessageBox::warning(this, "输入错误", "输入格式不符合要求，请输入0~100的小数");
    }
}

//成绩输入框槽函数3
void add_student::on_addcj3_textChanged(const QString &arg1)
{
    if(arg1.toDouble()>100||arg1.toDouble()<0)
    {
        //ui->addcj1->setStyleSheet("color: red;");
        ui->addcj3->setText("");
        QMessageBox::warning(this, "输入错误", "输入格式不符合要求，请输入0~100的小数");
    }
}

//成绩输入框槽函数4
void add_student::on_addcj4_textChanged(const QString &arg1)
{
    if(arg1.toDouble()>100||arg1.toDouble()<0)
    {
        //ui->addcj1->setStyleSheet("color: red;");
        ui->addcj4->setText("");
        QMessageBox::warning(this, "输入错误", "输入格式不符合要求，请输入0~100的小数");
    }
}
