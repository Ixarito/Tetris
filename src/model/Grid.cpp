#include "Grid.h"

namespace tetris::model {

    Grid::Grid(size_t width, size_t height, int nbAlreadyPlacedBlock) : _lines(new Line[height]), _current(Tetromino::random()), _currentCol(width / 2), _currentRow(0), width(width), height(height) {}

    Grid::~Grid() {
        delete[] _lines;
    }

    const Block & Grid::get(size_t row, size_t col) const {
        return _lines[row][col];
    }

    bool Grid::insert(Tetromino tetromino) {
        _current = tetromino;
        _currentCol = 0;
        _currentRow = 0;
    }

    void Grid::moveCurrent(MoveDirection direction) {
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

    void Grid::rotateCurrent(RotateDirection direction) {
        _current.rotate(direction);
    }

    bool Grid::canMove(MoveDirection direction) {
        switch (direction) {
            case MoveDirection::LEFT:
                return _currentCol > 0;
            case MoveDirection::RIGHT:
                return _currentCol + _current.getWidth() < width;
            case MoveDirection::DOWN:
                return _currentRow + _current.getHeight() < height;
        }
    }

    int Grid::dropCurrent() {
        while (canMove(MoveDirection::DOWN)) {
            moveCurrent(MoveDirection::DOWN);
        }
    }

    std::vector<size_t> Grid::getFullLines() {
        std::vector<size_t> fullLines;
        for (size_t i = 0; i < height; i++) {
            if (_lines[i].isFull()) {
                fullLines.push_back(i);
            }
        }
    }

    void Grid::removeLine(size_t position) {
        Line emptyLine(width);

        for (size_t i = position; i > 0; i--) {
            _lines[i] = _lines[i - 1];
        }

        _lines[0] = emptyLine;
    }

    const Line & Grid::operator[](size_t position) const {
        return _lines[position];
    }

    const Line * Grid::cbegin() const {
        return _lines.cbegin();
    }

    const Line * Grid::cend() const {
        return _lines.cend();
    }

} // namespace tetris::model