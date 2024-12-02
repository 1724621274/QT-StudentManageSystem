#ifndef WIDGET_H
#define WIDGET_H
#include <QTableWidget>
#include <QWidget>
#include <QMessageBox>
#include <QResizeEvent>
#include "student.h"
#include "QDebug"
#include "dialog.h"
#include <QTableWidget>
#include <QHeaderView>
#include <QStackedWidget>
#include <QFileDialog>
#include <QFont>
#include <QIcon>
#include <QScreen>
extern bool fangshi[13];
extern int stuID;//声明全局变量stuID
extern StudentManager stu;//声明全局变量stu
extern QString filename;//声明全局变量filename

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);



    QDoubleValidator* validator = new QDoubleValidator(this);
    /**
     * 学生信息显示在表格中
     */
    void studentdisp(std::vector<Student> students,QTableWidget *tableWidget);

    /**
     * 设置一列的单元格文字对齐方式
    */
    void setColumnAlignment(QTableWidget *tableWidget, int columnIndex, Qt::Alignment alignment) ;
    ~Widget();

signals:
    void windowSizeChanged(QTableWidget *tableWidget);

private slots:

    void onHeaderSectionClicked(int logicalIndex);

    void on_readfile_clicked();

    void on_savefile_clicked();

    void on_pushButton_2_clicked();

    void on_dispButton_clicked();

    void on_pushButton_7_clicked();

    void on_addButton_clicked();

    void on_pushButton_10_clicked();

    void on_addcj1_textChanged(const QString &arg1);

    void on_addcj2_textChanged(const QString &arg1);

    void on_addcj3_textChanged(const QString &arg1);

    void on_addcj4_textChanged(const QString &arg1);

    void liekuan(QTableWidget *tableWidget);

    void on_pushButton_3_clicked();

    void on_saveButton_clicked();

    void on_pushButton_4_clicked();

    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_shaixuanqi_returnPressed();

    void on_chazhaoqi_returnPressed();

private:
    //重写resizeEvent函数实现表格根据窗口实时变换
    void resizeEvent(QResizeEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
    Ui::Widget *ui;
};
#endif // WIDGET_H
