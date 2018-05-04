#-------------------------------------------------
#
# Project created by QtCreator 2018-04-08T10:44:38
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SafeHarbour
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
    LoginWindow.cpp \
    Authentication.cpp \
    AdminPanel.cpp \
    AdminAddHarbour.cpp \
    AdminGeo.cpp \
    AdminEditHarbour.cpp \
    AdminAddClient.cpp \
    AdminCorporation.cpp \
    AdminEditClient.cpp \
    AdminAddManager.cpp \
    AdminEditManager.cpp

HEADERS += \
    LoginWindow.h \
    Authentication.h \
    AdminPanel.h \
    AdminAddHarbour.h \
    AdminGeo.h \
    AdminEditHarbour.h \
    AdminAddClient.h \
    AdminCorporation.h \
    AdminEditClient.h \
    AdminAddManager.h \
    AdminEditManager.h

FORMS += \
    LoginWindow.ui \
    AdminPanel.ui \
    AdminAddHarbour.ui \
    AdminGeo.ui \
    AdminEditHarbour.ui \
    AdminAddClient.ui \
    AdminCorporation.ui \
    AdminEditClient.ui \
    AdminAddManager.ui \
    AdminEditManager.ui

RESOURCES += \
    gfx.qrc
