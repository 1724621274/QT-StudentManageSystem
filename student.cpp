#include "student.h"
#include "des.h"
extern QString deskey;

// 构造函数
Student::Student(QString n, int g, long long id, int gr, int majId, int clsNum, int dormNum, int bedNum, double s1, double s2, double s3, double s4) {
    name = n;
    gender = g;
    studentId = id;
    grade = gr;
    majorId = majId;
    classNumber = clsNum;
    dormitoryNumber = dormNum;
    bedNumber = bedNum;
    score1 = s1;
    score2 = s2;
    score3 = s3;
    score4 = s4;
    averageScore = (s1 + s2 + s3 + s4) / 4.0;
}

// 设置姓名
void Student::setName(QString n) {
    name = n;
}

// 获取姓名
QString Student::getName() {
    return name;
}

// 设置性别
void Student::setGender(int g) {
    gender = g;
}

// 获取性别
int Student::getGender() {
    return gender;
}

// 设置学号
void Student::setStudentId(long long id) {
    studentId = id;
}

// 获取学号
long long Student::getStudentId() {
    return studentId;
}

// 设置年级
void Student::setGrade(int gr) {
    grade = gr;
}

// 获取年级
int Student::getGrade() {
    return grade;
}

// 设置专业编号
void Student::setMajorId(int majId) {
    majorId = majId;
}

// 获取专业编号
int Student::getMajorId() {
    return majorId;
}

// 设置班级
void Student::setClassNumber(int clsNum) {
    classNumber = clsNum;
}

// 获取班级
int Student::getClassNumber() {
    return classNumber;
}

// 设置宿舍号
void Student::setDormitoryNumber(int dormNum) {
    dormitoryNumber = dormNum;
}

// 获取宿舍号
int Student::getDormitoryNumber() {
    return dormitoryNumber;
}

// 设置床位号
void Student::setBedNumber(int bedNum) {
    bedNumber = bedNum;
}

// 获取床位号
int Student::getBedNumber() {
    return bedNumber;
}

// 设置专业成绩 1
void Student::Student::setScore1(double s1) {
    score1 = s1;
    recalculateAverageScore();
}

// 获取专业成绩 1
double Student::getScore1() {
    return score1;
}

// 设置专业成绩 2
void Student::setScore2(double s2) {
    score2 = s2;
    recalculateAverageScore();
}

// 获取专业成绩 2
double Student::getScore2() {
    return score2;
}

// 设置专业成绩 3
void Student::setScore3(double s3) {
    score3 = s3;
    recalculateAverageScore();
}

// 获取专业成绩 3
double Student::getScore3() {
    return score3;
}

// 设置专业成绩 4
void Student::setScore4(double s4) {
    score4 = s4;
    recalculateAverageScore();
}

// 获取专业成绩 4
double Student::getScore4() {
    return score4;
}

// 重新计算平均分
void Student::recalculateAverageScore() {
    averageScore = (score1 + score2 + score3 + score4) / 4.0;
}

// 获取平均分
double Student::getAverageScore() {
    return averageScore;
}

// 打印学生信息的函数
void Student::printInfo() {
    qDebug() << name << "  "<< gender << "     "<< studentId << "    "<< grade << "      "<< majorId << "      "<< classNumber << "     "<< dormitoryNumber << "     "<< bedNumber << "      "<< score1 << "      "<< score2 << "      "<< score3 << "      "<< score4 << "     "<<averageScore << endl;
}



// 比较函数，用于按姓名排序
bool StudentManager::compareByName_0( Student &s1,  Student &s2) {
    return s1.getName() < s2.getName();
}
bool StudentManager::compareByName_1( Student &s1,  Student &s2) {
    return s1.getName() > s2.getName();
}

// 比较函数，用于按性别排序
bool StudentManager::compareByGender_0( Student &s1,  Student &s2) {
    return s1.getGender() < s2.getGender();
}
bool StudentManager::compareByGender_1( Student &s1,  Student &s2) {
    return s1.getGender() > s2.getGender();
}

