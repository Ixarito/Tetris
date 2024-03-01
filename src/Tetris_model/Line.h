#ifndef TETRIS_MODEL_LINE_H
#define TETRIS_MODEL_LINE_H

#include <vector>
#include "Block.h"

namespace tetris::model{

	/**
	 * Represents a line of blocks
	 * @sa tetris::model::Block
	 * @sa tetris::model::Grid
	 */
	class Line{
		std::vector<Block> _content;
	public:
		/**
		 * The length of the line
		 */
		const int length;

		/**
		 * Constructs a Line
		 * @param length the length of the line
		 */
		Line(int & length);

		/**
		 * Places a block in the line
		 * @param position the position where the block is going to be placed
		 * @param block the block to placed
		 * @sa tetris::model::Line::operator[]()
		 */
		void set(int & position, Block & block);

		/**
		 * Gives the block at the given position
		 * @param position the position of the block to get
		 * @return a reference to the block at the given position
		 * @sa tetris::model::Line::operator[]()
		 */
		Block & get(int & position);

		/**
		 * Determines if the line is full of blocks
		 * @return true if the line is filled, false otherwise
		 */
		bool isFull() const;

		/**
		 * Clear the line of all its blocks
		 */
		void clear();

		/**
		 * Gives the block at the given position
		 * @param position the position of the block to access
		 * @return a reference to the block at the given position
		 */
		Block & operator[](int position);


		/**
		 * @name Iterators
		 * @{
		 */

		/**
		 * Returns an iterator to the first block of the line
		 * @return an iterator to the first block
		 */
		decltype(_content.cbegin()) inline cbegin() const;

		/**
		 * Returns an iterator to the element following the last block of the line
		 * @return an iterator to the element following the last block
		 */
		decltype(_content.cend()) inline cend() const;

		/**
		 * @}
		 */
	};

} // namespace tetris::model

#endif //TETRIS_MODEL_LINE_H
