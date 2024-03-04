cmake_minimum_required(VERSION 3.5)

project(Tetris_model LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors")

add_executable(Tetris_model
		main.cpp
		Block.h
		Color.h
		RotateDirection.h MoveDirection.h
		Tetromino.h
		Line.h
		Bag.h
		Grid.h
		Game.h GameTypeLines.h GameTypeScore.h GameTypeTime.h
        Block.cpp
		Tetromino.cpp
		Line.cpp
)

include(GNUInstallDirs)
install(TARGETS Tetris_model
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
