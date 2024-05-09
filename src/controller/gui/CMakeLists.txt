cmake_minimum_required(VERSION 3.5)
project(Tetris_controller_console LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors")

# Inclure les répertoires des bibliothèques Tetris
include_directories(../../model)
include_directories(../../view/gui)

# Définir les fichiers sources
set(SOURCES
        GameController.cpp
        GameController.h
)

# Créer une bibliothèque statique
add_library(Tetris_controller_GUI STATIC ${SOURCES})