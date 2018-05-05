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
    GUI/AdminAddClient.cpp \
    GUI/AdminAddHarbour.cpp \
    GUI/AdminAddManager.cpp \
    GUI/AdminCorporation.cpp \
    GUI/AdminEditClient.cpp \
    GUI/AdminEditHarbour.cpp \
    GUI/AdminEditManager.cpp \
    GUI/AdminGeo.cpp \
    GUI/AdminPanel.cpp \
    AuxClass/Authentication.cpp \
    GUI/ClientPanel.cpp \
    GUI/LoginWindow.cpp \
    GUI/ManagerPanel.cpp \
    main.cpp

HEADERS += \
    GUI/AdminAddClient.h \
    GUI/AdminAddHarbour.h \
    GUI/AdminAddManager.h \
    GUI/AdminCorporation.h \
    GUI/AdminEditClient.h \
    GUI/AdminEditHarbour.h \
    GUI/AdminEditManager.h \
    GUI/AdminGeo.h \
    GUI/AdminPanel.h \
    AuxClass/Authentication.h \
    GUI/ClientPanel.h \
    GUI/LoginWindow.h \
    GUI/ManagerPanel.h

FORMS += \
    GUI/AdminAddClient.ui \
    GUI/AdminAddHarbour.ui \
    GUI/AdminAddManager.ui \
    GUI/AdminCorporation.ui \
    GUI/AdminEditClient.ui \
    GUI/AdminEditHarbour.ui \
    GUI/AdminEditManager.ui \
    GUI/AdminGeo.ui \
    GUI/AdminPanel.ui \
    GUI/ClientPanel.ui \
    GUI/LoginWindow.ui \
    GUI/ManagerPanel.ui

RESOURCES += \
    gfx.qrc \
