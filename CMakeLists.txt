cmake_minimum_required(VERSION 3.5)

project(Tetris)

add_subdirectory(src/model)

add_subdirectory(src/view/console)

add_subdirectory(src/controller/console)

add_subdirectory(tests)
