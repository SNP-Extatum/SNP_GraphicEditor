QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS   += -lopengl32
# LIBS   += -lglut32
LIBS   += -lGLU32



SOURCES += \
    cube.cpp \
    figure.cpp \
    form_about.cpp \
    form_cube.cpp \
    main.cpp \
    mainscene.cpp \
    mainwindow.cpp \
    modulecamera.cpp \
    vec2.cpp \
    vec3.cpp \
    vecfunctions.cpp

HEADERS += \
    cube.hpp \
    figure.hpp \
    form_about.hpp \
    form_cube.hpp \
    mainscene.hpp \
    mainwindow.hpp \
    modulecamera.hpp \
    settings.hpp \
    vec2.hpp \
    vec3.hpp \
    vecfunctions.hpp

FORMS += \
    form_about.ui \
    form_cube.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
