#-------------------------------------------------
#
# Project created by QtCreator 2017-01-27T18:13:16
#
#-------------------------------------------------

QT       += core gui webenginewidgets websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = desktop-shell
TEMPLATE = app

LIBS += -framework CoreData -framework Foundation -framework AppKit

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp \
           mainwindow.cpp \
           webengineview.cpp \
           notification.cpp \
    applicationcontroller.cpp

macx {
    OBJECTIVE_SOURCES += nativeprogressbar_mac.mm \
                         progressbar_mac.mm
}

HEADERS  += mainwindow.h \
            webengineview.h \
            progressbar.h \
            notification.h \
    applicationcontroller.h
