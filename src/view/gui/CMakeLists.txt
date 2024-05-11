cmake_minimum_required(VERSION 3.5)
project(Tetris_view_GUI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Inclure les répertoires des bibliothèques Tetris
include_directories(../../common)
include_directories(../../model)
include_directories(../../controller/gui)
include_directories(.)

find_package(Qt6 COMPONENTS
		Core
		Gui
		Widgets
		REQUIRED)

add_executable(Tetris_view_GUI
		main.cpp
		TetrisScene.cpp
		TetrisScene.h
        MainWindow.cpp
        MainWindow.h
)

target_link_libraries(Tetris_view_GUI
		Qt::Core
		Qt::Gui
		Qt::Widgets
		Tetris_COMMON
		Tetris_model
		Tetris_controller_GUI
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
	set(DEBUG_SUFFIX)
	if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
		set(DEBUG_SUFFIX "d")
	endif ()
	set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
	if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
		set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
		if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
			set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
		endif ()
	endif ()
	if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
		add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
				COMMAND ${CMAKE_COMMAND} -E make_directory
				"$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
		add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
				COMMAND ${CMAKE_COMMAND} -E copy
				"${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
				"$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
	endif ()
	foreach (QT_LIB Core Gui Widgets)
		add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
				COMMAND ${CMAKE_COMMAND} -E copy
				"${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
				"$<TARGET_FILE_DIR:${PROJECT_NAME}>")
	endforeach (QT_LIB)
endif ()
