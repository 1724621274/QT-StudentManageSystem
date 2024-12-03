#include "admin.h"
#include "ui_admin.h"

admin::admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    disp();
}

admin::~admin()
{
    if(add!=nullptr)delete add;
    if(home!=nullptr)delete home;
    delete ui;
}
//设置一列的单元格文字对齐方式
void admin::setColumnAlignment(QTableWidget *tableWidget, int columnIndex, Qt::Alignment alignment) {
    for (int row = 0; row < tableWidget->rowCount(); ++row) {
        QTableWidgetItem *item = tableWidget->item(row, columnIndex);
        if (item) {
            item->setTextAlignment(alignment);
        }
    }
}

add_admin * admin::getadd(){
    return add;
}

void admin::disp()
{
    int i = 0;
    ui->tableWidget_admin->clearContents();//清表格数据
    ui->tableWidget_admin->setRowCount(0);//设置行数为0
    //stu.readFromFile("C://Users//lizhonghai//Desktop//student.txt");
    ui->tableWidget_admin->horizontalHeader()->setVisible(true);
    ui->tableWidget_admin->verticalHeader()->setVisible(false);
    ui->tableWidget_admin->setColumnCount(3);//设置表格列数
    ui->tableWidget_admin->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//平均拉伸
    //ui->tableWidget_admin->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);//根据内容调整宽度
    //ui->tableWidget_admin->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->tableWidget_admin->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选中一行
    ui->tableWidget_admin->setSelectionMode(QAbstractItemView::SingleSelection);//设置每次只能选中一个单元格
    ui->tableWidget_admin->horizontalHeader()->setFont(QFont("楷体",12));//表头字体
    ui->tableWidget_admin->setAlternatingRowColors(true);//设置表格每行交替颜色
    ui->tableWidget_admin->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
    QStringList header;
    header<<"序号"<<"账号"<<"密码";
    ui->tableWidget_admin->setHorizontalHeaderLabels(header);//设置表头显示文本

    for(auto &it : root_key ){
        if(it.first=="admin")continue;
        ui->tableWidget_admin->insertRow(i);//添加行
        QTableWidgetItem *item;
        item=new QTableWidgetItem(QString::number(i+1));
        ui->tableWidget_admin->setItem(i,0,item);//设置序号
        item=new QTableWidgetItem(it.first);
        ui->tableWidget_admin->setItem(i,1,item);//设置账号
        item=new QTableWidgetItem(it.second);
        ui->tableWidget_admin->setItem(i++,2,item);//设置密码
    }
    setColumnAlignment(ui->tableWidget_admin,0,Qt::AlignCenter);//垂直居中水平居中对齐
    setColumnAlignment(ui->tableWidget_admin,1,Qt::AlignVCenter|Qt::AlignLeft);//垂直居中水平左对齐
    setColumnAlignment(ui->tableWidget_admin,2,Qt::AlignVCenter|Qt::AlignLeft);//垂直居中水平左对齐
}
void admin::on_join_home_clicked()
{
    emit join_home();
}

void admin::on_add_admin_clicked()
{
    add->setModal(true);
    add->show1();
    connect(add,&add_admin::add_admin_successfuly,this,&admin::disp);
}


void admin::on_delete_admin_clicked()
{
    if(root_key.size())
    {
        if(ui->tableWidget_admin->currentRow()!=-1)
        {
            if(QMessageBox::warning(this,"删除学生","要删除-"+ui->tableWidget_admin->item(ui->tableWidget_admin->currentRow(),1)->text()+"-吗",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes){
                //删除root_key中键值为当前选中行的第二列内容（账号）的元素
                root_key.erase(ui->tableWidget_admin->item(ui->tableWidget_admin->currentRow(),1)->text());
                emit delete_admin_successfuly();
                disp();
            }
        }
    }
}

