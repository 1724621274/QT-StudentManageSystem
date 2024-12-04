#include "login.h"
#include "ui_login.h"
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    QIcon icon(":/img/icons/logo.png");
    this->setWindowIcon(icon);
    this->setWindowTitle("学生信息管理系统——登录");
    readkey(keyfilename.toStdString(),&root_key);//读取普通管理员账号
}

login::~login()
{
    //如果admin1不为空则delete admin1
    if(admin1!=nullptr)delete admin1;
    //如果home不为空则delete home
    if(home!=nullptr)delete home;
    delete ui;
}

bool login::savekey(const std::string& filename,const std::map<QString,QString> &key) {
    std::ofstream file(filename);
    if (file.is_open()) {
       for(auto &it : key)
       {
           if(it.first=="admin")continue;//不保存内置超级管理员账号到文件
           file << des_encrypt(it.first.toStdString(),deskey.toStdString()) << " "<<des_encrypt(it.second.toStdString(),deskey.toStdString())<<" "<<std::endl;
       }
       file.close();
    } else {
        qDebug() << "无法打开文件进行保存" << endl;
        return false;
    }
    return true;
}

// 从文件读取学生信息
bool login::readkey(const std::string& filename,std::map<QString,QString> *key) {
    std::ifstream file(filename);
    if (file.is_open()) {
        while(true){
            std::string r_key , r_id;
            file>>r_id>>r_key;
            if (file.eof()) {
                break;
            }
            if(r_key.size()!=64||r_id.size()!=64)continue;//如果读取的长度不为64，则代表密钥缺失，跳转下一组账号密码
            r_id=des_decrypt(r_id,deskey.toStdString());
            if(r_id.c_str()==QString("admin"))continue;//检测到内置超级管理员账号则不存储
            r_key=des_decrypt(r_key,deskey.toStdString());
            (*key)[r_id.c_str()]=r_key.c_str();//添加到容器中
        }
        file.close();
    }else return false;
    return true;
}

bool login::is_give_chars(const QChar c){
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

void login::on_pushButton_login_clicked()
{
    if(root_key[ui->lineEdit_id->text()]!=ui->lineEdit_password->text()||ui->lineEdit_password->text().size()==0||ui->lineEdit_id->text().size()==0)
    {
        ui->label_hello->setText("账号或者密码错误！！！！");
        ui->label_hello->setStyleSheet("color : red");
        return;
    }

    if(ui->lineEdit_id->text()==QString("admin"))
    {
        this->admin1=new admin();
        this->admin1->show();
        this->hide();
        ui->label_hello->setText("");
        ui->lineEdit_id->setText("");
        ui->lineEdit_password->setText("");
        connect(admin1,&admin::join_home,this,&login::showhome);
        connect(admin1,&admin::delete_admin_successfuly,this,&login::emitsavekey);
        connect(admin1->getadd(),&add_admin::add_admin_successfuly,this,&login::emitsavekey);
    }else{
        this->home=new Widget();//为主页面申请空间并将地址给home
        this->home->show();//显示主页面
        this->hide();//隐藏登录页面
        ui->label_hello->setText("");
        ui->lineEdit_id->setText("");
        ui->lineEdit_password->setText("");
        connect(home,&Widget::outButton_clicked,this,&login::showlogin);
    }
}


void login::on_pushButton_tuichu_clicked()
{
    this->close();//关闭
}


void login::on_lineEdit_password_returnPressed()
{
    on_pushButton_login_clicked();
}


void login::on_lineEdit_id_returnPressed()
{
    on_pushButton_login_clicked();
}

void login::showlogin(){
    this->show();
}

void login::showhome(){
    this->admin1->close();
    this->home=new Widget();
    this->home->show();
    connect(home,&Widget::outButton_clicked,this,&login::showlogin);//连接信号
}

void login::emitsavekey()
{
    savekey(keyfilename.toStdString(),root_key);
}

void login::on_lineEdit_id_textChanged(const QString &arg1)
{
    QString l="";
    for(auto &it : arg1)
    {
        if(is_give_chars(it))l=l+it;
        else
        {
            ui->lineEdit_id->setText(l);
            ui->label_hello->setText("不能输入中文字符及空格");
            ui->label_hello->setStyleSheet("color : red");
            return;
        }
    }
    ui->label_hello->setText("");
}


void login::on_lineEdit_password_textChanged(const QString &arg1)
{
    QString l="";
    for(auto &it : arg1)
    {
        if(is_give_chars(it))l=l+it;
        else
        {
            ui->lineEdit_password->setText(l);
            ui->label_hello->setText("不能输入中文字符及空格");
            ui->label_hello->setStyleSheet("color : red");
            return;
        }
    }
    ui->label_hello->setText("");
}

