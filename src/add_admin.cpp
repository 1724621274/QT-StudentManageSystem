#include "add_admin.h"
#include "ui_add_admin.h"

add_admin::add_admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_admin)
{
    ui->setupUi(this);
}

add_admin::~add_admin()
{
    delete ui;
}

bool add_admin::is_give_chars(const QChar c){
    //如果是字母和数字直接返回1
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9'))return true;
    //判断特殊字符
    QString chars="()`!@#$%^&*_-+=|{}[]:;'<>,.?";
    for(auto &it : chars)
    {
        if(c==it)return true;
    }
    return false;
}

void add_admin::show1()
{
    this->show();
    ui->tishi->setText("");
    ui->lineEdit_id->setText("");
    ui->lineEdit_password->setText("");
}

void add_admin::on_pushButton_clicked()
{
    if(ui->lineEdit_id->text().size()==0)
    {
        ui->tishi->setText("账号不能为空！！");
        ui->tishi->setStyleSheet("color :red");
        return;
    }
    if(ui->lineEdit_password->text().size()==0)
    {
        ui->tishi->setText("密码不能为空！！");
        ui->tishi->setStyleSheet("color :red");
        return;
    }
    if(root_key.count(ui->lineEdit_id->text()))
    {
        ui->tishi->setText("账号已经存在！！");
        ui->tishi->setStyleSheet("color :red");
        return;
    }
    root_key[ui->lineEdit_id->text()]=ui->lineEdit_password->text();
    ui->tishi->setText("账号添加成功！！");
    ui->tishi->setStyleSheet("color :green");
    emit add_admin_successfuly();
}


void add_admin::on_pushButton_2_clicked()
{
    this->close();
}


void add_admin::on_lineEdit_id_textChanged(const QString &arg1)
{
    QString l="";
    for(auto &it : arg1)
    {
        if(is_give_chars(it))l=l+it;
        else
        {
            ui->lineEdit_id->setText(l);
            ui->tishi->setText("不能输入中文字符及空格");
            ui->tishi->setStyleSheet("color : red");
            return;
        }
    }
    ui->tishi->setText("");
}


void add_admin::on_lineEdit_password_textChanged(const QString &arg1)
{
    QString l="";
    for(auto &it : arg1)
    {
        if(is_give_chars(it))l=l+it;
        else
        {
            ui->lineEdit_password->setText(l);
            ui->tishi->setText("不能输入中文字符及空格");
            ui->tishi->setStyleSheet("color : red");
            return;
        }
    }
    ui->tishi->setText("");
}

