#include "Tetromino.h"
#include "util/maxVectorSize.hpp"
#include <iostream>

namespace tetris::model {

    Tetromino::Tetromino(Shape_type shape, Color color) :
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

    Tetromino::Tetromino(ConstructorComponents_type ctorCmpnts) :
            _shape(util::maxVectorSize(ctorCmpnts.first),
                   std::vector<std::optional<Block>>(util::maxVectorSize(ctorCmpnts.first)))
    //              ^ Make the largest matrix to store the shape even when rotated
    {
        for (size_t i{0}; i < ctorCmpnts.first.size(); ++i) {
            for (size_t j{0}; j < ctorCmpnts.first[i].size(); ++j) {
                if (ctorCmpnts.first[i][j]) {
                    this->_shape[i][j] = Block(ctorCmpnts.second);
                }
            }
        }
    }


    Block Tetromino::get(size_t x, size_t y) const {
        return _shape[x][y].value();
    }


    bool Tetromino::isOccupied(size_t x, size_t y) const {
        return _shape[x][y].has_value();
    }


    void Tetromino::rotate(RotateDirection direction) {
        size_t size = _shape.size();
        if (direction == RotateDirection::CW) {
            // Clockwise rotation
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < i; ++j) {
                    std::optional<Block> temp = _shape[i][j];
                    _shape[i][j] = _shape[j][i];
                    _shape[j][i] = temp;
                }
            }
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size / 2; ++j) {
                    std::optional<Block> temp = _shape[i][j];
                    _shape[i][j] = _shape[i][size - j - 1];
                    _shape[i][size - j - 1] = temp;
                }
            }
        } else if (direction == RotateDirection::CCW) {
            // Counter-clockwise rotation
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size - i; ++j) {
                    std::optional<Block> temp = _shape[i][j];
                    _shape[i][j] = _shape[size - j - 1][size - i - 1];
                    _shape[size - j - 1][size - i - 1] = temp;
                }
            }
            for (int j = 0; j < size / 2; ++j) {
                for (int i = 0; i < size; ++i) {
                    std::optional<Block> temp = _shape[j][i];
                    _shape[j][i] = _shape[size - j - 1][i];
                    _shape[size - j - 1][i] = temp;
                }
            }
        }
    }


    size_t Tetromino::getHeight() const {
        int height{0};
        int vectorHeight {static_cast<int>(_shape.size())}; //used for optimise the loop
        for (int y{0}; y < _shape[0].size(); ++y) {
            int tempHeight{0};
            for (int x{0}; x < vectorHeight; ++x) {
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
        int width{0};
        int vectorWidth {static_cast<int>(_shape[0].size())}; //used for optimise the loop
        for (int x{0}; x < _shape.size(); ++x) {
            int tempWidth{0};
            for (int y{0}; y < vectorWidth; ++y) {
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

    //test
    void Tetromino::print() const {
        for (const auto& row : _shape) {
            for (const auto& block : row) {
                std::cout << (block.has_value() ? 'X' : '_');
            }
            std::cout << '\n';
        }
    }


} // namespace tetris::model

