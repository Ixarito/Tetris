cmake_minimum_required(VERSION 3.5)
project(Tetris_controller_console LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors")

# Inclure les répertoires des bibliothèques Tetris
include_directories(../../model)
include_directories(../../view/console)

add_executable(Tetris_controller_console
        main.cpp
        GameType.h
        Interactions.cpp
        Interactions.h
        Controller.cpp
        Controller.h
)

# Lier les bibliothèques Tetris
target_link_libraries(Tetris_controller_console Tetris_model Tetris_view_console Tetris_COMMON)
