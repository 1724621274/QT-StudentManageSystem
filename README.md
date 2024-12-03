# 《学生数据管理程序说明文档》


## 一、程序概述
本程序由小辉yu(黎忠海)开发完成，完成时间为 2024.11.27。其主要功能是实现对学生数据的多方面管理操作，涵盖数据的导入、导出、排序、查找、筛选、添加以及删除等，能够有效地帮助用户处理学生数据相关事务。

## 二、程序特性
- **数据存储加密**：为保障数据安全，程序对本地数据采用 DES 加密算法进行存储，防止数据泄露与非法访问。
- **路径要求**：程序必须放置在英文路径下运行，否则会因路径字符编码等问题导致无法读取文件，影响程序正常使用。

## 三、文件结构说明
- **src 文件夹**：包含 QT5 工程文件，这是程序开发过程中的相关工程文件，对于程序的进一步开发、调试或二次开发可能具有重要意义。
- **src/icons 文件夹**：包含应用图标的图片。
- **StudentManageSystem.zip**：此压缩文件包含了运行环境的发布程序，用户可通过解压该文件，在满足英文路径要求的情况下，直接运行程序，方便程序的部署与使用。
- **student.txt**：用于存放测试数据，用户可在此文件内准备待处理的学生数据文件，以便程序进行导入等操作。

## 四、功能详细说明
- **管理员账户管理**：允许管理员账户的添加删除，超级管理员可添加和删除普通管理员账户。
- **数据导入**：允许用户从外部文件（仅.txt文件）将学生数据导入到程序中，以便进行后续的管理操作。
- **数据导出**：用户能够将程序内处理好的学生数据导出为.txt格式的文件，方便数据的备份、共享或与其他系统进行对接。
- **排序功能**：可依据学生的不同属性（如学号、成绩、姓名、班级、年级等）对数据进行升序或降序排列，方便用户查看数据的顺序分布情况。
- **查找功能**：通过输入特定的关键字（如学号），能够快速定位到对应的学生数据记录，提高数据检索效率。
- **筛选功能**：根据设定的条件（如特定班级、年级、专业等）筛选出符合要求的学生数据子集，便于针对性地分析和处理数据。
- **添加功能**：支持用户手动输入新的学生数据信息，并将其添加到已有的学生数据集合中，实现数据的扩充。
- **删除功能**：对于不再需要或错误录入的学生数据记录，用户可通过此功能将其从数据集中删除，确保数据的准确性和有效性。
- **修改功能**：程序尚未设定修改模块、后续更新会加入

## 五、联系方式
- **邮箱**：1724621274@qq.com
- **QQ**：1724621274

## 六、更新日志：
- **2024.12.2**：v1.0 初代版本，包含数据导入、导出、排序、查找、筛选、添加、删除；
- **2024.12.2**：v1.1 更新了管理员账户的管理界面，超级管理员可添加和删除普通管理员账户
