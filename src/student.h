#ifndef STUDENT_H
#define STUDENT_H
#include "QDebug" //qDebug���
#include <vector> //vector
#include <algorithm> //sort()����
#include <fstream>//�ļ�����
#include <map>
#include <QDir>
#include <QFileInfo>
#include <QFile>
#include <string>
//ѧ����
class Student {
    private:
        //����
        QString name;
        //�Ա�
        int gender;
        //ѧ��
        long long studentId;
        //�꼶
        int grade;
        //רҵ����
        int majorId;
        //�༶
        int classNumber;
        //���Һ�
        int dormitoryNumber;
        //��λ��
        int bedNumber;
        //�ɼ�1
        double score1;
        //�ɼ�2
        double score2;
        //�ɼ�3
        double score3;
        //�ɼ�4
        double score4;
        //ƽ���ɼ�
        double averageScore;

    public:
        Student(){}
        // ���캯��
        Student(QString n, int g, long long id, int gr, int majId, int clsNum, int dormNum, int bedNum, double s1, double s2, double s3,double s4);

        // ��������
        void setName(QString n);

        // ��ȡ����
        QString getName();

        // �����Ա�
        void setGender(int g);

        // ��ȡ�Ա�
        int getGender();

        // ����ѧ��
        void setStudentId(long long id);

        // ��ȡѧ��
        long long getStudentId();

        // �����꼶
        void setGrade(int gr);

        // ��ȡ�꼶
        int getGrade();

        // ����רҵ���
        void setMajorId(int majId);

        // ��ȡרҵ
        int getMajorId();

        // ���ð༶
        void setClassNumber(int clsNum);

        // ��ȡ�༶
        int getClassNumber();

        // ���������
        void setDormitoryNumber(int dormNum);

        // ��ȡ�����
        int getDormitoryNumber();

        // ���ô�λ��
        void setBedNumber(int bedNum);

        // ��ȡ��λ��
        int getBedNumber();

        // ����רҵ�ɼ� 1
        void setScore1(double s1);

        // ��ȡרҵ�ɼ� 1
        double getScore1();

        // ����רҵ�ɼ� 2
        void setScore2(double s2);

        // ��ȡרҵ�ɼ� 2
        double getScore2();

        // ����רҵ�ɼ� 3
        void setScore3(double s3);

        // ��ȡרҵ�ɼ� 3
        double getScore3();

        // ����רҵ�ɼ� 4
        void setScore4(double s4);

        // ��ȡרҵ�ɼ� 4
        double getScore4();

        // ���¼���ƽ����
        void recalculateAverageScore();

        // ��ȡƽ����
        double getAverageScore();

        // ��ӡѧ����Ϣ�ĺ���
        void printInfo();
};

//ѧ��������
class StudentManager {
    private:
        std::vector<Student> students;
        // �ȽϺ��������ڰ���������
        static bool compareByName_0( Student &s1,  Student &s2);
        static bool compareByName_1( Student &s1,  Student &s2);
        // �ȽϺ��������ڰ��Ա�����
        static bool compareByGender_0( Student &s1,  Student &s2);
        static bool compareByGender_1( Student &s1,  Student &s2);
        // �ȽϺ��������ڰ�ѧ������
        static bool compareByStudentId_0( Student &s1,  Student &s2);
        static bool compareByStudentId_1( Student &s1,  Student &s2);
        // �ȽϺ��������ڰ��꼶����
        static bool compareByGrade_0( Student &s1,  Student &s2);
        static bool compareByGrade_1( Student &s1,  Student &s2);
        // �ȽϺ��������ڰ�רҵ�������
        static bool compareByMajorId_0( Student &s1,  Student &s2);
        static bool compareByMajorId_1( Student &s1,  Student &s2);
        // �ȽϺ��������ڰ��༶����
        static bool compareByClassNumber_0( Student &s1,  Student &s2);
        static bool compareByClassNumber_1( Student &s1,  Student &s2);
        // �ȽϺ��������ڰ����������
        static bool compareByDormitoryNumber_0( Student &s1,  Student &s2);
        static bool compareByDormitoryNumber_1( Student &s1,  Student &s2);
        // �ȽϺ��������ڰ���λ������
        static bool compareByBedNumber_0( Student &s1,  Student &s2);
        static bool compareByBedNumber_1( Student &s1,  Student &s2);
        // �ȽϺ��������ڰ�רҵ�ɼ� 1 ����
        static bool compareByScore1_0( Student &s1,  Student &s2);
        static bool compareByScore1_1( Student &s1,  Student &s2);
        // �ȽϺ��������ڰ�רҵ�ɼ� 2 ����
        static bool compareByScore2_0( Student &s1,  Student &s2);
        static bool compareByScore2_1( Student &s1,  Student &s2);
        // �ȽϺ��������ڰ�רҵ�ɼ� 3 ����
        static bool compareByScore3_0( Student &s1,  Student &s2);
        static bool compareByScore3_1( Student &s1,  Student &s2);
        // �ȽϺ��������ڰ�רҵ�ɼ� 4 ����
        static bool compareByScore4_0( Student &s1,  Student &s2);
        static bool compareByScore4_1( Student &s1,  Student &s2);
        // �ȽϺ��������ڰ��ɼ�ƽ��������
        static bool compareByAverageScore_0( Student &s1,  Student &s2);
        static bool compareByAverageScore_1( Student &s1,  Student &s2);
    public:
        //���캯��
        StudentManager();

