cmake_minimum_required(VERSION 3.5)
project(Tetris_COMMON LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors")

# Définir les fichiers sources
set(COMMON
		Observable.h
		Observable.cpp
		Observer.h
		ActionType.h
)

# Créer une bibliothèque statique
add_library(Tetris_COMMON STATIC ${COMMON})
