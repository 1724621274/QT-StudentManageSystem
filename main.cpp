/*
作者：黎忠海
完成时间：2024/11/27
实现功能：
学生管理系统
功能：学生的添加、删除、查找、筛选、排序、导出TXT、导入TXT
学生信息加密保存在本地
加解密算法：DES

*/
#include <QApplication>
#include <QTextCodec>
#include "student.h"
#include "login.h"
bool fangshi[13]={0};//排序方式 0升序 1降序
int stuID;//定义全局变量stuID
StudentManager stu;//定义全局变量stu
QString filename="data/student.des";//定义全局变量filename
QString keyfilename="data/key.des";//定义全局变量keyfilename
QString deskey="1234567812345678";//DES密钥
std::map<QString,QString> root_key;//管理员账户存储容器
int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    //a.setWindowIcon(icon);
    login lg;
    lg.show();
    return a.exec();
}
