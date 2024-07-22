#-------------------------------------------------
#
# Project created by QtCreator 2024-03-30T16:04:48
#
#-------------------------------------------------

QT += gui
QT += quick
QT += qml
TARGET = UiPlugin
TEMPLATE = lib
CONFIG += plugin

CONFIG += c++17
DEFINES += UIPLUGIN_LIBRARY

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
        uiplugin.cpp \
    tools/HashString/HashString.cpp \
    tools/pluginmanager/pluginlist.cpp \
    tools/pluginmanager/pluginmanager.cpp \

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
#QML_IMPORT_PATH = /home/zmjwangxueyuan/3_myproject/5_project/vendor/zmos/common/buildroot/output/host/aarch64-buildroot-linux-gnu/sysroot/usr/qml


# Additional import path used to resolve QML modules just for Qt Quick Designer
#QML_DESIGNER_IMPORT_PATH =

HEADERS += \
        uiplugin.h \
    tools/plugininterface/plugininterface.h \
    tools/HashString/HashString.h \
    tools/pluginmanager/pluginlist.h \
    tools/pluginmanager/pluginmanager.h \

#unix {
#    target.path = /usr/lib
#    INSTALLS += target
#}
target.path = /home/3568/plugins
INSTALLS += target

DISTFILES += \
    UiPlugin.json
