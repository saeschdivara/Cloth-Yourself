#-------------------------------------------------
#
# Project created by QtCreator 2014-01-27T20:43:39
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = MyLoves_ClothingApp
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    ClothingWebsite.cpp \
    views/IndexView.cpp \
    models/ClothModel.cpp \
    models/ClothingTimeModel.cpp \
    views/ClothingTimeView.cpp

HEADERS += \
    ClothingWebsite.h \
    views/IndexView.h \
    models/ClothModel.h \
    models/ClothingTimeModel.h \
    views/ClothingTimeView.h

OTHER_FILES += \
    templates/index.html \
    templates/ClothingTimeView.html \
    templates/base.html

QMAKE_CXXFLAGS += -std=c++11
CONFIG += c++11

CONFIG(release, debug|release): {
    LIBS += -L$$PWD/../Public-Server-System/dist/3rdparty/tufao/release/ -ltufao
    LIBS += -L$$PWD/../Public-Server-System/dist/3rdparty/arangodb-driver/release/ -larangodb-driver
    LIBS += -L$$PWD/../Public-Server-System/dist/3rdparty/grantlee/template_library/release/ -ltemplate_library
    LIBS += -L$$PWD/../Public-Server-System/dist/Public-Server-System/release/ -lPublic-Server-System
}
else:CONFIG(debug, debug|release): {
    LIBS += -L$$PWD/../Public-Server-System/dist/3rdparty/tufao/debug/ -ltufao
    LIBS += -L$$PWD/../Public-Server-System/dist/3rdparty/arangodb-driver/debug/ -larangodb-driver
    LIBS += -L$$PWD/../Public-Server-System/dist/3rdparty/grantlee/template_library/debug/ -ltemplate_library
    LIBS += -L$$PWD/../Public-Server-System/dist/Public-Server-System/debug/ -lPublic-Server-System
}

INCLUDEPATH += $$PWD/../Public-Server-System/3rdparty/tufao/src
DEPENDPATH += $$PWD/../Public-Server-System/3rdparty/tufao/src

INCLUDEPATH += $$PWD/../Public-Server-System/3rdparty/arangodb-driver/src
DEPENDPATH += $$PWD/../Public-Server-System/3rdparty/arangodb-driver/src

INCLUDEPATH += $$PWD/../Public-Server-System/3rdparty/grantlee/templates/
DEPENDPATH += $$PWD/../Public-Server-System/3rdparty/grantlee/templates/

INCLUDEPATH += $$PWD/../Public-Server-System/src/
DEPENDPATH += $$PWD/../Public-Server-System/src/
