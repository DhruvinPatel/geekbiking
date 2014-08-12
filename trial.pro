#-------------------------------------------------
#
# Project created by QtCreator 2013-08-12T23:54:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = trial
TEMPLATE = app


SOURCES += \
    sources/scores.cpp \
    sources/quit.cpp \
    sources/newgame3.cpp \
    sources/newgame2.cpp \
    sources/newgame1.cpp \
    sources/name.cpp \
    sources/main.cpp \
    sources/help.cpp \
    sources/credits.cpp \
    sources/buttons.cpp \
    sources/vec3f.cpp \
    sources/terr.cpp \
    sources/render.cpp \
    sources/physics.cpp \
    sources/obj.cpp \
    sources/imageloader.cpp \
    sources/hud.cpp \
    sources/glm.cpp \
    sources/Game.cpp

HEADERS  += \
    sources/scores.h \
    sources/quit.h \
    sources/newgame3.h \
    sources/newgame2.h \
    sources/newgame1.h \
    sources/name.h \
    sources/help.h \
    sources/credits.h \
    sources/buttons.h \
    sources/vec3f.h \
    sources/terr.h \
    sources/render.h \
    sources/physics.h \
    sources/obj.h \
    sources/Kollision.h \
    sources/imageloader.h \
    sources/hud.h \
    sources/glm.h \
    sources/Game.h \
    sources/box.h

FORMS    += \
    sources/scores.ui \
    sources/quit.ui \
    sources/newgame3.ui \
    sources/newgame2.ui \
    sources/newgame1.ui \
    sources/name.ui \
    sources/help.ui \
    sources/credits.ui \
    sources/buttons.ui

RESOURCES += \
    sources/resources.qrc

unix:!macx: LIBS += -lGL

unix:!macx: LIBS += -lGLU

unix:!macx: LIBS += -lglut

win32: LIBS += -lglui32

win32: LIBS += -lglut32

win32: LIBS += -lOPENGL32

win32: LIBS += -lGLU32

win32: LIBS += -lGlaux

OTHER_FILES +=
