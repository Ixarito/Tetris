#include "Game.h"
#include <random>
#include <algorithm>

namespace tetris::model{

	using common::ActionType;

	Game::Game(const GameParameters & params):
			_grid(params.gridWidth, params.gridHeight, params.nbAlreadyPlacedBlocks),
			_bag{},
			_nextTetromino{},
			_currentPosition{},
			_gameOver{false},
			_startLevel{params.level},
			_currentLevel{params.level},
			score{},
			nbClearedLines{}
	{
		if(params.shapes.empty()) throw std::invalid_argument("Please specify tetrominoes to play");

		for(const auto & tetromino: params.shapes){
			_bag.emplace_back(tetromino);
		}
		shuffleBag();


		insert(getNext());
	}

	bool Game::isGameOver() const{
		return _gameOver;
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
		return _currentLevel;
	}

    const unsigned int & Game::getNbClearedLines() const{
        return nbClearedLines;
    }

    Game::GridView_type Game::getGridView() const {
        std::vector<Line> gridView;
		for (auto &line: _grid) {
			gridView.push_back(*line);
		}

		if (_current.has_value()) {
			// getWidth and getHeight are long methods so declare before
			auto tetroWidth{_current->getWidth()};
			auto tetroHeight{_current->getHeight()};

			for (size_t x = 0; x < tetroWidth; x++) {
				for (size_t y = 0; y < tetroHeight; y++) {
					if (_current->isOccupied(x, y)) {
						gridView[_currentPosition.row + y].set(_currentPosition.col + x, _current->get(x, y));
					}
				}
			}
		}
		return gridView;
    }

	void Game::goDown(){
		moveCurrent(MoveDirection::DOWN);
        if (!canMove(MoveDirection::DOWN)){ // FIXME call to drop?
            insert(getNext());

			auto nbLinesRemoved = _grid.removeFullLines();

			updateData(nbLinesRemoved);
        }
	}

	void Game::goLeft(){
		moveCurrent(MoveDirection::LEFT);
	}

	void Game::goRight(){
		moveCurrent(MoveDirection::RIGHT);
	}

	void Game::rotateClockwise(){
		rotateCurrent(RotateDirection::CW);

		endMovement();
	}

	void Game::rotateCounterclockwise(){
		rotateCurrent(RotateDirection::CCW);

		endMovement();
	}

	void Game::checkGameOver() {
		if(_currentPosition.row == 0 && isCurrentOverlap()){
			_gameOver = true;

			notifyObservers(ActionType::GAME_OVER, this);
		}
	}

	void Game::drop(){
		size_t nbLinesCrossed{};
		while (canMove(MoveDirection::DOWN)) {
			moveCurrent(MoveDirection::DOWN);
			nbLinesCrossed++;
		}
		placeCurrent();

		auto nbLinesRemoved = _grid.removeFullLines();
		insert(getNext());

		updateData(nbLinesRemoved, nbLinesCrossed);
	}

	void Game::insert(Tetromino tetromino) {
		_current = tetromino;
		_currentPosition.col = _grid.width / 2 - tetromino.getWidth() / 2;
		_currentPosition.row = 0;

		notifyObservers(common::ActionType::TETROMINO_INSERTED, this);

		checkGameOver();
	}

	void Game::moveCurrent(const MoveDirection &direction) {
		if (!_current.has_value()) throw std::logic_error("Game: _current is not initialized");

		if (canMove(direction)) {
			switch (direction) {
				case MoveDirection::LEFT:
					_currentPosition.col--;
					break;
				case MoveDirection::RIGHT:
					_currentPosition.col++;
					break;
				case MoveDirection::DOWN:
					_currentPosition.row++;
					break;
			}

			notifyObservers(ActionType::GRID_CHANGED, this);
		}
	}

	void Game::rotateCurrent(const RotateDirection &direction) {
		if (!_current.has_value()) throw std::logic_error("Game: _current is not initialized");
		_current->rotate(direction);
		if (!canRotate()){ // FIXME
			if (direction==RotateDirection::CCW){
				_current->rotate(RotateDirection::CW);
			} else {
				_current->rotate(RotateDirection::CCW);
			}

		}

	}

	void Game::placeCurrent() {
		if (!_current.has_value()) throw std::logic_error("Game: _current is not initialized");

		// insert current tetromino in the real grid
		_grid.insert(_current.value(), _currentPosition.row, _currentPosition.col);
	}

	bool Game::canMove(const MoveDirection &direction) /*const*/{
		if (!_current.has_value()) throw std::logic_error("Game: _current is not initialized");

		for (size_t x = 0; x < _current->getWidth(); x++) {
			for (size_t y = 0; y < _current->getHeight(); y++) {
				if (_current->isOccupied(x, y)) {
					switch (direction) {
						case MoveDirection::LEFT:
							if (_currentPosition.col + x <= 0) {
								return false;
							}
							if (_grid.isOccupied(_currentPosition.row + y, _currentPosition.col + x - 1)) {
								return false;
							}
							break;
						case MoveDirection::RIGHT:
							if (_currentPosition.col + x >= _grid.width - 1) {
								return false;
							}
							if (_grid.isOccupied(_currentPosition.row + y, _currentPosition.col + x + 1)) {
								return false;
							}
							break;
						case MoveDirection::DOWN:
							if (_currentPosition.row + y >= _grid.height - 1) {
								placeCurrent(); // FIXME here??
								return false;
							}
							if (_grid.isOccupied(_currentPosition.row + y + 1, _currentPosition.col + x)) {
								placeCurrent();
								return false;
							}
							break;
					}
				}
			}
		}
		return true;
	}

	bool Game::canRotate() const{
		for (size_t x = 0; x < _current->getWidth(); x++) {
			for (size_t y = 0; y < _current->getHeight(); y++) {
				if (_current->isOccupied(x, y)
				&& (	_currentPosition.col + x >= _grid.width
					||	_currentPosition.col + x < 0
					|| _grid.isOccupied(_currentPosition.col + x, _currentPosition.row + y)))
				{
					return false;
				}
			}
		}
		return true;
	}

	bool Game::isCurrentOverlap() const {
		auto tetroWidth{_current->getWidth()};
		auto tetroHeight{_current->getHeight()};

		for (size_t x = 0; x < tetroWidth; x++) {
			for (size_t y = 0; y < tetroHeight; y++) {
				if (_current->isOccupied(x, y) && _grid.isOccupied(_currentPosition.row + x, _currentPosition.col + y)) {
					return true;
				}
			}
		}
		return false;
	}

	void Game::updateData(size_t nbLinesRemoved, size_t nbLinesCrossed){
		score += nbLinesRemoved + nbLinesCrossed;
		nbClearedLines += nbLinesRemoved;
		_currentLevel = (nbClearedLines / 10) + _startLevel;

		notifyObservers(ActionType::DATA_UPDATED, this);
	}

	void Game::endMovement(){
		notifyObservers(ActionType::GRID_CHANGED, this);
	}


} // namespace tetris::model


