#ifndef TETRIS_MODEL_GAME_H
#define TETRIS_MODEL_GAME_H

#include <vector>
#include <utility>
#include "Grid.h"
#include "Bag.h"

namespace tetris::model{

	/**
	 * Represents a game part of the Tetris game
	 */
	class Game{
		Grid _grid;
		Bag _bag;
		int _level;

	protected:
		/**
		 * The current game score
		 */
		unsigned long long int score;

	public:

		/**
		 * Creates a new game part of the Tetris game
		 * @param shapes the shapes of tetrominoes to play during the game
		 * @param level if specified, the game will start at a higher level of difficulty
		 * @param nbAlreadyPlacedBlocks if specified, the game Grid will be filled with randomly placed blocks at the bottom
		 * @sa tetris::model::Grid::Grid()
		 */
		Game(std::vector<Tetromino::ConstructorComponents_type> shapes, int level = 0, int nbAlreadyPlacedBlocks = 0);

		/**
		 * @name Victory checks
		 * @{
		 */

		/**
		 * Determines if the game is over
		 * @return true if the game is over, false otherwise
		 */
		bool isGameOver() const;


		/**
		 * Determines if the game is won
		 * @return true if the game is won, false else
		 * @note The method does not really make sense if it is not override. With the simple Game class, it always returns false
		 */
		virtual bool isWon() const;

		/**
		 * @}
		 *
		 * @name Getters
		 * @{
		 */

		/**
		 * Gives the current score
		 * @return the current score
		 */
		inline long long int getScore() const;

		/**
		 * Gives the current level
		 * @return the current level
		 */
		inline int getLevel() const;

		/**
		 * @}
		 *
		 * @name Actions
		 * @{
		 */

		/**
		 * Performs the action move the current tetromino down
		 */
		void goDown() const;

		/**
		 * Performs the action move the current tetromino to the left
		 */
		void goLeft() const;

		/**
		 * Performs the action move the current tetromino to the right
		 */
		void goRight() const;

		/**
		 * Performs the action rotate the current tetromino to the left
		 */
		void rotateLeft() const;

		/**
		 * Performs the action rotate the current tetromino to the right
		 */
		void rotateRight() const;

		/**
		 * Performs the action drop the current tetromino
		 */
		void drop() const;

		};

		/**
		 * @}
		 */

} // namespace tetris::model

#endif //TETRIS_MODEL_GAME_H
