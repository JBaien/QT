#-------------------------------------------------
#
# Project created by QtCreator 2024-03-30T16:04:48
#
#-------------------------------------------------

QT += gui
QT += quick

TARGET = CommCANPlugin
TEMPLATE = lib
CONFIG += plugin

CONFIG += c++11
DEFINES += COMMCANPLUGIN_LIBRARY

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
        commcanplugin.cpp \
    tools/HashString/HashString.cpp \
    tools/pluginmanager/pluginlist.cpp \
    tools/pluginmanager/pluginmanager.cpp

HEADERS += \
        commcanplugin.h \
    tools/plugininterface/plugininterface.h \
    tools/HashString/HashString.h \
    tools/pluginmanager/pluginlist.h \
    tools/pluginmanager/pluginmanager.h

#unix {
#    target.path = /usr/lib
#    INSTALLS += target
#}
target.path = /home/CXH12/plugins
INSTALLS += target

DISTFILES += \
    CommCANPlugin.json
