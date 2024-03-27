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
		static Bag _instance;

		std::vector<Tetromino> _list;
		decltype(_list.begin()) _next;

		// TODO: implements constructor & method shuffle() in .cpp file
	public:

		/**
		 * Gives access to the instance of bag
		 * @return the instance of bag
		 */
		static inline Bag getInstance();

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
