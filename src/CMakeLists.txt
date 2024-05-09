cmake_minimum_required(VERSION 3.5)

project(Tetris_sources)

add_subdirectory(model)

add_subdirectory(view/console)
add_subdirectory(view/gui)

add_subdirectory(controller/console)
add_subdirectory(controller/gui)
