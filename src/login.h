#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "home.h"
#include "admin.h"
#include <QChar>
#include <map>
extern QString keyfilename;
extern std::map<QString,QString> root_key;
namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    bool savekey(const std::string& filename,const std::map<QString,QString> &key);
    bool readkey(const std::string& filename,std::map<QString,QString> *key);
    bool is_give_chars(const QChar c);
    ~login();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_tuichu_clicked();

    void on_lineEdit_password_returnPressed();

    void on_lineEdit_id_returnPressed();

    void showlogin();//显示login

    void showhome();//从admin显示home

    void emitsavekey();//add_admin添加管理员账户处理槽函数

    void on_lineEdit_id_textChanged(const QString &arg1);

    void on_lineEdit_password_textChanged(const QString &arg1);

private:
    Ui::login *ui;
    Widget *home=nullptr;//定义主界面指针
    admin *admin1=nullptr;//定义管理员界面指针
};

#endif // LOGIN_H
