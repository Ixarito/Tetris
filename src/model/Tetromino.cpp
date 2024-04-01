#include "Tetromino.h"
#include "util/maxVectorSize.hpp"
#include <iostream>

namespace tetris::model {

    Tetromino::Tetromino(const Shape_type & shape, const Color & color) :
            _shape(util::maxVectorSize(shape), std::vector<std::optional<Block>>(util::maxVectorSize(shape)))
    // 				    ^ Make the largest matrix to store the shape even when rotated
    {
        for (size_t i{0}; i < shape.size(); ++i) {
            for (size_t j{0}; j < shape[i].size(); ++j) {
                if (shape[i][j]) {
                    this->_shape[i][j] = Block(color);
                }
            }
        }
    }

    Tetromino::Tetromino(const ConstructorComponents_type & ctorCmpnts) : Tetromino(ctorCmpnts.first, ctorCmpnts.second) {}


    Block Tetromino::get(const size_t & x, const size_t & y) const {
		if(!isOccupied(x, y)) throw std::logic_error("No block at this position. To avoid this error, use the isOccupied() method");
        return _shape[y][x].value();
    }


    bool Tetromino::isOccupied(const size_t & x, const size_t & y) const {
        return _shape[y][x].has_value();
    }


    //source : https://www.javatpoint.com/rotate-matrix-by-90-degrees-in-java
    void Tetromino::rotate(const RotateDirection & direction) {
        size_t size = _shape.size();

        std::vector<std::vector<std::optional<Block>>> tempShape(size, std::vector<std::optional<Block>>(size));

        if (direction == RotateDirection::CCW) {
            for (size_t i = 0; i < size; ++i) {
                for (size_t j = 0; j < size; ++j) {
                    tempShape[size - j - 1][i] = _shape[i][j];
                }
            }
        } else if (direction == RotateDirection::CW) {
            for (size_t i = 0; i < size; ++i) {
                for (size_t j = 0; j < size; ++j) {
                    tempShape[j][size - i - 1] = _shape[i][j];
                }
            }
        }

        _shape = tempShape;
    }


    size_t Tetromino::getHeight() const {
        size_t height{};
        size_t vectorWidth {_shape[0].size()}; // used for optimise the loop

        for (size_t x{}; x < vectorWidth; ++x) {
            size_t tempHeight{};
            for (size_t y{}; y < _shape.size(); ++y) {
                if (_shape[y][x].has_value()) {
                    tempHeight = y + 1;
                }
            }
            if (tempHeight > height) {
                height = tempHeight;
            }
        }

        return height;
    }

    size_t Tetromino::getWidth() const {
        size_t width{};
        size_t vectorWidth {_shape[0].size()}; // used for optimise the loop

        for (size_t y{}; y < _shape.size(); ++y) {
            size_t tempWidth{};
            for (size_t x{}; x < vectorWidth; ++x) {
                if (_shape[y][x].has_value()) {
                    tempWidth = x + 1;
                }
            }
            if (tempWidth > width) {
                width = tempWidth;
            }
        }

        return width;
    }

    //Only a test - to delete after
    void Tetromino::print() const {
        for (const auto& row : _shape) {
            for (const auto& block : row) {
                std::cout << (block.has_value() ? 'X' : '_');
            }
            std::cout << '\n';
        }
    }


} // namespace tetris::model

