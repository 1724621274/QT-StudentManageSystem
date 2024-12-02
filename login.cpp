#include "login.h"
#include "ui_login.h"

QString r_key;
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    QIcon icon(":/img/icons/logo.png");
    this->setWindowIcon(icon);
    this->setWindowTitle("学生信息管理系统——登录");
    root_key["admin"]="12345678";//默认管理员账号
    r_key=readkey(keyfilename.toStdString());
    if(r_key.size())
    {
        qDebug()<<"读取成功!!!"<<endl<<"key："<<r_key;
    }
    else qDebug()<<"数据读取失败";

    if( savekey(keyfilename.toStdString(),r_key) )qDebug()<<"保存成功！！！！";
    else qDebug()<<"保存失败！！！！";
    //connect(home,&Widget::childWidgetClosed,this,&login::xxxx);
}

login::~login()
{
    //如果home不为空则delete home
    if(home!=nullptr)delete home;
    delete ui;
}

bool login::savekey(const std::string& filename,const QString& key) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << des_encrypt(key.toStdString(),deskey.toStdString()) << " ";
        file.close();
    } else {
        qDebug() << "无法打开文件进行保存" << endl;
        return false;
    }
    return true;
}

// 从文件读取学生信息
QString login::readkey(const std::string& filename) {
    std::ifstream file(filename);
    std::string r_key;
    if (file.is_open()) {
        file>>r_key;
        file.close();
    }
    if(r_key.size()!=64)return "";//如果加密的DES密文长度不正确那就直接返回空密码
    return des_decrypt(r_key,deskey.toStdString()).c_str();
}


void login::on_pushButton_login_clicked()
{
    if(root_key[ui->lineEdit_id->text()]!=ui->lineEdit_password->text()||ui->lineEdit_id->text().size()==0||ui->lineEdit_id->text().size()==0)
    {
        ui->label_hello->setText("账号或者密码错误！！！！");
        ui->label_hello->setStyleSheet("color : red");
        return;
    }
    this->home=new Widget();//为主页面申请空间并将地址给home
    this->home->show();//显示主页面
    this->hide();//隐藏登录页面
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

