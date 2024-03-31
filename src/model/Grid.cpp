#include <stdexcept>
#include "Grid.h"
#include "util/outOfRangeMessage.hpp"

namespace tetris::model {

	Grid::Grid(const size_t & width, const size_t & height, const int & nbAlreadyPlacedBlock):
	_current(Tetromino::random()), _currentCol{}, _currentRow{}, width{width}, height{height}
	{
		auto lineTab {new Line*[height]};
		_lines = *lineTab;
	}

	Grid::~Grid() {
		delete[] _lines;
	}

	bool Grid::canMove(const MoveDirection & direction) {
		switch (direction) {
			case MoveDirection::LEFT:
				return _currentCol > 0;
			case MoveDirection::RIGHT:
				return _currentCol + _current.getWidth() < width;
			case MoveDirection::DOWN:
				return _currentRow + _current.getHeight() < height;
		}
	}

	const Block & Grid::get(const size_t & row, const size_t & col) const {
		if(row >= height){
			throw std::out_of_range(util::OORmessage(row, height));
		}
		return _lines[row][col];
	}

	bool Grid::insert(Tetromino tetromino) {
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
			if (_lines[i].isFull()) {
				fullLines.push_back(i);
			}
		}
		return fullLines;
	}

	void Grid::removeLine(const size_t & position) {
		for (size_t i = position; i > 0; i--) {
			std::swap(_lines[i], _lines[i-1]);
		}

		_lines[0] = emptyLine;
	}

	const Line & Grid::operator[](const size_t & position) const {
		if(position >= height){
			throw std::out_of_range(util::OORmessage(position, height));
		}
		return _lines[position];
	}

	Line * Grid::begin() const {
		return _lines;
	}

	const Line * Grid::cbegin() const {
		return _lines;
	}

	Line * Grid::end() const {
		return _lines + height;
	}

	const Line * Grid::cend() const {
		return _lines + height;
	}

} // namespace tetris::model