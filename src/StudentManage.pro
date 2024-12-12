QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_admin.cpp \
    add_student.cpp \
    admin.cpp \
    des.cpp \
    home.cpp \
    login.cpp \
    main.cpp \
    student.cpp \
    student_show.cpp

HEADERS += \
    add_admin.h \
    add_student.h \
    admin.h \
    des.h \
    home.h \
    login.h \
    student.h \
    student_show.h

FORMS += \
    add_admin.ui \
    add_student.ui \
    admin.ui \
    home.ui \
    login.ui \
    student_show.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc
