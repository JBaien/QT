# 如果QT的版本大于4，则需要添加Widgets模块
greaterThan(QT_MAJOR_VERSION, 4):QT += widgets

SOURCES += \
    main.cpp

FORMS += \
    hellodialog.ui
