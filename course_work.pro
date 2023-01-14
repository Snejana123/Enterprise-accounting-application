QT       += core gui

# QT_USE_NATIVE_WINDOWS = 1

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cashdeskhbox.cpp \
    cashdeskswindow.cpp \
    cashwidget.cpp \
    controlwidget.cpp \
    controlwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    settingswidget.cpp \
    settingswindow.cpp

HEADERS += \
    cashdeskhbox.h \
    cashdeskswindow.h \
    cashwidget.h \
    controlwidget.h \
    controlwindow.h \
    mainwindow.h \
    settingswidget.h \
    settingswindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    images/appIcon.png

RESOURCES += \
    application.qrc