        //����ļ����Ƿ���ڣ��������򴴽�
        bool CreateFolder(QString fullpath);
        bool isAllDigits(std::string str);
        //�Ա�ת����mapӳ��
        std::map<QString,int>gender_str_to_int;
        std::map<int,QString>gender_int_to_str;

        //רҵת����mapӳ��
        std::map<QString,int>major_str_to_int;
        std::map<int,QString>major_int_to_str;
        // ���ѧ��
        void addStudent(Student student);

        //�޸�ѧ��
        void updateStudent(long long studentId, Student& newStudent);

        // ɾ��ѧ��
        void deleteStudent(long long studentId);

        // ������������
        void sortByName(bool fangshi);

        // �����Ա�����
        void sortByGender(bool fangshi);

        // ����ѧ������
        void sortByStudentId(bool fangshi);

        // �����꼶����
        void sortByGrade(bool fangshi);

        // ����רҵ�������
        void sortByMajorId(bool fangshi);

        // ���ݰ༶����
        void sortByClassNumber(bool fangshi);

        // �������������
        void sortByDormitoryNumber(bool fangshi);

        // ���ݴ�λ������
        void sortByBedNumber(bool fangshi);

        // ����רҵ�ɼ� 1 ����
        void sortByScore1(bool fangshi);

        // ����רҵ�ɼ� 2 ����
        void sortByScore2(bool fangshi);

        // ����רҵ�ɼ� 3 ����
        void sortByScore3(bool fangshi);

        // ����רҵ�ɼ� 4 ����
        void sortByScore4(bool fangshi);

        // ���ݳɼ�ƽ��������
        void sortByAverageScore(bool fangshi);

        // ����������
        std::vector<Student> findStudentByName(const QString &name);

        // ��ѧ�Ų���
        Student *findStudentByStudentId(long long studentId);

        // ���꼶ɸѡ
        std::vector<Student> filterByGrade(int grade);

        // ��רҵɸѡ
        std::vector<Student> filterByMajor(int majorId);

        // ���༶ɸѡ
        std::vector<Student> filterByClass(int classNumber);

        // ������ɸѡ
        std::vector<Student> filterByDormitory(int dormitoryNumber);

        // ��ӡ����ѧ����Ϣ
        void printAllStudents();

        //��ȡѧ����Ϣ
        std::vector<Student> getstudent();

        //����ѧ����Ϣ���ļ�
        bool saveToFile(const std::string& filename);

        //����ѧ����Ϣ��DES���ܣ����ļ�
        bool saveDesToFile(const std::string& filename);

        // ���ļ���ȡѧ����Ϣ
        bool readFromFile(const std::string& filename);

        // ��DES�����ļ���ȡѧ����Ϣ
        bool readDesFromFile(const std::string& filename);
};

#endif // STUDENT_H
