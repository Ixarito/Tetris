cmake_minimum_required(VERSION 3.5)
project(tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors")

# Vérifier si le sous-module Google Test est initialisé
if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/googletest/CMakeLists.txt")
    message(STATUS "Submodule 'googletest' n'est pas initialisé. Initialisation...")
    execute_process(COMMAND git submodule init
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
    execute_process(COMMAND git submodule update
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
endif()

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Inclure le répertoire de la bibliothèque Tetris_model
include_directories(../src/model)

add_executable(tests main.cpp
        TetrominoTestUtils.hpp
        BlockTestUtils.hpp
        LineTest.cpp)

# Lier les bibliothèques Google Test et Tetris_model
target_link_libraries(tests gtest gtest_main Tetris_model)
