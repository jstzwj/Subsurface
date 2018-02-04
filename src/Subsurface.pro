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
    core/scence/scence.cpp \
    core/scence/primitive.cpp \
    core/scence/primitives/box.cpp \
    core/scence/shape.cpp \
    core/scence/light.cpp \
    core/scence/camera.cpp \
    editor/widget/colorbox.cpp \
    editor/widget/namecolorwidget.cpp \
    editor/commandpanel.cpp \
    editor/createprimitivetab.cpp \
    editor/createtab.cpp \
    editor/customedtitlebar.cpp \
    editor/mainwindow.cpp \
    editor/modifytab.cpp \
    editor/viewwidget.cpp \
    editor/widget/spushbutton.cpp \
    editor/widget/stoolbarbutton.cpp \
    editor/layout/flowlayout.cpp

HEADERS += \
    core/scence/scence.h \
    core/scence/primitive.h \
    core/scence/primitives/box.h \
    core/type.h \
    util/singleton.h \
    core/scence/normal.h \
    core/scence/point.h \
    core/scence/vector.h \
    core/scence/shape.h \
    core/scence/light.h \
    core/scence/camera.h \
    editor/widget/colorbox.h \
    editor/widget/namecolorwidget.h \
    editor/commandpanel.h \
    editor/createprimitivetab.h \
    editor/createtab.h \
    editor/customedtitlebar.h \
    editor/mainwindow.h \
    editor/modifytab.h \
    editor/viewwidget.h \
    editor/widget/spushbutton.h \
    editor/widget/stoolbarbutton.h \
    editor/layout/flowlayout.h

FORMS += \
    editor/mainwindow.ui

win32:LIBS += -lOpengl32 \
                -lglu32

DISTFILES += \
    shader/fragmentshader.frag \
    shader/vertexshader.vert

RESOURCES += \
    qss.qrc \
    images.qrc \
    shaders.qrc
