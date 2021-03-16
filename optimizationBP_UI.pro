QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Math/Function.cpp \
    Math/area.cpp \
    Math/gradientDescent.cpp \
    Math/optimizationMethod.cpp \
    Math/randomSearch.cpp \
    Math/stopCrit.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    Math/Function.h \
    Math/area.h \
    Math/gradientDescent.h \
    Math/optimizationMethod.h \
    Math/randomSearch.h \
    Math/stopCrit.h \
    mainwindow.h \
    qcustomplot.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
