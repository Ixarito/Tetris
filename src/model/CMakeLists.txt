cmake_minimum_required(VERSION 3.5)
project(Tetris_model LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors")

# Définir les fichiers sources
set(SOURCES
		Block.h
		Color.h
		RotateDirection.h
		MoveDirection.h
		Tetromino.h
		Line.h
		Bag.h
		Grid.h
		Game.h
		GameTypeLines.h
		GameTypeScore.h
		GameTypeTime.h
		Block.cpp
		Tetromino.cpp
		Line.cpp
		util/maxVectorSize.hpp
		Bag.cpp
		Game.cpp
		GameTypes.cpp
		Grid.cpp
		util/outOfRangeMessage.hpp
		util/random.hpp
)

# Créer une bibliothèque statique
add_library(Tetris_model STATIC ${SOURCES})
