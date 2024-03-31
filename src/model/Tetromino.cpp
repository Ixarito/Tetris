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

    Tetromino::Tetromino(const ConstructorComponents_type & ctorCmpnts) : Tetromino(ctorCmpnts.first, ctorCmpnts.second)
	{}


    Block Tetromino::get(const size_t & x, const size_t & y) const {
		if(!isOccupied(x, y)) throw std::logic_error("No block at this position. To avoid this error, use the isOccupied() method");
        return _shape[x][y].value();
    }


    bool Tetromino::isOccupied(const size_t & x, const size_t & y) const {
        return _shape[x][y].has_value();
    }


    //source : https://www.javatpoint.com/rotate-matrix-by-90-degrees-in-java
    void Tetromino::rotate(const RotateDirection & direction) {
        size_t size = _shape.size();

		std::cout << size << std::endl;
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
        size_t height{0};

        size_t vectorHeight {_shape.size()}; //used for optimise the loop
        for (size_t y{0}; y < _shape[0].size(); ++y) {
            size_t tempHeight{0};
            for (size_t x{0}; x < vectorHeight; ++x) {
                if (_shape[x][y].has_value()) {
                    tempHeight++;
                }
            }
            if (tempHeight > height) {
                height = tempHeight;
            }
        }

        return height;
    }

    size_t Tetromino::getWidth() const {
        size_t width{0};
        size_t vectorWidth {_shape[0].size()}; //used for optimise the loop

        for (size_t x{0}; x < _shape.size(); ++x) {
            size_t tempWidth{0};
            for (size_t y{0}; y < vectorWidth; ++y) {
                if (_shape[x][y].has_value()) {
                    tempWidth++;
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

