#include <stdexcept>
#include "Grid.h"
#include "util/outOfRangeMessage.hpp"

namespace tetris::model {

	Grid::Grid(const size_t & width, const size_t & height, const int & nbAlreadyPlacedBlock):
	_lines{}, _current(Tetromino::random()), _currentCol{}, _currentRow{}, width{width}, height{height}
	{
		for(size_t i {0}; i < height; i++){
			_lines.push_back(new Line(width));
		}
	}

	Grid::~Grid() {
		for(auto lp: _lines){
			delete lp;
			lp = nullptr;
		}
	}

	bool Grid::canMove(const MoveDirection & direction) {
		switch (direction) {
			case MoveDirection::LEFT:
				return _currentCol > 0;
			case MoveDirection::RIGHT:
				return _currentCol + _current.getWidth() < width;
			case MoveDirection::DOWN:
				return _currentRow + _current.getHeight() < height;
			default:
				throw std::domain_error("End of switch reached for MoveDirection values");
		}
	}

	const Block & Grid::get(const size_t & row, const size_t & col) const {
		if(row >= height){
			throw std::out_of_range(util::OORmessage(row, height));
		}
		return (*_lines[row])[col];
	}

	bool Grid::insert(Tetromino tetromino) { // TODO: bool ?
		_current = tetromino;
		_currentCol = width/2;
		_currentRow = 0;
	}

	void Grid::moveCurrent(const MoveDirection & direction) {
		switch (direction) {
			case MoveDirection::LEFT:
				if(canMove(direction))
				_currentCol--;
				break;
			case MoveDirection::RIGHT:
				_currentCol++;
				break;
			case MoveDirection::DOWN:
				_currentRow++;
				break;
		}
	}

	void Grid::rotateCurrent(const RotateDirection & direction) {
		_current.rotate(direction);
	}

	int Grid::dropCurrent() {
		int count {}; // number of lines crossed
		while (canMove(MoveDirection::DOWN)) {
			moveCurrent(MoveDirection::DOWN);
			count++;
		}
		return count;
	}

	std::vector<size_t> Grid::getFullLines() {
		std::vector<size_t> fullLines;
		for (size_t i = 0; i < height; i++) {
			if (_lines[i]->isFull()) {
				fullLines.push_back(i);
			}
		}
		return fullLines;
	}

	void Grid::removeLine(const size_t & position) {
		if(position >= height){
			throw std::out_of_range(util::OORmessage(position, height));
		}

		// remove line from the deque
		auto it = _lines.begin() + position;
		Line* target = *it;
		_lines.erase(it);

		// clear line and reinsert in top of the grid
		target->clear();
		_lines.push_front(target);
	}

	const Line & Grid::operator[](const size_t & position) const {
		if(position >= height){
			throw std::out_of_range(util::OORmessage(position, height));
		}
		return *_lines[position];
	}

	auto Grid::begin() const -> decltype(_lines.begin()){
		return _lines.begin();
	}

	auto Grid::cbegin() const -> decltype(_lines.cbegin()){
		return _lines.cbegin();
	}

	auto Grid::end() const -> decltype(_lines.end()){
		return _lines.end();
	}

	auto Grid::cend() const -> decltype(_lines.cend()){
		return _lines.cend();
	}

} // namespace tetris::model