// 比较函数，用于按学号排序
bool StudentManager::compareByStudentId_0( Student &s1,  Student &s2) {
    return s1.getStudentId() < s2.getStudentId();
}
bool StudentManager::compareByStudentId_1( Student &s1,  Student &s2) {
    return s1.getStudentId() > s2.getStudentId();
}

// 比较函数，用于按年级排序
bool StudentManager::compareByGrade_0( Student &s1,  Student &s2) {
    return s1.getGrade() < s2.getGrade();
}
bool StudentManager::compareByGrade_1( Student &s1,  Student &s2) {
    return s1.getGrade() > s2.getGrade();
}

// 比较函数，用于按专业编号排序
bool StudentManager::compareByMajorId_0( Student &s1,  Student &s2) {
    return s1.getMajorId() < s2.getMajorId();
}
bool StudentManager::compareByMajorId_1( Student &s1,  Student &s2) {
    return s1.getMajorId() > s2.getMajorId();
}

// 比较函数，用于按班级排序
bool StudentManager::compareByClassNumber_0( Student &s1,  Student &s2) {
    return s1.getClassNumber() < s2.getClassNumber();
}
bool StudentManager::compareByClassNumber_1( Student &s1,  Student &s2) {
    return s1.getClassNumber() > s2.getClassNumber();
}

// 比较函数，用于按宿舍号排序
bool StudentManager::compareByDormitoryNumber_0( Student &s1,  Student &s2) {
    return s1.getDormitoryNumber() < s2.getDormitoryNumber();
}
bool StudentManager::compareByDormitoryNumber_1( Student &s1,  Student &s2) {
    return s1.getDormitoryNumber() > s2.getDormitoryNumber();
}

// 比较函数，用于按床位号排序
bool StudentManager::compareByBedNumber_0( Student &s1,  Student &s2) {
    return s1.getBedNumber() < s2.getBedNumber();
}
bool StudentManager::compareByBedNumber_1( Student &s1,  Student &s2) {
    return s1.getBedNumber() > s2.getBedNumber();
}

// 比较函数，用于按专业成绩 1 排序
bool StudentManager::compareByScore1_0( Student &s1,  Student &s2) {
    return s1.getScore1() < s2.getScore1();
}
bool StudentManager::compareByScore1_1( Student &s1,  Student &s2) {
    return s1.getScore1() > s2.getScore1();
}

// 比较函数，用于按专业成绩 2 排序
bool StudentManager::compareByScore2_0( Student &s1,  Student &s2) {
    return s1.getScore2() < s2.getScore2();
}
bool StudentManager::compareByScore2_1( Student &s1,  Student &s2) {
    return s1.getScore2() > s2.getScore2();
}

// 比较函数，用于按专业成绩 3 排序
bool StudentManager::compareByScore3_0( Student &s1,  Student &s2) {
    return s1.getScore3() < s2.getScore3();
}
bool StudentManager::compareByScore3_1( Student &s1,  Student &s2) {
    return s1.getScore3() > s2.getScore3();
}

// 比较函数，用于按专业成绩 4 排序
bool StudentManager::compareByScore4_0( Student &s1,  Student &s2) {
    return s1.getScore4() < s2.getScore4();
}
bool StudentManager::compareByScore4_1( Student &s1,  Student &s2) {
    return s1.getScore4() > s2.getScore4();
}

// 比较函数，用于按成绩平均分排序
bool StudentManager::compareByAverageScore_0( Student &s1,  Student &s2) {
    return s1.getAverageScore() < s2.getAverageScore();
}
bool StudentManager::compareByAverageScore_1( Student &s1,  Student &s2) {
    return s1.getAverageScore() > s2.getAverageScore();
}

