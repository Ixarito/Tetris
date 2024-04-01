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
        switch (direction) {
            case MoveDirection::LEFT:
                for (int x = 0; x < _current->getWidth(); x++) {
                    for (int y = 0; y < _current->getHeight(); y++) {
                        if (_current->isOccupied(x, y)) {
                            if (_currentCol + x <= 0) {
                                return false;
                            }
                            if (_lines[_currentRow + y]->isOccupied(_currentCol + x - 1)) {
                                return false;
                            }
                        }
                    }
                }
                return true;
            case MoveDirection::RIGHT:
                for (int x = 0; x < _current->getWidth(); x++) {
                    for (int y = 0; y < _current->getHeight(); y++) {
                        if (_current->isOccupied(x, y)) {
                            if (_currentCol + x >= width - 1) {
                                return false;
                            }
                            if (_lines[_currentRow + y]->isOccupied(_currentCol + x + 1)) {
                                return false;
                            }
                        }
                    }
                }
                return true;
            case MoveDirection::DOWN:
                for (int x = 0; x < _current->getWidth(); x++) {
                    for (int y = 0; y < _current->getHeight(); y++) {
                        if (_current->isOccupied(x, y)) {
                            if (_currentRow + y >= height - 1) {
                                return false;
                            }
                            if (_lines[_currentRow + y + 1]->isOccupied(_currentCol + x)) {
                                return false;
                            }
                        }
                    }
                }
                return true;
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
        _current->rotate(direction);
    }

    int Grid::dropCurrent() {
        int count{}; // number of lines crossed
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

    std::vector<std::vector<std::optional<model::Block>>> Grid::getGridView() const {
        std::vector<std::vector<std::optional<model::Block>>> gridView;
        for (int x = 0; x < width; x++) {
            std::vector<std::optional<model::Block>> column;
            for (int y = 0; y < height; y++) {
                column.emplace_back(get(y, x));
            }
            gridView.push_back(column);
        }
        for (int x = 0; x < _current->getWidth(); x++) {
            for (int y = 0; y < _current->getHeight(); y++) {
                if (_current->isOccupied(x, y)) {
                    gridView[_currentCol + x][_currentRow + y] = _current->get(x, y);
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