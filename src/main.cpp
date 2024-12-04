/*
作者：黎忠海
完成时间：2024/12/3
实现功能：
学生管理系统
功能：学生的添加、删除、查找、筛选、排序、导出TXT、导入TXT、超级管理员对管理员账户的添加与删除
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
QString filewenjian="data";//定义全局变量filewenjian表示文件路径
QString filename=filewenjian+"/student.des";//定义全局变量filename表示学生数据存储文件
QString keyfilename=filewenjian+"/key.des";//定义全局变量keyfilename表示管理员账户存储文件
QString deskey="1234567812345678";//DES密钥
std::map<QString,QString> root_key;//管理员账户存储容器
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //检查数据存放的文件夹是否存在，不存在则创建
    stu.CreateFolder(filewenjian);
    root_key["admin"]="12345678";//超级管理员账号
    login lg;
    lg.show();
    return a.exec();
}
