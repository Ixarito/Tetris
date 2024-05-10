#include "Game.h"
#include <random>
#include <algorithm>

namespace tetris::model{

	Game::Game(const GameParameters & params):
		_grid(params.gridWidth, params.gridHeight, params.nbAlreadyPlacedBlocks),
		_bag{},
		_nextTetromino{},
		_level{params.level},
		score{},
		nbClearedLines{}
	{
		if(params.shapes.empty()) throw std::invalid_argument("Please specify tetrominoes to play");

		for(const auto & tetromino: params.shapes){
			_bag.emplace_back(tetromino);
		}
		shuffleBag();


		_grid.insert(getNext());
	}

	bool Game::isGameActive() const{
		return _grid.isOnTop();
	}

	bool Game::isWon() const{
		return false;
	}

	Tetromino Game::getNext() {
		auto next = _bag[_nextTetromino];
		_nextTetromino = (_nextTetromino + 1) % _bag.size();
		if(_nextTetromino == 0) shuffleBag();
		return next;
	}

	const Tetromino & Game::peekNext() const {
		return _bag[_nextTetromino];
	}

	void Game::shuffleBag(){
		std::random_device rd;
		std::mt19937 g(rd());
		std::ranges::shuffle(_bag, g);
	}

	const unsigned long long int & Game::getScore() const{
		return score;
	}

	const unsigned int & Game::getLevel() const{
		return _level;
	}

    const unsigned int & Game::getNbClearedLines() const{
        return nbClearedLines;
    }

    Grid::GridView_type Game::getGridView() const {
        return _grid.getGridView();
    }

	void Game::goDown(){
		_grid.moveCurrent(MoveDirection::DOWN);
        if (!_grid.canMove(MoveDirection::DOWN)){ // FIXME call to drop?
            _grid.insert(getNext());

			auto nbLinesRemoved = _grid.removeFullLines();

			updateData(nbLinesRemoved);
        }

		endMovement();
	}

	void Game::goLeft(){
		_grid.moveCurrent(MoveDirection::LEFT);

		endMovement();
	}

	void Game::goRight(){
		_grid.moveCurrent(MoveDirection::RIGHT);

		endMovement();
	}

	void Game::rotateClockwise(){
		_grid.rotateCurrent(RotateDirection::CW);

		endMovement();
	}

	void Game::rotateCounterclockwise(){
		_grid.rotateCurrent(RotateDirection::CCW);

		endMovement();
	}

	void Game::drop(){
		auto nbLinesCrossed =  _grid.dropCurrent();
		auto nbLinesRemoved = _grid.removeFullLines();
		_grid.insert(getNext());

		updateData(nbLinesRemoved, nbLinesCrossed);
	}

	using namespace common;

	void Game::updateData(size_t nbLinesRemoved, size_t nbLinesCrossed){
		score += nbLinesRemoved + nbLinesCrossed;
		nbClearedLines += nbLinesRemoved;
		_level = nbClearedLines/10;

		notifyObservers(ActionType::DATA_UPDATED, this);
	}

	void Game::endMovement(){
		notifyObservers(ActionType::GRID_CHANGED, this);
	}


} // namespace tetris::model