StudentManager::StudentManager()
{
    //性别设置
    gender_str_to_int["女"]=0;
    gender_int_to_str[0]="女";
    gender_str_to_int["男"]=1;
    gender_int_to_str[1]="男";
    //专业设置
    major_str_to_int["测控技术与仪器"]=1;
    major_int_to_str[1]="测控技术与仪器";
    major_str_to_int["自动化"]=2;
    major_int_to_str[2]="自动化";
    major_str_to_int["应用物理学"]=3;
    major_int_to_str[3]="应用物理学";
    major_str_to_int["电子信息与技术"]=4;
    major_int_to_str[4]="电子信息与技术";
    major_str_to_int["机械电子工程"]=5;
    major_int_to_str[5]="机械电子工程";
}

// 添加学生
void StudentManager::addStudent(Student student) {
    students.push_back(student);
}

// 删除学生
void StudentManager::deleteStudent(long long studentId) {
    for (auto it = students.begin(); it!= students.end(); ++it) {
        if (it->getStudentId() == studentId) {
            students.erase(it);
            return;
        }
    }
    qDebug() << "未找到指定学号的学生，删除失败" << endl;
}

// 根据姓名排序
void StudentManager::sortByName(bool fangshi) {
    if(fangshi)std::sort(students.begin(), students.end(), compareByName_1);
    else std::sort(students.begin(), students.end(), compareByName_0);
}

// 根据性别排序
void StudentManager::sortByGender(bool fangshi) {
    if(fangshi)std::sort(students.begin(), students.end(), compareByGender_1);
    else std::sort(students.begin(), students.end(), compareByGender_0);
}

// 根据学号排序
void StudentManager::sortByStudentId(bool fangshi) {
    if(fangshi)std::sort(students.begin(), students.end(), compareByStudentId_1);
    else std::sort(students.begin(), students.end(), compareByStudentId_0);
}

// 根据年级排序
void StudentManager::sortByGrade(bool fangshi) {
    if(fangshi)std::sort(students.begin(), students.end(), compareByGrade_1);
    else std::sort(students.begin(), students.end(), compareByGrade_0);
}

// 根据专业编号排序
void StudentManager::sortByMajorId(bool fangshi) {
    if(fangshi)std::sort(students.begin(), students.end(), compareByMajorId_1);
    else std::sort(students.begin(), students.end(), compareByMajorId_0);
}

// 根据班级排序
void StudentManager::sortByClassNumber(bool fangshi) {
    if(fangshi)std::sort(students.begin(), students.end(), compareByClassNumber_1);
    else std::sort(students.begin(), students.end(), compareByClassNumber_0);
}

// 根据宿舍号排序
void StudentManager::sortByDormitoryNumber(bool fangshi) {
    if(fangshi)std::sort(students.begin(), students.end(), compareByDormitoryNumber_1);
    else std::sort(students.begin(), students.end(), compareByDormitoryNumber_0);
}

// 根据床位号排序
void StudentManager::sortByBedNumber(bool fangshi) {
    if(fangshi)std::sort(students.begin(), students.end(), compareByBedNumber_1);
    else std::sort(students.begin(), students.end(), compareByBedNumber_0);
}

// 根据专业成绩 1 排序
void StudentManager::sortByScore1(bool fangshi) {
    if(fangshi)std::sort(students.begin(), students.end(), compareByScore1_1);
    else std::sort(students.begin(), students.end(), compareByScore1_0);
}

// 根据专业成绩 2 排序
void StudentManager::sortByScore2(bool fangshi) {
    if(fangshi)std::sort(students.begin(), students.end(), compareByScore2_1);
    else std::sort(students.begin(), students.end(), compareByScore2_0);
}

// 根据专业成绩 3 排序
void StudentManager::sortByScore3(bool fangshi) {
    if(fangshi)std::sort(students.begin(), students.end(), compareByScore3_1);
    else std::sort(students.begin(), students.end(), compareByScore3_0);
}

// 根据专业成绩 4 排序
void StudentManager::sortByScore4(bool fangshi) {
    if(fangshi)std::sort(students.begin(), students.end(), compareByScore4_1);
    else std::sort(students.begin(), students.end(), compareByScore4_0);
}

