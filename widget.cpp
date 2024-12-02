#include "widget.h"
#include "ui_widget.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);//显示主页
    connect(ui->tableWidget->horizontalHeader(), &QHeaderView::sectionClicked, this, &Widget::onHeaderSectionClicked);//连接点击表头的信号
    connect(this, &Widget::windowSizeChanged, this, &Widget::liekuan);//连接窗口改变的信号
    this->setWindowTitle("学生信息管理系统");
    QIcon icon(":/img/icons/logo.png");
    this->setWindowIcon(icon);
    stu.readDesFromFile(filename.toStdString());
//    QFont font;
//    QScreen *screen = QGuiApplication::primaryScreen();
//    QRect screenGeometry = screen->geometry();
//    int height = screenGeometry.height();
//    if (height < 720) {
//        font.setFamily("楷体");  // 设置字体家族
//        font.setPointSize(16);
//    } else if (height >= 720 && height < 1080) {
//        font.setFamily("楷体");  // 设置字体家族
//        font.setPointSize(20);
//    } else {
//        font.setFamily("楷体");  // 设置字体家族
//        font.setPointSize(28);
//    }
//    ui->label_2->setFont(font);
}

Widget::~Widget()
{
    delete ui;
    delete validator ;
}

void Widget::resizeEvent(QResizeEvent *event)
{
    if(ui->stackedWidget->currentIndex()==1)emit windowSizeChanged(ui->tableWidget);//处于页面1的时候发送信号
    QWidget::resizeEvent(event);
}

void Widget::closeEvent(QCloseEvent *event)
{


    if(this->windowTitle()=="学生信息管理系统"){
        QMessageBox tishi;
        tishi.setText("需要保存文件数据吗?");
        tishi.setIcon(QMessageBox::Question);
        tishi.setWindowTitle("退出系统");
        QIcon icon(":/img/icons/logo.png");
        tishi.setWindowIcon(icon);
        // 创建按钮并添加到列表
        QList<QAbstractButton*> buttonList;
        QAbstractButton* saveButton = tishi.addButton(QMessageBox::Save);
        QAbstractButton* yesButton = tishi.addButton(QMessageBox::Yes);
        QAbstractButton* noButton = tishi.addButton(QMessageBox::No);
        saveButton->setText("保存并退出");
        yesButton->setText("仅退出");
        noButton->setText("取消");
        buttonList.append(saveButton);
        buttonList.append(yesButton);
        buttonList.append(noButton);
        // 按照想要的顺序从列表中取出按钮并重新添加到消息框
        for (QAbstractButton* button : buttonList) {
            tishi.addButton(button, QMessageBox::NoRole);
        }
        tishi.exec();
        if(tishi.clickedButton()==saveButton)
        {

            stu.saveDesToFile(filename.toStdString());
            event->accept();
        }
        else if(tishi.clickedButton()==yesButton)
        {
            event->accept();
        }
        else event->ignore(); //默认情况下接收关闭信号，关闭窗体
    }
}


//列宽处理函数
void Widget::liekuan(QTableWidget *tableWidget){
    //qDebug()<<"表格总宽度："<<tableWidget->width();
    int kuan[14];
    std::fill_n(kuan, 14, ui->tableWidget->width()/16);
    kuan[3]*=2;
    kuan[5]*=2;
    kuan[13]=tableWidget->width()-kuan[0]*15-2;//-2是因为两边边框各占1个宽度
    for(int i = 0 ; i < 14 ; i++)tableWidget->setColumnWidth(i,kuan[i]);
}

