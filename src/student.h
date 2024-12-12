#ifndef STUDENT_H
#define STUDENT_H
#include "QDebug" //qDebug输出
#include <vector> //vector
#include <algorithm> //sort()排序
#include <fstream>//文件操作
#include <map>
#include <QDir>
#include <QFileInfo>
#include <QFile>
#include <string>
//学生类
class Student {
    private:
        //姓名
        QString name;
        //性别
        int gender;
        //学号
        long long studentId;
        //年级
        int grade;
        //专业代码
        int majorId;
        //班级
        int classNumber;
        //寝室号
        int dormitoryNumber;
        //床位号
        int bedNumber;
        //成绩1
        double score1;
        //成绩2
        double score2;
        //成绩3
        double score3;
        //成绩4
        double score4;
        //平均成绩
        double averageScore;

    public:
        Student(){}
        // 构造函数
        Student(QString n, int g, long long id, int gr, int majId, int clsNum, int dormNum, int bedNum, double s1, double s2, double s3,double s4);

        // 设置姓名
        void setName(QString n);

        // 获取姓名
        QString getName();

        // 设置性别
        void setGender(int g);

        // 获取性别
        int getGender();

        // 设置学号
        void setStudentId(long long id);

        // 获取学号
        long long getStudentId();

        // 设置年级
        void setGrade(int gr);

        // 获取年级
        int getGrade();

        // 设置专业编号
        void setMajorId(int majId);

        // 获取专业
        int getMajorId();

        // 设置班级
        void setClassNumber(int clsNum);

        // 获取班级
        int getClassNumber();

        // 设置宿舍号
        void setDormitoryNumber(int dormNum);

        // 获取宿舍号
        int getDormitoryNumber();

        // 设置床位号
        void setBedNumber(int bedNum);

        // 获取床位号
        int getBedNumber();

        // 设置专业成绩 1
        void setScore1(double s1);

        // 获取专业成绩 1
        double getScore1();

        // 设置专业成绩 2
        void setScore2(double s2);

        // 获取专业成绩 2
        double getScore2();

        // 设置专业成绩 3
        void setScore3(double s3);

        // 获取专业成绩 3
        double getScore3();

        // 设置专业成绩 4
        void setScore4(double s4);

        // 获取专业成绩 4
        double getScore4();

        // 重新计算平均分
        void recalculateAverageScore();

        // 获取平均分
        double getAverageScore();

        // 打印学生信息的函数
        void printInfo();
};

//学生管理类
class StudentManager {
    private:
        std::vector<Student> students;
        // 比较函数，用于按姓名排序
        static bool compareByName_0( Student &s1,  Student &s2);
        static bool compareByName_1( Student &s1,  Student &s2);
        // 比较函数，用于按性别排序
        static bool compareByGender_0( Student &s1,  Student &s2);
        static bool compareByGender_1( Student &s1,  Student &s2);
        // 比较函数，用于按学号排序
        static bool compareByStudentId_0( Student &s1,  Student &s2);
        static bool compareByStudentId_1( Student &s1,  Student &s2);
        // 比较函数，用于按年级排序
        static bool compareByGrade_0( Student &s1,  Student &s2);
        static bool compareByGrade_1( Student &s1,  Student &s2);
        // 比较函数，用于按专业编号排序
        static bool compareByMajorId_0( Student &s1,  Student &s2);
        static bool compareByMajorId_1( Student &s1,  Student &s2);
        // 比较函数，用于按班级排序
        static bool compareByClassNumber_0( Student &s1,  Student &s2);
        static bool compareByClassNumber_1( Student &s1,  Student &s2);
        // 比较函数，用于按宿舍号排序
        static bool compareByDormitoryNumber_0( Student &s1,  Student &s2);
        static bool compareByDormitoryNumber_1( Student &s1,  Student &s2);
        // 比较函数，用于按床位号排序
        static bool compareByBedNumber_0( Student &s1,  Student &s2);
        static bool compareByBedNumber_1( Student &s1,  Student &s2);
        // 比较函数，用于按专业成绩 1 排序
        static bool compareByScore1_0( Student &s1,  Student &s2);
        static bool compareByScore1_1( Student &s1,  Student &s2);
        // 比较函数，用于按专业成绩 2 排序
        static bool compareByScore2_0( Student &s1,  Student &s2);
        static bool compareByScore2_1( Student &s1,  Student &s2);
        // 比较函数，用于按专业成绩 3 排序
        static bool compareByScore3_0( Student &s1,  Student &s2);
        static bool compareByScore3_1( Student &s1,  Student &s2);
        // 比较函数，用于按专业成绩 4 排序
        static bool compareByScore4_0( Student &s1,  Student &s2);
        static bool compareByScore4_1( Student &s1,  Student &s2);
        // 比较函数，用于按成绩平均分排序
        static bool compareByAverageScore_0( Student &s1,  Student &s2);
        static bool compareByAverageScore_1( Student &s1,  Student &s2);
    public:
        //构造函数
        StudentManager();

        //检查文件夹是否存在，不存在则创建
        bool CreateFolder(QString fullpath);
        bool isAllDigits(std::string str);
        //性别转换：map映射
        std::map<QString,int>gender_str_to_int;
        std::map<int,QString>gender_int_to_str;

        //专业转换：map映射
        std::map<QString,int>major_str_to_int;
        std::map<int,QString>major_int_to_str;
        // 添加学生
        void addStudent(Student student);

        //修改学生
        void updateStudent(long long studentId, Student& newStudent);

        // 删除学生
        void deleteStudent(long long studentId);

        // 根据姓名排序
        void sortByName(bool fangshi);

        // 根据性别排序
        void sortByGender(bool fangshi);

        // 根据学号排序
        void sortByStudentId(bool fangshi);

        // 根据年级排序
        void sortByGrade(bool fangshi);

        // 根据专业编号排序
        void sortByMajorId(bool fangshi);

        // 根据班级排序
        void sortByClassNumber(bool fangshi);

        // 根据宿舍号排序
        void sortByDormitoryNumber(bool fangshi);

        // 根据床位号排序
        void sortByBedNumber(bool fangshi);

        // 根据专业成绩 1 排序
        void sortByScore1(bool fangshi);

        // 根据专业成绩 2 排序
        void sortByScore2(bool fangshi);

        // 根据专业成绩 3 排序
        void sortByScore3(bool fangshi);

        // 根据专业成绩 4 排序
        void sortByScore4(bool fangshi);

        // 根据成绩平均分排序
        void sortByAverageScore(bool fangshi);

        // 按姓名查找
        std::vector<Student> findStudentByName(const QString &name);

        // 按学号查找
        Student *findStudentByStudentId(long long studentId);

        // 按年级筛选
        std::vector<Student> filterByGrade(int grade);

        // 按专业筛选
        std::vector<Student> filterByMajor(int majorId);

        // 按班级筛选
        std::vector<Student> filterByClass(int classNumber);

        // 按宿舍筛选
        std::vector<Student> filterByDormitory(int dormitoryNumber);

        // 打印所有学生信息
        void printAllStudents();

        //获取学生信息
        std::vector<Student> getstudent();

        //保存学生信息到文件
        bool saveToFile(const std::string& filename);

        //保存学生信息（DES加密）到文件
        bool saveDesToFile(const std::string& filename);

        // 从文件读取学生信息
        bool readFromFile(const std::string& filename);

        // 从DES加密文件读取学生信息
        bool readDesFromFile(const std::string& filename);
};

#endif // STUDENT_H
