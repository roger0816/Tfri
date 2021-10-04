
QT       += core sql network


QT -= gui


CONFIG += console c++11
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


#include(../RLib/RLib/include/RLib.pri)

win32: LIBS += -L$$PWD/../libs/RLib/ -lRLibQt5Win

INCLUDEPATH += $$PWD/../libs/RLib/include
DEPENDPATH += $$PWD/../libs/RLib/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../libs/RLib/RLibQt5Win.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../libs/RLib/libRLibQt5Win.a

DESTDIR = $$PWD/../bin/


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH +=../common

SOURCES += \
        ../libs/upng-master/upng.c \
        CQueryData.cpp \
        ../common/CSqlClass.cpp \
        Launch.cpp \
        main.cpp



HEADERS += \
    ../common/CDefine.h \
    ../libs/upng-master/upng.h \
    CQueryData.h \
    ../common/CSqlClass.h \
    Launch.h

INCLUDEPATH+= ../libs/upng-master



OBJECTS_DIR = $$PWD/obj
MOC_DIR = $$PWD/obj
UI_DIR = $$PWD/obj/ui_header








unix:!macx: LIBS += -L$$PWD/../libs/RLib/ -lRLibQt5Embedded

INCLUDEPATH += $$PWD/../libs/RLib/include
DEPENDPATH += $$PWD/../libs/RLib/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../libs/RLib/libRLibQt5Embedded.a