//学生信息显示在表格中
void Widget::studentdisp(std::vector<Student> students,QTableWidget *tableWidget)
{
    int i = 0;
    tableWidget->clearContents();//清表格数据
    tableWidget->setRowCount(0);//设置行数为0
    //stu.readFromFile("C://Users//lizhonghai//Desktop//student.txt");
    tableWidget->horizontalHeader()->setVisible(true);
    tableWidget->verticalHeader()->setVisible(false);
    tableWidget->setColumnCount(14);//设置表格行数
    //ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//平均拉伸
    //ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);//根据内容调整宽度
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选中一行
    tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//设置每次只能选中一个单元格
    tableWidget->horizontalHeader()->setFont(QFont("楷体",12));//表头字体
    tableWidget->setAlternatingRowColors(true);//设置表格每行交替颜色
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
    QStringList header;
    header<<"序号"<<"姓名"<<"性别"<<"学号"<<"年级"<<"专业"<<"班级"<<"寝室"<<"床号"<<"专业1"<<"专业2"<<"专业3"<<"专业4"<<"平均分";
    tableWidget->setHorizontalHeaderLabels(header);//设置表头显示文本
    liekuan(tableWidget);
    //ui->tableWidget->horizontalHeader()->setMinimumSectionSize(kuan[3]);
    for(auto &student:students)
    {
        tableWidget->insertRow(i);//添加行
        QTableWidgetItem *item;
        item=new QTableWidgetItem(QString::number(i+1));
        tableWidget->setItem(i,0,item);//设置序号
        item=new QTableWidgetItem(student.getName());
        tableWidget->setItem(i,1,item);//设置i行1列内容为item
        item=new QTableWidgetItem(stu.gender_int_to_str[student.getGender()]);
        tableWidget->setItem(i,2,item);
        item=new QTableWidgetItem(QString::number(student.getStudentId()));
        tableWidget->setItem(i,3,item);
        item=new QTableWidgetItem(QString::number(student.getGrade()));
        tableWidget->setItem(i,4,item);
        item=new QTableWidgetItem(stu.major_int_to_str[student.getMajorId()]);
        tableWidget->setItem(i,5,item);
        item=new QTableWidgetItem(QString::number(student.getClassNumber()));
        tableWidget->setItem(i,6,item);
        item=new QTableWidgetItem(QString::number(student.getDormitoryNumber()));
        tableWidget->setItem(i,7,item);
        item=new QTableWidgetItem(QString::number(student.getBedNumber()));
        tableWidget->setItem(i,8,item);
        item=new QTableWidgetItem(QString::number(student.getScore1()));
        tableWidget->setItem(i,9,item);
        item=new QTableWidgetItem(QString::number(student.getScore2()));
        tableWidget->setItem(i,10,item);
        item=new QTableWidgetItem(QString::number(student.getScore3()));
        tableWidget->setItem(i,11,item);
        item=new QTableWidgetItem(QString::number(student.getScore4()));
        tableWidget->setItem(i,12,item);
        item=new QTableWidgetItem(QString::number(student.getAverageScore()));
        tableWidget->setItem(i++,13,item);
    }

    for(int i = 0 ; i < 14 ; i++)setColumnAlignment(tableWidget,i,Qt::AlignCenter);//垂直居中水平居中对齐
    setColumnAlignment(tableWidget,5,Qt::AlignVCenter|Qt::AlignLeft);//垂直居中水平左对齐
}

//设置一列的单元格文字对齐方式
void Widget::setColumnAlignment(QTableWidget *tableWidget, int columnIndex, Qt::Alignment alignment) {
    for (int row = 0; row < tableWidget->rowCount(); ++row) {
        QTableWidgetItem *item = tableWidget->item(row, columnIndex);
        if (item) {
            item->setTextAlignment(alignment);
        }
    }
}

//读取本地加密文件
void Widget::on_readfile_clicked()
{
    //读取文件
    ui->savetishi->setText("系统本地数据加载成功！！！");
    ui->savetishi->setStyleSheet("color : green");
    studentdisp(stu.getstudent(),ui->tableWidget);
}

