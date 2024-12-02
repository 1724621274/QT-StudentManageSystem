#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "widget.h"
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
    bool savekey(const std::string& filename,const QString& key);
    QString readkey(const std::string& filename);
    ~login();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_tuichu_clicked();

    void on_lineEdit_password_returnPressed();

    void on_lineEdit_id_returnPressed();

private:
    Ui::login *ui;
    Widget *home=nullptr;//定义主界面指针
};

#endif // LOGIN_H
