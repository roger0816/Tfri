#-------------------------------------------------
#
# Project created by QtCreator 2016-08-15T17:47:13
#
#-------------------------------------------------

#QT       += widgets

#QT       += gui

TARGET = RLib
TEMPLATE = lib
CONFIG += staticlib





win32{
OS=Win
}
unix:!macx{

linux-arm-gnueabi {
    OS=Embedded
}

#OS=Linux
OS=Embedded
}
mac:!macx{
OS=Ios
}
macx{
#QMAKE_MAC_SDK = macosx10.12
OS=Osx
}
android{
OS=Android
}

TARGET = $${TARGET}Qt$$QT_MAJOR_VERSION$${OS}




include(../include/RLib.pri)

DESTDIR = $$PWD/../
OBJECTS_DIR = $$PWD/obj
MOC_DIR = $$PWD/obj
UI_DIR = $$PWD/obj/ui_header


INCLUDEPATH +=$$PWD/../include/




SOURCES += \
    network/CTcpClient.cpp \
    network/CTcpServer.cpp \
    network/Network.cpp \
    database/DataBase.cpp \
    database/CSql.cpp \
    ipc/Ipc.cpp \
    ipc/CLocalServer.cpp \
    ipc/CLocalClient.cpp \
    utility/Utility.cpp \
    Library.cpp
#    ui/LayerWheel.cpp \
#    ui/LayerScrollView.cpp \
#    ui/ItemSelectNumber.cpp \
#    ui/LayerKeyborad.cpp \
#    ui/ItemLineEdit.cpp \
#    utility/GlobalBase.cpp \
#    ui/LayerBlock.cpp \
#    ui/ItemLoadingBarA.cpp





unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \

HEADERS += \
    database/CSql.h \
    network/CTcpClient.h \
    network/CTcpServer.h \
    ipc/CLocalServer.h \
    ipc/CLocalClient.h


#FORMS += \
#    ui/LayerKeyborad.ui \
#    ui/LayerBlock.ui












