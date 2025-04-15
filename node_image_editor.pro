QT       += widgets
CONFIG   += c++14 console
TEMPLATE = app
TARGET   = node_image_editor

# OpenCV include & libs
INCLUDEPATH += C:/opencv/build/include
LIBS        += -LC:\opencv\build\x64\vc16\lib \
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
    src/MainWindow.h \
    src/NodeModel.h \
    src/Node.h \
    src/NodeGraph.h \
    src/nodes/InputNode.h \
    src/nodes/OutputNode.h
