QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

unix:LIBS += -L /usr/lib64 -lglfw -L/usr/lib64/GL -lGL -lSDL2 -lGLEW -lSDL2_image -lfreetype

SOURCES += \
    Animate/animate.cpp \
    base2d/base2d.cpp \
    baseobject/baseobject.cpp \
    buttons/button.cpp \
    camera/camera.cpp \
    cube/colorcube.cpp \
    cube/cube.cpp \
    fileutils/fileutil.cpp \
    imageloader/loadimage.cpp \
    initgl.cpp \
    landscape/landscape.cpp \
    lights/light.cpp \
    logs/logs.cpp \
    main.cpp \
    monitors.cpp \
    mouse.cpp \
    projection/projection.cpp \
    shaders/shader.cpp \
    textrenderer/textrender.cpp \
    utils/utils.cpp \
    vecmath/vecmath.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../master/defaults.h \
   Animate/animate.h \
    base2d/base2d.h \
    baseobject/baseobject.h \
    buttons/button.h \
    camera/camera.h \
    cube/colorcube.h \
    cube/cube.h \
    defines.h \
    fileutils/fileutil.h \
    imageloader/loadimage.h \
    initgl.h \
    landscape/landscape.h \
    lights/light.h \
    logs/logs.h \
    monitors.h \
    mouse.h \
    projection/projection.h \
    shaders/shader.h \
    shaders/shader.h \
    textrenderer/textrender.h \
    utils/utils.h \
    vecmath/vecmath.h

DISTFILES += \
    ShaderSources/FogShaderExample.txt \
    ShaderSources/colorshader.frg \
    ShaderSources/cubefragmentshaderMulti.frg \
    ShaderSources/cubefragmentshaderMultinormals.frg \
    ShaderSources/cubevertexnormalshader.vex \
    ShaderSources/cubevertexshader.vex \
    ShaderSources/fogfragmentshader.frg \
    ShaderSources/fogvertexshader.vex \
    ShaderSources/fragmentnormalcolorshader.frg \
    ShaderSources/vertexnormalcolorshader.vex
