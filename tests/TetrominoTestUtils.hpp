#ifndef TETRIS_TETROMINOTESTUTILS_HPP
#define TETRIS_TETROMINOTESTUTILS_HPP

#include "Tetromino.h"
#include "BlockTestUtils.hpp"

namespace tetris::model{

	bool operator==(const Tetromino & lhs, const Tetromino & rhs) {
		// Check if dimensions are equal
		if (lhs.getWidth() != rhs.getWidth() || lhs.getHeight() != rhs.getHeight())
			return false;

		auto height {lhs.getHeight()};
		auto width {lhs.getWidth()};

		// Check each block in the shape
		for (size_t y = 0; y < height; ++y) {
			for (size_t x = 0; x < width; ++x) {
				// If one block differs, return false
				if (lhs.isOccupied(x,y) != rhs.isOccupied(x,y))
					return false;
			}
		}
		// All blocks are equal, return true
		return true;
	}

} // namespace tetris::model

#endif //TETRIS_TETROMINOTESTUTILS_HPP
