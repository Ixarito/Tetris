cmake_minimum_required(VERSION 3.5)
project(Tetris_view_console LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors")


# Définir les fichiers sources
set(SOURCES
    BasicDisplay.h
    BasicDisplay.cpp
)

# Créer une bibliothèque statique
add_library(Tetris_view_console STATIC ${SOURCES})
