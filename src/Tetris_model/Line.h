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
		const size_t length;

		/**
		 * Constructs a Line
		 * @param length the length of the line
		 */
		Line(size_t length);

		/**
		 * Places a Block in the line
		 * @param position the position where the block is going to be placed
		 * @param block the block to placed
		 * @sa tetris::model::Line::operator[]()
		 */
		void set(size_t position, Block & block);

		/**
		 * Gives the Block at the given position
		 * @param position the position of the block to get
		 * @return a reference to the block at the given position
		 * @sa tetris::model::Line::operator[]()
		 */
		Block & get(size_t position);

		/**
		 * Gives the Block at the given position
		 * @param position the position of the block to get
		 * @return a constant reference to the block at the given position
		 * @sa tetris::model::Line::operator[]()
		 */
		const Block & get(size_t position) const;

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
		 * Gives the Block at the given position
		 * @param position the position of the block to access
		 * @return a reference to the block at the given position
		 */
		Block & operator[](size_t position);

		/**
		 * Gives the Block at the given position
		 * @param position the position of the block to access
		 * @return a constant reference to the block at the given position
		 */
		const Block & operator[](size_t position) const;


		/**
		 * @name Iterators
		 * @{
		 */

		/**
		 * Returns an iterator to the first Block of the line
		 * @return an iterator to the first Block
		 */
		decltype(_content.cbegin()) inline cbegin() const;

		/**
		 * Returns an iterator to the element following the last Block of the line
		 * @return an iterator to the element following the last Block
		 */
		decltype(_content.cend()) inline cend() const;

		/**
		 * @}
		 */
	};

} // namespace tetris::model

#endif //TETRIS_MODEL_LINE_H
