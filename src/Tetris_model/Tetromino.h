#ifndef TETRIS_MODEL_TETROMINO_H
#define TETRIS_MODEL_TETROMINO_H

#include <vector>
#include "Block.h"
#include "RotateDirection.h"

namespace tetris::model{

	/**
	 * Represents a piece of the Tetris game
	 * A tetromino is formed by blocks
	 * @sa tetris::model::Block
	 */
	class Tetromino{
		std::vector<std::vector<Block>> _shape;

	public:
		/**
		 * Creates a Tetromino
		 * @param color the color of the blocks that form the tetromino
		 */
		Tetromino(std::vector<std::vector<bool>>, Color color);

		/**
		 * Gives the block at the given position
		 * @param x the x position in the tetromino shape
		 * @param y the y position in the tetromino shape
		 * @return the block at the given position
		 * @note returns a copy of the block as it may persist after the tetromino has been destroyed
		 */
		const Block get(int x, int y) const;

		/**
		 * Determines if a position is occupied by a block in the tetromino shape
		 * @param x the x position in the tetromino shape
		 * @param y the y position in the tetromino shape
		 * @return true if the position is occupied by a block, false otherwise
		 */
		bool isOccupied(int x, int y) const;

		/**
		 * Rotates the tetromino in the given direction
		 * @param direction the direction of rotation
		 */
		void rotate(RotateDirection direction);

		/**
		 * Gives the current tetromino width
		 * @return the current tetromino width
		 */
		int getWidth() const;

		/**
		 * Gives the current tetromino height
		 * @return the current tetromino height
		 */
		int getHeight() const;

	};

} // namespace tetris::model

#endif //TETRIS_MODEL_TETROMINO_H
