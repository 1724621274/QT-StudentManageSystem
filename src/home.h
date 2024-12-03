#ifndef HOME_H
#define HOME_H
#include <QTableWidget>
#include <QWidget>
#include <QMessageBox>
#include <QResizeEvent>
#include "student.h"
#include "QDebug"
#include "student_show.h"
#include <QTableWidget>
#include <QHeaderView>
#include <QStackedWidget>
#include <QFileDialog>
#include <QFont>
#include <QIcon>
#include <QScreen>
extern bool fangshi[13];
extern int stuID;//澹版槑鍏ㄥ眬鍙橀噺stuID
extern StudentManager stu;//澹版槑鍏ㄥ眬鍙橀噺stu
extern QString filename;//澹版槑鍏ㄥ眬鍙橀噺filename
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
     * 瀛︾敓淇℃伅鏄剧ず鍦ㄨ〃鏍间腑
     */
    void studentdisp(std::vector<Student> students,QTableWidget *tableWidget);

    /**
     * 璁剧疆涓�鍒楃殑鍗曞厓鏍兼枃瀛楀榻愭柟寮�    */
    void setColumnAlignment(QTableWidget *tableWidget, int columnIndex, Qt::Alignment alignment) ;
    ~Widget();

signals:
    void windowSizeChanged(QTableWidget *tableWidget);
    void outButton_clicked();

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

    void on_outButton_clicked();

private:
    //閲嶅啓resizeEvent鍑芥暟瀹炵幇琛ㄦ牸鏍规嵁绐楀彛瀹炴椂鍙樻崲
    bool guanbiflag=false;//关闭标志，用于判断是否是返回login界面
    void resizeEvent(QResizeEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
    Ui::Widget *ui;
};
#endif // HOME_H