// 根据成绩平均分排序
void StudentManager::sortByAverageScore(bool fangshi) {
    if(fangshi)std::sort(students.begin(), students.end(), compareByAverageScore_1);
    else std::sort(students.begin(), students.end(), compareByAverageScore_0);
}

// 按姓名查找
std::vector<Student> StudentManager::findStudentByName(const QString &name) {
    std::vector<Student> findstudent;
    for (auto& student : students) {
        if (student.getName() == name) {
            findstudent.push_back(student);
        }
    }
    return findstudent;
}

// 按学号查找
Student *StudentManager::findStudentByStudentId(long long studentId) {
    for (auto& student : students) {
        if (student.getStudentId() == studentId) {
            return &student;
        }
    }
    return nullptr;
}

// 按年级筛选
std::vector<Student> StudentManager::filterByGrade(int grade) {
    std::vector<Student> filteredStudents;
    for (auto& student : students) {
        if (student.getGrade() == grade) {
            filteredStudents.push_back(student);
        }
    }
    return filteredStudents;
}

// 按专业筛选
std::vector<Student> StudentManager::filterByMajor(int majorId) {
    std::vector<Student> filteredStudents;
    for (auto& student : students) {
        if (student.getMajorId() == majorId) {
            qDebug()<<majorId;
            filteredStudents.push_back(student);
        }
    }
    return filteredStudents;
}

// 按班级筛选
std::vector<Student> StudentManager::filterByClass(int classNumber) {
    std::vector<Student> filteredStudents;
    for (auto& student : students) {
        if (student.getClassNumber() == classNumber) {
            filteredStudents.push_back(student);
        }
    }
    return filteredStudents;
}

// 按宿舍筛选
std::vector<Student> StudentManager::filterByDormitory(int dormitoryNumber) {
    std::vector<Student> filteredStudents;
    for (auto& student : students) {
        if (student.getDormitoryNumber() == dormitoryNumber) {
            filteredStudents.push_back(student);
        }
    }
    return filteredStudents;
}

// 打印所有学生信息
void StudentManager::printAllStudents() {
    qDebug() << "姓名   性别   学号   年级   专业   班级   寝室   床号   专业1   专业2   专业3   专业4   平均分" ;
    for ( auto& i : students) {
        i.printInfo();
    }
}

std::vector<Student> StudentManager::getstudent(){
    return students;
}

//保存到文件
bool StudentManager::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for ( auto& student : students) {
            file << student.getName().toStdString() << " ";
            file << student.getGender() << " ";
            file << student.getStudentId() << " ";
            file << student.getGrade() << " ";
            file << student.getMajorId() << " ";
            file << student.getClassNumber() << " ";
            file << student.getDormitoryNumber() << " ";
            file << student.getBedNumber() << " ";
            file << student.getScore1() << " ";
            file << student.getScore2() << " ";
            file << student.getScore3() << " ";
            file << student.getScore4() << std::endl;
        }
        file.close();
    } else {
        qDebug() << "无法打开文件进行保存" << endl;
        return false;
    }
        return true;
}

// 从文件读取学生信息
bool StudentManager::readFromFile(const std::string& filename) {
    bool zt=false;
    std::ifstream file(filename);
    if (file.is_open()) {
        Student student;
        while (true) {
            std::string name;
            int gender,  grade, majorId, classNumber, dormitoryNumber, bedNumber, score1, score2, score3, score4;
            long long studentId;
            file >> name;
            file >> gender;
            file >> studentId;
            file >> grade;
            file >> majorId;
            file >> classNumber;
            file >> dormitoryNumber;
            file >> bedNumber;
            file >> score1;
            file >> score2;
            file >> score3;
            file >> score4;

            if (file.eof()) {
                break;
            }
            if(!zt){
                students.clear();
                zt=true;
            }

            student.setName(name.c_str());
            student.setGender(gender);
            student.setStudentId(studentId);
            student.setGrade(grade);
            student.setMajorId(majorId);
            student.setClassNumber(classNumber);
            student.setDormitoryNumber(dormitoryNumber);
            student.setBedNumber(bedNumber);
            student.setScore1(score1);
            student.setScore2(score2);
            student.setScore3(score3);
            student.setScore4(score4);
            student.recalculateAverageScore();

            students.push_back(student);
        }
        file.close();
    } else {
        qDebug() << "无法打开文件进行读取" << endl;
    }
    return zt;
}

