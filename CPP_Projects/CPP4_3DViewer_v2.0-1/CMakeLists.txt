# CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
find_program(VALGRIND_EXECUTABLE valgrind)
project(CPP4_3DViewer_v2.0-1 CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(src/3DViewer)


find_package(Qt6Widgets REQUIRED)
find_package(Qt6 COMPONENTS Core Widgets PrintSupport OpenGL OpenGLWidgets REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


# Define the main executable target
add_executable(CPP4_3DViewer_v2.0-1
        src/Backend/data.h
        src/Backend/file.h
        src/3DViewer/OpenGLWidget.cc
        src/3DViewer/main.cc
        src/Backend/data.cc
        src/Backend/model.h
        src/Backend/model.cc
        src/Backend/file.cc
        src/3DViewer/view.h
        src/3DViewer/view.cc
        src/Backend/affine_facade.h
        src/3DViewer/OpenGLWidget.h
        src/Backend/scaling.cc
)

target_include_directories(CPP4_3DViewer_v2.0-1 PRIVATE src src/3DViewer)
target_link_libraries(CPP4_3DViewer_v2.0-1 PRIVATE Qt6::Core  Qt6::OpenGLWidgets Qt6::Widgets Qt6::OpenGL  #[[Qt5::Quick]]  Qt6::PrintSupport  -lm -lsubunit -pthread)

target_compile_options(CPP4_3DViewer_v2.0-1 PRIVATE
        -Wall
        -Wextra
        -Werror
        -std=c++17
)