QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../src/SmartCalc/main.cpp \
    ../src/SmartCalc/mainwindow.cpp \
    ../src/SmartCalc/qcustomplot.cpp \
    ../src/Backend/smart_calc_v1.0.c \
    ../src/Backend/stack.c \
    ../src/Backend/suppport.c

HEADERS += \
    ../src/SmartCalc/mainwindow.h \
    ../src/SmartCalc/qcustomplot.h \
    ../src/Backend/smart_calc_v1.0.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