//保存到文件
void Widget::on_savefile_clicked()
{
    QString savefileName=QFileDialog::getSaveFileName(nullptr,"保存文件","","TXT(*.txt)");//"TXT(*.txt);;Excel(*.xlsx)"分隔类型用;;
    if(!savefileName.isEmpty()){
        if(stu.saveDesToFile(filename.toStdString())&&stu.saveToFile(savefileName.toStdString()))
        {
            ui->savetishi->setText("文件已经保存到："+savefileName+"中！");
            ui->savetishi->setStyleSheet("color: green");
        }
        else ui->savetishi->setText("");
    }
    else ui->savetishi->setText("");
}

//点击表头（排序）
void Widget::onHeaderSectionClicked(int logicalIndex)
{
    //logicalIndex：列序号
    switch(logicalIndex)
    {
        case 1:stu.sortByName(fangshi[logicalIndex-1]);break;
        case 2:stu.sortByGender(fangshi[logicalIndex-1]);break;
        case 3:stu.sortByStudentId(fangshi[logicalIndex-1]);break;
        case 4:stu.sortByGrade(fangshi[logicalIndex-1]);break;
        case 5:stu.sortByMajorId(fangshi[logicalIndex-1]);break;
        case 6:stu.sortByClassNumber(fangshi[logicalIndex-1]);break;
        case 7:stu.sortByDormitoryNumber(fangshi[logicalIndex-1]);break;
        case 8:stu.sortByBedNumber(fangshi[logicalIndex-1]);break;
        case 9:stu.sortByScore1(fangshi[logicalIndex-1]);break;
        case 10:stu.sortByScore2(fangshi[logicalIndex-1]);break;
        case 11:stu.sortByScore3(fangshi[logicalIndex-1]);break;
        case 12:stu.sortByScore4(fangshi[logicalIndex-1]);break;
        case 13:stu.sortByAverageScore(fangshi[logicalIndex-1]);break;
    }
    studentdisp(stu.getstudent(),ui->tableWidget);
    fangshi[logicalIndex-1]=!fangshi[logicalIndex-1];//取反 下一次点击交换排序方式
}

//回到主页
void Widget::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//页面1：显示学生信息
void Widget::on_dispButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->savetishi->setText("");
    ui->shaixuanqi->setText("");
    ui->chazhaoqi->setText("");
    studentdisp(stu.getstudent(),ui->tableWidget);//显示在表格

}

//回到主页
void Widget::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//页面2：添加学生信息
void Widget::on_addButton_clicked()
{
    ui->addname->setText("");
    ui->addxingbie->setCurrentIndex(0);
    ui->addnianji->setText("");
    ui->addxuehao->setText("");
    ui->addbanji->setText("");
    ui->addzhuanye->setCurrentIndex(0);
    ui->addqinshi->setText("");
    ui->addchuanghao->setCurrentIndex(0);
    ui->addcj1->setText("");
    ui->addcj2->setText("");
    ui->addcj3->setText("");
    ui->addcj4->setText("");

    validator->setRange(0,100,2);
    ui->addcj1->setValidator(validator);
    ui->addcj2->setValidator(validator);
    ui->addcj3->setValidator(validator);
    ui->addcj4->setValidator(validator);
    ui->stackedWidget->setCurrentIndex(2);
}

//页面2的添加学生按钮
void Widget::on_pushButton_10_clicked()
{
    bool xb=false;
    if(ui->addxingbie->currentIndex()==1)xb=true;
    Student student(ui->addname->text(),xb,ui->addxuehao->text().toLongLong(),ui->addnianji->text().toInt(),ui->addzhuanye->currentIndex(),ui->addbanji->text().toInt(),ui->addqinshi->text().toInt(),ui->addchuanghao->currentIndex(),ui->addcj1->text().toDouble(),ui->addcj2->text().toDouble(),ui->addcj3->text().toDouble(),ui->addcj4->text().toDouble());
    student.printInfo();
    stu.addStudent(student);
    ui->addname->setText("");
    ui->addxingbie->setCurrentIndex(0);
    ui->addnianji->setText("");
    ui->addxuehao->setText("");
    ui->addbanji->setText("");
    ui->addzhuanye->setCurrentIndex(0);
    ui->addqinshi->setText("");
    ui->addchuanghao->setCurrentIndex(0);
    ui->addcj1->setText("");
    ui->addcj2->setText("");
    ui->addcj3->setText("");
    ui->addcj4->setText("");
}

//成绩输入框槽函数1
void Widget::on_addcj1_textChanged(const QString &arg1)
{
    if(arg1.toDouble()>100||arg1.toDouble()<0)
    {
        //ui->addcj1->setStyleSheet("color: red;");
        ui->addcj1->setText("");
        QMessageBox::warning(this, "输入错误", "输入格式不符合要求，请输入0~100的小数");
    }
}

//成绩输入框槽函数2
void Widget::on_addcj2_textChanged(const QString &arg1)
{
    if(arg1.toDouble()>100||arg1.toDouble()<0)
    {
        //ui->addcj1->setStyleSheet("color: red;");
        ui->addcj2->setText("");
        QMessageBox::warning(this, "输入错误", "输入格式不符合要求，请输入0~100的小数");
    }
}

//成绩输入框槽函数3
void Widget::on_addcj3_textChanged(const QString &arg1)
{
    if(arg1.toDouble()>100||arg1.toDouble()<0)
    {
        //ui->addcj1->setStyleSheet("color: red;");
        ui->addcj3->setText("");
        QMessageBox::warning(this, "输入错误", "输入格式不符合要求，请输入0~100的小数");
    }
}

//成绩输入框槽函数4
void Widget::on_addcj4_textChanged(const QString &arg1)
{
    if(arg1.toDouble()>100||arg1.toDouble()<0)
    {
        //ui->addcj1->setStyleSheet("color: red;");
        ui->addcj4->setText("");
        QMessageBox::warning(this, "输入错误", "输入格式不符合要求，请输入0~100的小数");
    }
}

//从TXT文件中加载
void Widget::on_pushButton_3_clicked()
{
    QString txtName = QFileDialog::getOpenFileName(nullptr, "选择文件", "", "TXT文件(*.txt)");
    //如果返回非空则读取
    if(!txtName.isEmpty()){
        if(stu.readFromFile(txtName.toStdString())){
            ui->savetishi->setText("读取"+txtName+"成功");
            ui->savetishi->setStyleSheet("color : green");
        }
        else{
            ui->savetishi->setText("读取"+txtName+"失败");
            ui->savetishi->setStyleSheet("color : red");
        }
        studentdisp(stu.getstudent(),ui->tableWidget);
    }
}


void Widget::on_saveButton_clicked()
{
    this->close();
}


void Widget::on_pushButton_4_clicked()
{
    //如果还有学生并且选中了一行则删除
    if(stu.getstudent().size()){
        if(ui->tableWidget->currentRow()!=-1){
            if(QMessageBox::warning(this,"删除学生","要删除-"+ui->tableWidget->item(ui->tableWidget->currentRow(),1)->text()+"-吗",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes){
                stu.deleteStudent(ui->tableWidget->item(ui->tableWidget->currentRow(),3)->text().toLongLong());
                studentdisp(stu.getstudent(),ui->tableWidget);
                ui->savetishi->setText("删除成功");
                ui->savetishi->setStyleSheet("color : green");
            }
            else{
                ui->savetishi->setText("");
            }
        }
        else
        {
            ui->savetishi->setText("当前没有选中学生");
            ui->savetishi->setStyleSheet("color : red");
        }
    }
    else{
        ui->savetishi->setText("系统学生人数为0");
        ui->savetishi->setStyleSheet("color : red");
    }
}

void Widget::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    Dialog *dialog=new Dialog;
    dialog->dispdata(stu.findStudentByStudentId(ui->tableWidget->item(item->row(),3)->text().toLongLong()));
    dialog->setWindowTitle("学生信息展示");
    QIcon icon(":/img/icons/logo.png");
    dialog->setWindowIcon(icon);
    dialog->exec();
    delete dialog;
}


