#ifndef TETRIS_MODEL_TETROMINO_H
#define TETRIS_MODEL_TETROMINO_H

#include <vector>
#include <optional>
#include "Block.h"
#include "RotateDirection.h"

namespace tetris::model{

	/**
	 * Represents a piece of the Tetris game
	 * A tetromino is formed by blocks
	 * @sa tetris::model::Block
	 */
	class Tetromino{

		std::vector<std::vector<std::optional<Block>>> _shape;

	public:
		/**
		 * Alias of 2d vector of bool that represents the shape of the tetromino
		 * @sa tetris::model::Tetromino::ConstructorComponents_type
		 */
		using Shape_type = std::vector<std::vector<bool>>;

		/**
		 * Alias of pair of Tetromino::Shape_type and tetris::model::Color that represents the 2 parameters of the tetromino constructor
		 * @sa tetris::model::Tetromino::Shape_type
		 */
		using ConstructorComponents_type = std::pair<Tetromino::Shape_type, Color>;

		/**
		 * Creates a Tetromino
		 * @param shape the shape that represents the tetromino
		 * @param color the color of the blocks that form the tetromino
		 */
		Tetromino(Shape_type shape, Color color);


		/**
		 * Creates a Tetromino.
		 * Alias of the other constructor but with the type ConstructorComponents_type
		 * @param ctorCmpnts the pair of component for the constructor
		 * @sa tetris::model::Tetromino::ConstructorComponents_type
		 */
		Tetromino(ConstructorComponents_type ctorCmpnts);

		/**
		 * Gives the Block at the given position
		 * @param x the x position in the tetromino shape
		 * @param y the y position in the tetromino shape
		 * @return the block at the given position
		 * @note returns a copy of the Block as it may persist after the tetromino has been destroyed
		 */
        Block get(size_t x, size_t y) const;

		/**
		 * Determines if a position is occupied by a Block in the tetromino shape
		 * @param x the x position in the tetromino shape
		 * @param y the y position in the tetromino shape
		 * @return true if the position is occupied by a Block, false otherwise
		 */
		bool isOccupied(size_t x, size_t y) const;

		/**
		 * Rotates the tetromino in the given direction
		 * @param direction the direction of rotation
		 */
		void rotate(RotateDirection direction);

		/**
		 * Gives the current tetromino width
		 * @return the current tetromino width
		 */
		size_t getWidth() const;

		/**
		 * Gives the current tetromino height
		 * @return the current tetromino height
		 */
		size_t getHeight() const;


        //test
        void print() const;



    };

} // namespace tetris::model

#endif //TETRIS_MODEL_TETROMINO_H
