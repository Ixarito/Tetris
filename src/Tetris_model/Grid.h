#ifndef TETRIS_MODEL_GRID_H
#define TETRIS_MODEL_GRID_H

#include "Line.h"
#include "Tetromino.h"
#include "MoveDirection.h"

namespace tetris::model{

	/**
	 * Represents the grid of the Tetris game
	 * The grid is composed of lines
	 * @sa tetris::model::Line
	 */
	class Grid{
		Line * _lines;
		Tetromino _current;
		size_t _currentCol;
		size_t _currentRow;

		// TODO: implement method placeCurrent() in .cpp file
	public:
		/**
		 * The width of the grid.
		 * It corresponds to the length of a line
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
		 * @param nbAlreadyPlacedBlock if specified, will randomly place in the bottom of the grid as many block as the given number
		 */
		explicit Grid(size_t width, size_t height, int nbAlreadyPlacedBlock = 0);

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
		 * Gives the block at the given position
		 * @param row the row of the block to get
		 * @param col the column of the block to get
		 * @return a constant reference to the block
		 */
		const Block & get(size_t row, size_t col) const;

		/**
		 * Inserts a tetromino at the top of the grid
		 * @param tetromino the tetromino to insert
		 * @return true if tetromino could be inserted, false if there is no place to insert it
		 */
		bool insert(Tetromino tetromino);

		/**
		 * Move the current tetromino in the given direction.
		 * Has no effect if there is no current tetromino currently in the grid
		 * @param direction the direction to move the tetromino
		 */
		void moveCurrent(MoveDirection direction);

		/**
		 * Rotate the current tetromino in the given direction.
		 * Has no effect if there is no current tetromino currently in the grid
		 * @param direction the direction to rotate the tetromino
		 * @sa tetris::model::Tetromino::rotate()
		 */
		inline void rotateCurrent(RotateDirection direction);

		/**
		 * Drops the current tetromino while possible
		 * @return the number of lines crossed by the tetromino before coming to rest
		 */
		int dropCurrent();

		/**
		 * Gives the line numbers that are full of blocks
		 * @return all the line numbers that are full
		 * @sa tetris::model::Line::isFull()
		 */
		std::vector<size_t> getFullLines();

		/**
		 * Removes the line at the given position.
		 * Has the effect of lowering all the lines that were above
		 * @param position the position of the line
		 * @sa tetris::model::Grid::getFullLines()
		 */
		void removeLine(size_t position);

		/**
		 * Gives the line at the given position
		 * @param position the position of the line to get
		 * @return a constant reference to the line
		 * @sa tetris::model::Line
		 * @sa tetris::model::Line::operator[]()
		 */
		const Line & operator[](size_t position) const;


		/**
		 * @name Iterators
		 * @{
		 */

		/**
		 * Returns a pointer to the first line of the grid
		 * @return a pointer to a constant line
		 * @sa tetris::model::Line::cbegin()
		 */
		inline const Line * cbegin() const;

		/**
		 * Returns a pointer to the element following the last line of the grid
		 * @return a pointer to the element following the last constant line
		 * @sa tetris::model::Line::cend()
		 */
		inline const Line * cend() const;

		/**
		 * @}
		 */
	};

} // namespace tetris::model

#endif //TETRIS_MODEL_GRID_H
