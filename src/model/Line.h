#ifndef TETRIS_MODEL_LINE_H
#define TETRIS_MODEL_LINE_H

#include <vector>
#include <optional>
#include "Block.h"

namespace tetris::model{

	/**
	 * Represents a line of blocks
	 * @sa tetris::model::Block
	 * @sa tetris::model::Grid
	 */
	class Line{
		std::vector<std::optional<Block>> _content;

	public:
		/**
		 * The length of the line
		 */
		const size_t length;

		/**
		 * Constructs a Line
		 * @param length the length of the line
		 */
		Line(const size_t & length);

		/**
		 * Places a Block in the line
		 * @param position the position where the block is going to be placed
		 * @param block the block to place
		 * @sa tetris::model::Line::operator[]()
		 */
		void set(const size_t & position, const Block & block);

		/**
		 * Gives the Block at the given position
		 * @param position the position of the block to get
		 * @return a reference to the block at the given position
		 * @sa tetris::model::Line::operator[]()
		 */
		Block & get(const size_t & position);

		/**
		 * Gives the Block at the given position
		 * @param position the position of the block to get
		 * @return a constant reference to the block at the given position
		 * @sa tetris::model::Line::operator[]()
		 */
		const Block & get(const size_t & position) const;

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
         * Determines if a position is occupied by a Block in the line
         * @param position the position to check
         * @return true if the position is occupied by a Block, false otherwise
         */
        bool isOccupied(const size_t & position) const;

		/**
		 * Gives the Block at the given position
		 * @param position the position of the block to access
		 * @return a reference to the block at the given position
		 */
		Block & operator[](const size_t & position);

		/**
		 * Gives the Block at the given position
		 * @param position the position of the block to access
		 * @return a constant reference to the block at the given position
		 */
		const Block & operator[](const size_t & position) const;


		/**
		 * @name Iterators
		 * @{
		 */

		/**
		 * Returns an iterator to the first Block of the line
		 * @return an iterator to the first Block
		 */
		auto begin() const -> decltype(_content.begin());

		/**
		 * Returns an iterator to the first Block of the line
		 * @return an iterator to the first Block
		 */
		auto cbegin() const -> decltype(_content.cbegin());

		/**
		 * Returns an iterator to the element following the last Block of the line
		 * @return an iterator to the element following the last Block
		 */
		auto end() const -> decltype(_content.end());

		/**
		 * Returns an iterator to the element following the last Block of the line
		 * @return an iterator to the element following the last Block
		 */
		auto cend() const -> decltype(_content.cend());

		/**
		 * @}
		 */
	};

} // namespace tetris::model

#endif //TETRIS_MODEL_LINE_H
