#ifndef TETRIS_MODEL_BAG_H
#define TETRIS_MODEL_BAG_H

#include <vector>
#include "Tetromino.h"

namespace tetris::model{

	/**
	 * Contains the tetrominoes to play
	 * @sa tetris::model::Tetromino
	 */
	class Bag{
		std::vector<Tetromino> _list;
		size_t _next;

		Bag();
	public:

		Bag(Bag &) = delete;
		Bag operator=(Bag &) = delete;

		/**
		 * Gives access to the instance of bag
		 * @return the instance of bag
		 */
		static Bag & getInstance();

		/**
		 * Gives the next tetromino to play
		 * @return a copy of the tetromino to play
		 */
		Tetromino getNext();

		/**
		 * Gives an overview of the next tetromino in the bag
		 * @return a constant reference to the next tetromino
		 */
		const Tetromino & peekNext() const;

		/**
		 * Adds a tetromino to the bag
		 * @param tetromino a tetromino to add
		 * @sa tetris::model::Tetromino
		 */
		void add(Tetromino tetromino);
	};

} // namespace tetris::model

#endif //TETRIS_MODEL_BAG_H
