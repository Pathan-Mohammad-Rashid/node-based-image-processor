# QT       += core gui

# greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# CONFIG += c++17

# # You can make your code fail to compile if it uses deprecated APIs.
# # In order to do so, uncomment the following line.
# #DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# SOURCES += \
#     main.cpp \
#     mainwindow.cpp

# HEADERS += \
#     mainwindow.h

# FORMS += \
#     mainwindow.ui

# TRANSLATIONS += \
#     node_image_editor_en_IN.ts
# CONFIG += lrelease
# CONFIG += embed_translations

# # Default rules for deployment.
# qnx: target.path = /tmp/$${TARGET}/bin
# else: unix:!android: target.path = /opt/$${TARGET}/bin
# !isEmpty(target.path): INSTALLS += target


QT       += widgets
CONFIG   += c++14 console
TEMPLATE = app
TARGET   = node_image_editor

# OpenCV include & libs
INCLUDEPATH += C:/opencv/build/include
LIBS        += -LC:/opencv/build/x64/vc15/lib \
               -lopencv_core452 \
               -lopencv_imgcodecs452 \
               -lopencv_imgproc452

SOURCES += \
    src/main.cpp \
    src/MainWindow.cpp \
    src/Node.cpp \
    src/NodeGraph.cpp \
    src/nodes/InputNode.cpp \
    src/nodes/OutputNode.cpp

HEADERS += \
    NodeModel.h \
    src/MainWindow.h \
    src/NodeModel.h \
    src/Node.h \
    src/NodeGraph.h \
    src/nodes/InputNode.h \
    src/nodes/OutputNode.h
