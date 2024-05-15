#ifndef TETRIS_MODEL_GRID_H
#define TETRIS_MODEL_GRID_H

#include <deque>
#include "Line.h"
#include "Tetromino.h"

namespace tetris::model{

	/**
	 * Represents the grid of the Tetris game
	 * The grid is composed of lines
	 * @sa tetris::model::Line
	 */
	class Grid{
		std::deque<Line *> _lines;

        /**
		 * Gives the Line numbers that are full of blocks
		 * @return all the line numbers that are full
		 * @sa tetris::model::Line::isFull()
		 */
        std::vector<size_t> getFullLines();

        /**
         * Removes the Line at the given position.
         * Has the effect of lowering all the lines that were above
         * @param position the position of the line
         * @sa tetris::model::Grid::getFullLines()
         */
        void removeLine(const size_t & position);


	public:
		/**
		 * The width of the grid.
		 * It corresponds to the length of a Line
		 * @sa tetris::model::Line::length
		 */
		const size_t width;

		/**
		 * The height of the grid.
		 * It corresponds to the number of lines
		 */
		const size_t height;

		/**
		 * Constructs a grid
		 * @param width the width of the grid (the length of line)
		 * @param height the height of the grid (the number of lines)
		 * @param nbAlreadyPlacedBlock if specified, will randomly place in the bottom of the grid as many blocks as the given number
		 */
		explicit Grid(const size_t & width, const size_t & height, const int & nbAlreadyPlacedBlock = 0);

		/**
		 * Destructs the grid
		 */
		~Grid();

		/**
		 * No copy constructor
		 */
		Grid(Grid &) = delete;

		/**
		 * No copy assignment operator
		 */
		Grid & operator=(Grid &) = delete;

		/**
		 * Inserts a Tetromino at the given position in the grid.
		 * The position is relative to the top left corner of the Tetromino
		 * @param tetromino the Tetromino to insert
		 * @param row the row where insert the Tetromino
		 * @param col the column where insert the Tetromino
		 */
		void insert(const Tetromino & tetromino, const size_t & row, const size_t & col);

		/**
		 * Gives the Block at the given position
		 * @param row the row of the block to get
		 * @param col the column of the block to get
		 * @return a constant reference to the block
		 */
		const Block & get(const size_t & row, const size_t & col) const;

		/**
		 * Determines if a position is occupied by a Block
		 * @param row the row to check
		 * @param col the column to check
		 * @return true if the position is occupied, false otherwise
		 * @sa tetris::model::Line::isOccupied()
		 */
		bool isOccupied(const size_t & row, const size_t & col) const;

		/**
		 * Gives the Line at the given position
		 * @param position the position of the line to get
		 * @return a constant reference to the line
		 * @sa tetris::model::Line
		 * @sa tetris::model::Line::operator[]()
		 */
		const Line & operator[](const size_t & position) const;


        /**
         * Remove all full lines
         * @return the number of lines removed
         **/
        size_t removeFullLines();

		/**
		 * @name Iterators
		 * @{
		 */

		/**
		 * Returns a pointer to the first Line of the grid
		 * @return a pointer to a constant line
		 * @sa tetris::model::Line::cbegin()
		 */
		auto begin() const -> decltype(_lines.begin());

		/**
		 * Returns a pointer to the first Line of the grid
		 * @return a pointer to a constant line
		 * @sa tetris::model::Line::cbegin()
		 */
		auto cbegin() const -> decltype(_lines.cbegin());

		/**
		 * Returns a pointer to the element following the last Line of the grid
		 * @return a pointer to the element following the last constant line
		 * @sa tetris::model::Line::cend()
		 */
		auto end() const -> decltype(_lines.end());

		/**
		 * Returns a pointer to the element following the last Line of the grid
		 * @return a pointer to the element following the last constant line
		 * @sa tetris::model::Line::cend()
		 */
		auto cend() const -> decltype(_lines.cend());

		/**
		 * @}
		 */
	};

} // namespace tetris::model

#endif //TETRIS_MODEL_GRID_H
