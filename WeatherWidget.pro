QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += "WeatherState"

SOURCES += \
    NetworkMananger.cpp \
    WeatherState/CloudState.cpp \
    WeatherState/LightingState.cpp \
    WeatherState/RainState.cpp \
    WeatherState/SunState.cpp \
    WeatherState/BlobComponent.cpp \
    GradientWidget.cpp \
    components/InputCityDialog.cpp \
    main.cpp \
    mainwindow.cpp \
    components/PixmapClickable.cpp \
    components/TextClick.cpp

HEADERS += \
    NetworkMananger.h \
    QueryDataStruct.h \
    WeatherState/CloudState.h \
    WeatherState/LightingState.h \
    WeatherState/RainState.h \
    WeatherState/SunState.h \
    WeatherState/BlobComponent.h \
    GradientWidget.h \
    components/InputCityDialog.h \
    mainwindow.h \
    components/PixmapClickable.h \
    components/TextClick.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
