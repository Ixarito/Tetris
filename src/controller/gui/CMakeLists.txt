cmake_minimum_required(VERSION 3.5)
project(Tetris_controller_GUI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Inclure les répertoires des bibliothèques Tetris
include_directories(../)
include_directories(../../common)
include_directories(../../model)
include_directories(../../view/gui)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

# Définir les fichiers sources
set(SOURCES
        GameController.cpp
        GameController.h
		MenuController.cpp
		MenuController.h
		../GameType.h
		../ValueToReach.h
)

# Créer une bibliothèque statique
add_library(Tetris_controller_GUI STATIC ${SOURCES})

target_link_libraries(Tetris_controller_GUI
        Qt::Core
        Qt::Gui
        Qt::Widgets
)