//保存到文件
bool StudentManager::saveDesToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for ( auto& student : students) {
            file << des_encrypt(student.getName().toStdString(),deskey.toStdString()) << " ";
            file << des_encrypt(std::to_string(student.getGender()),deskey.toStdString()) << " ";
            file << des_encrypt(std::to_string(student.getStudentId()),deskey.toStdString()) << " ";
            file << des_encrypt(std::to_string(student.getGrade()),deskey.toStdString()) << " ";
            file << des_encrypt(std::to_string(student.getMajorId()),deskey.toStdString()) << " ";
            file << des_encrypt(std::to_string(student.getClassNumber()),deskey.toStdString()) << " ";
            file << des_encrypt(std::to_string(student.getDormitoryNumber()),deskey.toStdString()) << " ";
            file << des_encrypt(std::to_string(student.getBedNumber()),deskey.toStdString()) << " ";
            file << des_encrypt(std::to_string(student.getScore1()),deskey.toStdString()) << " ";
            file << des_encrypt(std::to_string(student.getScore2()),deskey.toStdString()) << " ";
            file << des_encrypt(std::to_string(student.getScore3()),deskey.toStdString()) << " ";
            file << des_encrypt(std::to_string(student.getScore4()),deskey.toStdString()) << std::endl;
        }
        file.close();
    } else {
        qDebug() << "无法打开文件进行保存" << endl;
        return false;
    }
    return true;
}

// 从文件读取学生信息
bool StudentManager::readDesFromFile(const std::string& filename) {
    std::ifstream file(filename);
    bool zt=false;
    if (file.is_open()) {
        Student student;
        while (true) {
            std::string name,gender, studentId, grade, majorId, classNumber, dormitoryNumber, bedNumber, score1, score2, score3, score4;
            file >> name;
            file >> gender;
            file >> studentId;
            file >> grade;
            file >> majorId;
            file >> classNumber;
            file >> dormitoryNumber;
            file >> bedNumber;
            file >> score1;
            file >> score2;
            file >> score3;
            file >> score4;

            name=des_decrypt(name,deskey.toStdString());
            gender=des_decrypt(gender,deskey.toStdString());
            studentId=des_decrypt(studentId,deskey.toStdString());
            grade=des_decrypt(grade,deskey.toStdString());
            majorId=des_decrypt(majorId,deskey.toStdString());
            classNumber=des_decrypt(classNumber,deskey.toStdString());
            dormitoryNumber=des_decrypt(dormitoryNumber,deskey.toStdString());
            bedNumber=des_decrypt(bedNumber,deskey.toStdString());
            score1=des_decrypt(score1,deskey.toStdString());
            score2=des_decrypt(score2,deskey.toStdString());
            score3=des_decrypt(score3,deskey.toStdString());
            score4=des_decrypt(score4,deskey.toStdString());


            if (file.eof()) {
                break;
            }
            if(!zt){
                students.clear();
                zt=true;
            }
            student.setName(name.c_str());
            student.setGender(stoi(gender));
            student.setStudentId(stoll(studentId));
            student.setGrade(stoi(grade));
            student.setMajorId(stoi(majorId));
            student.setClassNumber(stoi(classNumber));
            student.setDormitoryNumber(stoi(dormitoryNumber));
            student.setBedNumber(stoi(bedNumber));
            student.setScore1(stoi(score1));
            student.setScore2(stoi(score2));
            student.setScore3(stoi(score3));
            student.setScore4(stoi(score4));
            student.recalculateAverageScore();

            students.push_back(student);
        }
        file.close();
    } else {
        qDebug() << "无法打开文件进行读取" << endl;
    }
    return zt;
}

