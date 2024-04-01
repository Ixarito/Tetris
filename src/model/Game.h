#ifndef TETRIS_MODEL_GAME_H
#define TETRIS_MODEL_GAME_H

#include <vector>
#include "Grid.h"
#include "Bag.h"

namespace tetris::model{

	/**
	 * Parameters of a Game
	 */
	struct GameParameters{
		/**
		 * The shapes of tetrominoes to play during the game
		 * @sa tetris::model::Tetromino::ConstructorComponents_type
		 */
		std::vector<Tetromino::ConstructorComponents_type> shapes;
		/**
		 * If specified, the game will start at a higher level of difficulty
		 */
		int level = 0;
		/**
		 * The width of the game Grid. Default is 10
		 * @sa tetris::model::Grid::Grid()
		 */
		size_t gridWidth = 10;
		/**
		 * The height of the game Grid. Default is 20
		 * @sa tetris::model::Grid::Grid()
		 */
		size_t gridHeight = 20;
		/**
		 * If specified, the game Grid will be filled with randomly placed blocks at the bottom
		 * @sa tetris::model::Grid::Grid()
		 */
		int nbAlreadyPlacedBlocks = 0;
	};

	/**
	 * Represents a game part of the Tetris game
	 */
	class Game{
		Grid _grid;
		Bag & _bag;
		int _level;

	protected:
		/**
		 * The current game score
		 */
		unsigned long long int score;

	public:

		/**
		 * Creates a game part of the Tetris game
		 * @param params the parameters of the Game
		 * @sa tetris::model::GameParameters
		 */
		Game(const GameParameters & params);

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
		inline const unsigned long long int & getScore() const;

		/**
		 * Gives the current level
		 * @return the current level
		 */
		inline const int & getLevel() const;

		/**
		 * @}
		 *
		 * @name Actions
		 * @{
		 */

		/**
		 * Performs the action move the current tetromino down
		 */
		void goDown();

		/**
		 * Performs the action move the current tetromino to the left
		 */
		void goLeft();

		/**
		 * Performs the action move the current tetromino to the right
		 */
		void goRight();

		/**
		 * Performs the action rotate the current tetromino clockwise
		 */
		void rotateClockwise();

        std::vector<Line> getGridView() const;

		/**
		 * Performs the action rotate the current tetromino counterclockwise
		 */
		void rotateCounterclockwise();

		/**
		 * Performs the action drop the current tetromino
		 */
		void drop();

		};

		/**
		 * @}
		 */

} // namespace tetris::model

#endif //TETRIS_MODEL_GAME_H
