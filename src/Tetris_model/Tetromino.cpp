#include "Tetromino.h"
#include "util/maxVectorSize.hpp"

namespace tetris::model {

	Tetromino::Tetromino(Shape_type shape, Color color) :
	_shape(util::maxVectorSize(shape), std::vector<std::optional<Block>>(util::maxVectorSize(shape)))
	// 				^ Make the largest matrix to store the shape even when rotated
	{
		for (size_t i {0}; i < shape.size(); ++i) {
			for (size_t j {0}; j < shape[i].size(); ++j) {
				if (shape[i][j]) {
					this->_shape[i][j] = Block(color);
				}
			}
		}
	}

    Tetromino::Tetromino(ConstructorComponents_type ctorCmpnts) {
    }


    Block get(size_t x, size_t y) {
    }


    bool isOccupied(size_t x, size_t y) {
    }


    void rotate(RotateDirection direction) {
    }


    size_t getWidth() {
    }


    size_t getHeight() {
    }


} // namespace tetris::model

