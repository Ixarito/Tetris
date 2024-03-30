#include "Game.h"

namespace tetris::model{

	Game::Game(GameParameters params):
		_grid(params.gridWidth, params.gridHeight, params.nbAlreadyPlacedBlocks),
		_bag{Bag::getInstance()},
		_level{params.level},
		score{}
	{
		if(params.shapes.empty()) throw "Please specify tetrominoes to play";

		for(auto tetromino: params.shapes){
			_bag.add(tetromino);
		}
	}

	bool Game::isGameOver() const{
		return false; // TODO
	}

	bool Game::isWon() const{
		return false;
	}

	const unsigned long long int & Game::getScore() const{
		return score;
	}

	const int & Game::getLevel() const{
		return _level;
	}

	void Game::goDown(){
		_grid.moveCurrent(MoveDirection::DOWN);
	}

	void Game::goLeft(){
		_grid.moveCurrent(MoveDirection::LEFT);
	}

	void Game::goRight(){
		_grid.moveCurrent(MoveDirection::RIGHT);
	}

	void Game::rotateClockwise(){
		_grid.rotateCurrent(RotateDirection::CW);
	}

	void Game::rotateCounterclockwise(){
		_grid.rotateCurrent(RotateDirection::CCW);
	}

	void Game::drop(){
		_grid.dropCurrent();
	}

} // namespace tetris::model


