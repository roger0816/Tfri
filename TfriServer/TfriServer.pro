
QT       += core sql network


QT -= gui


CONFIG += console c++11
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


#include(../RLib/RLib/include/RLib.pri)

win32: LIBS += -L$$PWD/../RLib/RLib/ -lRLibQt5Win

INCLUDEPATH += $$PWD/../RLib/RLib/include
DEPENDPATH += $$PWD/../RLib/RLib/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../RLib/RLib/RLibQt5Win.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../RLib/RLib/libRLibQt5Win.a

DESTDIR = $$PWD/../bin/


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SOURCES += \
        ../libs/upng-master/upng.c \
        CQueryData.cpp \
        CSqlClass.cpp \
        Launch.cpp \
        main.cpp



HEADERS += \
    ../common/CDefine.h \
    ../libs/upng-master/upng.h \
    CQueryData.h \
    CSqlClass.h \
    Launch.h

INCLUDEPATH+= ../libs/upng-master