void Widget::on_pushButton_5_clicked()
{

    Student* stu1=stu.findStudentByStudentId(ui->chazhaoqi->text().toLongLong());
    if(stu1!=nullptr){
        std::vector<Student>stus;
        stus.push_back(*stu1);
        studentdisp(stus,ui->tableWidget);
        ui->savetishi->setText("查找成功");
        ui->savetishi->setStyleSheet("color : green");
    }
    else
    {
        ui->savetishi->setText("查找失败！！请输入正确的学号");
        ui->savetishi->setStyleSheet("color : red");
    }

}


void Widget::on_pushButton_clicked()
{
    int fangshi=ui->comboBox->currentIndex();
    std::vector<Student>stus;
    switch(fangshi)
    {
        //提示
        case 0:
            ui->savetishi->setText("请选择正确的筛选项目");
            ui->savetishi->setStyleSheet("color : red");
            break;
        //年级
        case 1:
            stus=stu.filterByGrade(ui->shaixuanqi->text().toInt());
            studentdisp(stus,ui->tableWidget);
            if(stus.size())
            {
                ui->savetishi->setText("按年级筛选成功！！");
                ui->savetishi->setStyleSheet("color : green");
            }
            else
            {
                ui->savetishi->setText("筛选该年级无结果！！");
                ui->savetishi->setStyleSheet("color : red");
            }
            break;
        //专业
        case 2:
            stus=stu.filterByMajor(stu.major_str_to_int[ui->shaixuanqi->text()]);
            studentdisp(stus,ui->tableWidget);
            if(stus.size())
            {
                ui->savetishi->setText("按专业筛选成功！！");
                ui->savetishi->setStyleSheet("color : green");
            }
            else
            {
                ui->savetishi->setText("筛选该专业无结果！！");
                ui->savetishi->setStyleSheet("color : red");
            }
            break;
        //班级
        case 3:
            stus=stu.filterByClass(ui->shaixuanqi->text().toInt());
            studentdisp(stus,ui->tableWidget);
            if(stus.size())
            {
                ui->savetishi->setText("按班级筛选成功！！");
                ui->savetishi->setStyleSheet("color : green");
            }
            else
            {
                ui->savetishi->setText("筛选该班级无结果！！");
                ui->savetishi->setStyleSheet("color : red");
            }
            break;
        //姓名
        case 4:
            stus=stu.findStudentByName(ui->shaixuanqi->text());
            studentdisp(stus,ui->tableWidget);
            if(stus.size())
            {
                ui->savetishi->setText("按姓名筛选成功！！");
                ui->savetishi->setStyleSheet("color : green");
            }
            else
            {
                ui->savetishi->setText("筛选该姓名无结果！！");
                ui->savetishi->setStyleSheet("color : red");
            }
            break;
        //寝室号
        case 5:
            stus=stu.filterByDormitory(ui->shaixuanqi->text().toInt());
            studentdisp(stus,ui->tableWidget);
            if(stus.size())
            {
                ui->savetishi->setText("按寝室号筛选成功！！");
                ui->savetishi->setStyleSheet("color : green");
            }
            else
            {
                ui->savetishi->setText("筛选该寝室号无结果！！");
                ui->savetishi->setStyleSheet("color : red");
            }
            break;
    }
}

//筛选器输入框回车事件
void Widget::on_shaixuanqi_returnPressed()
{
    //跳转筛选处理函数
    on_pushButton_clicked();
}

//学号查找器输入框回车事件
void Widget::on_chazhaoqi_returnPressed()
{
    //跳转学号查找处理函数
    on_pushButton_5_clicked();
}

