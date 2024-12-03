#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include "home.h"
#include "add_admin.h"
#include <QTableWidget>
#include <QHeaderView>
extern QString keyfilename;
extern std::map<QString,QString> root_key;
namespace Ui {
class admin;
}

class admin : public QWidget
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    Widget * gethome();
    void setColumnAlignment(QTableWidget *tableWidget, int columnIndex, Qt::Alignment alignment);
    add_admin * getadd();
    ~admin();
    void disp();

signals:
    void join_home();
    void delete_admin_successfuly();

private slots:
    void on_join_home_clicked();

    void on_add_admin_clicked();

    void on_delete_admin_clicked();

private:
    Ui::admin *ui;
    Widget *home=nullptr;
    add_admin *add=new add_admin();
};

#endif // ADMIN_H
