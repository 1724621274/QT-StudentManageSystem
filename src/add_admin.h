#ifndef ADD_ADMIN_H
#define ADD_ADMIN_H

#include <QDialog>
#include <QDebug>
#include <QChar>
extern std::map<QString,QString> root_key;//管理员账户存储容器
namespace Ui {
class add_admin;
}

class add_admin : public QDialog
{
    Q_OBJECT

public:
    explicit add_admin(QWidget *parent = nullptr);
    bool is_give_chars(const QChar c);
    void show1();
    ~add_admin();

signals:
    void add_admin_successfuly();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_id_textChanged(const QString &arg1);

    void on_lineEdit_password_textChanged(const QString &arg1);

private:
    Ui::add_admin *ui;
};

#endif // ADD_ADMIN_H
