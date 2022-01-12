QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

win32: LIBS += -L$$PWD/../libs/RLib/ -lRLibQt5Win

INCLUDEPATH += $$PWD/../libs/RLib/include
DEPENDPATH += $$PWD/../libs/RLib/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../libs/RLib/RLibQt5Win.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../libs/RLib/libRLibQt5Win.a

DESTDIR = $$PWD/../bin
OBJECTS_DIR = $$PWD/obj
MOC_DIR = $$PWD/obj
UI_DIR = $$PWD/obj/ui_header



INCLUDEPATH +=../common

DESTDIR = $$PWD/../bin/

SOURCES += \
    ../common/CQueryData.cpp \
    ../common/CSqlClass.cpp \
    ../common/DialogMsg.cpp \
    CCallApi.cpp \
    DialogDetail.cpp \
    DialogSelectFilter.cpp \
    DialogUser.cpp \
    Global.cpp \
    LayerLoadingLock.cpp \
    WTableAnalyze.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    ../common/CDefine.h \
    ../common/CQueryData.h \
    ../common/CSqlClass.h \
    ../common/DialogMsg.h \
    CCallApi.h \
    DialogDetail.h \
    DialogSelectFilter.h \
    DialogUser.h \
    Global.h \
    LayerLoadingLock.h \
    WTableAnalyze.h \
    widget.h

FORMS += \
    ../common/DialogMsg.ui \
    DialogDetail.ui \
    DialogSelectFilter.ui \
    DialogUser.ui \
    LayerLoadingLock.ui \
    WTableAnalyze.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../bin/serverRun.sh

RESOURCES += \
    res/res.qrc



