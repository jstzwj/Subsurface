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
    editor/commandpanel.cpp \
    editor/createprimitivetab.cpp \
    editor/createtab.cpp \
    editor/customedtitlebar.cpp \
    editor/mainwindow.cpp \
    editor/modifytab.cpp \
    editor/viewwidget.cpp \
    editor/layout/flowlayout.cpp \
    editor/widget/colorbox.cpp \
    editor/widget/modifierstack.cpp \
    editor/widget/namecolorwidget.cpp \
    editor/widget/scombobox.cpp \
    editor/widget/spushbutton.cpp \
    editor/widget/stoolbarbutton.cpp \
    core/datacontext.cpp \
    core/editorcontext.cpp \
    core/scontext.cpp \
    core/data/datablock.cpp \
    core/loader/filedata.cpp \
    core/loader/readfile.cpp \
    core/objects/aabbboundbox.cpp \
    core/objects/boundbox.cpp \
    core/objects/camera.cpp \
    core/objects/geometry.cpp \
    core/objects/light.cpp \
    core/objects/plane.cpp \
    core/objects/scence.cpp \
    core/objects/shape.cpp \
    core/objects/sobject.cpp \
    core/objects/geometry/box.cpp


HEADERS += \
    editor/commandpanel.h \
    editor/createprimitivetab.h \
    editor/createtab.h \
    editor/customedtitlebar.h \
    editor/mainwindow.h \
    editor/modifytab.h \
    editor/viewwidget.h \
    editor/layout/flowlayout.h \
    editor/widget/colorbox.h \
    editor/widget/modifierstack.h \
    editor/widget/namecolorwidget.h \
    editor/widget/scombobox.h \
    editor/widget/spushbutton.h \
    editor/widget/stoolbarbutton.h \
    core/datacontext.h \
    core/editorcontext.h \
    core/scontext.h \
    core/type.h \
    core/data/datablock.h \
    core/data/dimensions.h \
    core/data/id.h \
    core/data/serialization/binarywriter.h \
    core/data/serialization/FileInputStream.h \
    core/data/serialization/FileOutputStream.h \
    core/data/serialization/InputStream.h \
    core/data/serialization/OutputStream.h \
    core/data/serialization/serializable.h \
    core/data/serialization/Stream.h \
    core/data/serialization/StreamBase.h \
    core/loader/filedata.h \
    core/loader/readfile.h \
    core/objects/aabbboundbox.h \
    core/objects/boundbox.h \
    core/objects/camera.h \
    core/objects/geometry.h \
    core/objects/light.h \
    core/objects/normal.h \
    core/objects/plane.h \
    core/objects/point.h \
    core/objects/scence.h \
    core/objects/shape.h \
    core/objects/sobject.h \
    core/objects/vector.h \
    core/objects/geometry/box.h \
    core/util/endian.h \
    core/util/singleton.h


FORMS += \
    editor/mainwindow.ui

win32:LIBS += -lOpengl32 \
                -lglu32

DISTFILES += \
    shader/fragmentshader.frag \
    shader/vertexshader.vert \
    rsc/images/Geometry.png

RESOURCES += \
    qss.qrc \
    images.qrc \
    shaders.qrc
