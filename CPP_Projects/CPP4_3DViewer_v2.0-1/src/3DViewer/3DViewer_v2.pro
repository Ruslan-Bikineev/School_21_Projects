QT       += core gui openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../Backend/file.cc \
    ../Backend/data.cc \
    ../Backend/model.cc \
    ../Backend/scaling.cc \
    OpenGLWidget.cc \
    main.cc \
    view.cc


HEADERS += \
    ../Backend/affine_facade.h \
    ../Backend/data.h \
    ../Backend/file.h \
    ../Backend/model.h \
    ../Backend/move_coordinates_context.h \
    ../Backend/rotate_coordinates_context.h \
    OpenGLWidget.h \
    view.h

FORMS += \
    view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
