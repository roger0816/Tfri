QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DESTDIR = $$PWD/../bin/

SOURCES += \
    main.cpp \
    widget.cpp

HEADERS += \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


include(../RLib/RLib/include/RLib.pri)

win32: LIBS += -L$$PWD/../RLib/RLib/ -lRLibQt5Win

INCLUDEPATH += $$PWD/../RLib/RLib/include
DEPENDPATH += $$PWD/../RLib/RLib/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../RLib/RLib/RLibQt5Win.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../RLib/RLib/libRLibQt5Win.a
