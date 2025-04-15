cmake_minimum_required(VERSION 3.5)
project(node_image_editor)

set(CMAKE_CXX_STANDARD 14)
find_package(Qt5Widgets REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(${Qt5Widgets_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS})

file(GLOB SRC
    src/*.cpp
    src/nodes/*.cpp
)

add_executable(node_editor ${SRC})
target_link_libraries(node_editor Qt5::Widgets ${OpenCV_LIBS})
