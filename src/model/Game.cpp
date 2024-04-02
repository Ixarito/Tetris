#include <iostream>
#include "Game.h"

namespace tetris::model{

	Game::Game(const GameParameters & params):
		_grid(params.gridWidth, params.gridHeight, params.nbAlreadyPlacedBlocks),
		_bag{Bag::getInstance()},
		_level{params.level},
		score{}
	{
		if(params.shapes.empty()) throw "Please specify tetrominoes to play";

		for(auto & tetromino : params.shapes){
			_bag.add(tetromino);
		}

		/// TODO don't do that, yes, yes, do that beacause why don't do that !?
		_grid.insert(_bag.getNext());
	}

	bool Game::isGameActive() const{
		return _grid.isOnTop();
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

    std::vector<Line> Game::getGridView() const {
        return _grid.getGridView();
    }

	void Game::goDown(){
		_grid.moveCurrent(MoveDirection::DOWN);
        if (!_grid.canMove(MoveDirection::DOWN)){
            _grid.insert(_bag.getNext());
            score+=_grid.removeFullLines();
        }
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
		score += _grid.dropCurrent();
		_grid.insert(_bag.getNext());
        score+=_grid.removeFullLines();
	}


} // namespace tetris::model


