#-------------------------------------------------
#
# Project created by QtCreator 2018-01-28T21:31:23
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Subsurface
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    UI/commandpanel.cpp \
    UI/createprimitivetab.cpp \
    UI/createtab.cpp \
    UI/customedtitlebar.cpp \
    UI/mainwindow.cpp \
    UI/modifytab.cpp \
    UI/viewwidget.cpp \
    UI/widget/colorbox.cpp \
    core/scence/scence.cpp \
    core/scence/primitive.cpp \
    core/scence/primitives/box.cpp

HEADERS += \
    UI/commandpanel.h \
    UI/createprimitivetab.h \
    UI/createtab.h \
    UI/customedtitlebar.h \
    UI/mainwindow.h \
    UI/modifytab.h \
    UI/viewwidget.h \
    UI/widget/colorbox.h \
    core/scence/scence.h \
    core/scence/primitive.h \
    core/scence/primitives/box.h \
    core/type.h \
    core/scence/SVector.h \
    core/scence/SPoint.h \
    core/scence/SNormal.h

FORMS += \
    UI/mainwindow.ui

win32:LIBS += -lOpengl32 \
                -lglu32 \
                -lglut

DISTFILES += \
    shader/fragmentshader.frag \
    shader/vertexshader.vert

RESOURCES += \
    qss.qrc \
    images.qrc \
    shaders.qrc
