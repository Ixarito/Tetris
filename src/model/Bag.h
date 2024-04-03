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
		 * Adds a list of tetrominoes to the bag
		 * @param tetrominoes a list of tetrominoes to add
		 * @sa tetris::model::Tetromino
		 * @sa tetris::model::Tetromino::ConstructorComponents_type
		 */
		void addAll(const std::vector<Tetromino::ConstructorComponents_type> & tetrominoes);
	};

} // namespace tetris::model

#endif //TETRIS_MODEL_BAG_H
