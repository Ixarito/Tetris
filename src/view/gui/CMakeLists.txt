cmake_minimum_required(VERSION 3.5)
project(Tetris_view_console LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

include_directories(../../model)
#include_directories(../../controller/gui)

add_executable(Tetris_view_GUI
		mainwindow.h
		mainwindow.cpp
		mainwindow.ui
)

target_link_libraries(Tetris_view_GUI PRIVATE Tetris_model Tetris_view_console Qt${QT_VERSION_MAJOR}::Widgets)
