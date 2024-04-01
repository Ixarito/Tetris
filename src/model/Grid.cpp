#include <stdexcept>
#include "Grid.h"
#include "util/outOfRangeMessage.hpp"

namespace tetris::model {

    Grid::Grid(const size_t &width, const size_t &height, const int &nbAlreadyPlacedBlock) :
            _lines{}, _current{}, _currentCol{}, _currentRow{}, width{width}, height{height} {
        for (size_t i{0}; i < height; i++) {
            _lines.push_back(new Line(width));
        }
    }

    Grid::~Grid() {
        for (auto lp: _lines) {
            delete lp;
            lp = nullptr;
        }
    }

    bool Grid::canMove(const MoveDirection &direction) {
		if(!_current.has_value()) throw std::logic_error("Grid: _current is not initialized");

		for (size_t x = 0; x < _current->getWidth(); x++) {
			for (size_t y = 0; y < _current->getHeight(); y++) {
				if (_current->isOccupied(x, y)) {
					switch (direction) {
						case MoveDirection::LEFT:
							if (_currentCol + x <= 0) {
								return false;
							}
							if (_lines[_currentRow + y]->isOccupied(_currentCol + x - 1)) {
								return false;
							}
						case MoveDirection::RIGHT:
							if (_currentCol + x >= width - 1) {
								return false;
							}
							if (_lines[_currentRow + y]->isOccupied(_currentCol + x + 1)) {
								return false;
							}
						case MoveDirection::DOWN:
							if (_currentRow + y >= height - 1) {
								return false;
							}
							if (_lines[_currentRow + y + 1]->isOccupied(_currentCol + x)) {
								return false;
							}
					}
				}
			}
		}
		return true;
    }

	void Grid::placeCurrent() {
		// insert current tetromino in the real grid

		if(!_current.has_value()) throw std::logic_error("Grid: _current is not initialized");

		auto tetroWidth {_current->getWidth()};
		auto tetroHeight {_current->getHeight()};

		for (size_t x = 0; x < tetroWidth; x++) {
			for (size_t y = 0; y < tetroHeight; y++) {
				if (_current->isOccupied(x, y)) {
					_lines[_currentRow + y]->set(_currentCol + x, _current->get(x, y));
				}
			}
		}
	}

    const Block &Grid::get(const size_t &row, const size_t &col) const {
        if (row >= height) {
            throw std::out_of_range(util::OORmessage(row, height));
        }
        return (*_lines[row])[col];
    }

    bool Grid::insert(Tetromino tetromino) { // TODO: bool ?
        _current = tetromino;
        _currentCol = width / 2 - tetromino.getWidth() / 2;
        _currentRow = 0;
        return true;
    }

    void Grid::moveCurrent(const MoveDirection &direction) {
		if(!_current.has_value()) throw std::logic_error("Grid: _current is not initialized");

        if (canMove(direction)) {
            switch (direction) {
                case MoveDirection::LEFT:
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
    }

    void Grid::rotateCurrent(const RotateDirection &direction) {
		if(!_current.has_value()) throw std::logic_error("Grid: _current is not initialized");

        _current->rotate(direction);
    }

    int Grid::dropCurrent() {
        int count{}; // number of lines crossed
        while (canMove(MoveDirection::DOWN)) {
            moveCurrent(MoveDirection::DOWN);
            count++;
        }

		placeCurrent();

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

    void Grid::removeLine(const size_t &position) {
        if (position >= height) {
            throw std::out_of_range(util::OORmessage(position, height));
        }

        // remove line from the deque
        auto it = _lines.begin() + position;
        Line *target = *it;
        _lines.erase(it);

        // clear line and reinsert in top of the grid
        target->clear();
        _lines.push_front(target);
    }

    std::vector<Line> Grid::getGridView() const {
        std::vector<Line> gridView;
        for (auto & line : _lines) {
            gridView.push_back(*line);
        }

		if(_current.has_value()){
			// getWidth et Height are long methods so declare before
			auto tetroWidth {_current->getWidth()};
			auto tetroHeight {_current->getHeight()};

			for (size_t x = 0; x < tetroWidth; x++) {
				for (size_t y = 0; y < tetroHeight; y++) {
					if (_current->isOccupied(x, y)) {
						gridView[_currentRow + y].set(_currentCol + x, _current->get(x, y));
					}
				}
			}
		}
        return gridView;
    }


    const Line &Grid::operator[](const size_t &position) const {
        if (position >= height) {
            throw std::out_of_range(util::OORmessage(position, height));
        }
        return *_lines[position];
    }

    auto Grid::begin() const -> decltype(_lines.begin()) {
        return _lines.begin();
    }

    auto Grid::cbegin() const -> decltype(_lines.cbegin()) {
        return _lines.cbegin();
    }

    auto Grid::end() const -> decltype(_lines.end()) {
        return _lines.end();
    }

    auto Grid::cend() const -> decltype(_lines.cend()) {
        return _lines.cend();
    }

} // namespace tetris::model