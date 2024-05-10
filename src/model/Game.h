#ifndef TETRIS_MODEL_GAME_H
#define TETRIS_MODEL_GAME_H

#include <vector>
#include "Grid.h"
#include "Observable.h"

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
		unsigned int level = 0;
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
class Game : public common::Observable{
		Grid _grid;
		std::vector<Tetromino> _bag;
		size_t _nextTetromino;
		unsigned int _level;

	protected:
		/**
		 * The current game score
		 */
		unsigned long long int score;
		/**
		 * The number of lines cleared since the start of the game
		 */
		unsigned int nbClearedLines;

	public:

		/**
		 * Creates a game part of the Tetris game
		 * @param params the parameters of the Game
		 * @sa tetris::model::GameParameters
		 */
		explicit Game(const GameParameters & params);

		/**
		 * Destructor of Game
		 */
		virtual ~Game() = default;

		/**
		 * @name Victory checks
		 * @{
		 */

		/**
		 * Determines if the game is over
		 * @return true if the game is still active, false if the game is over
		 */
		bool isGameActive() const;


		/**
		 * Determines if the game is won
		 * @return true if the game is won, false else
		 * @note The method does not really make sense if it is not override. With the simple Game class, it always returns false
		 */
		virtual bool isWon() const;

		/**
		 * @}
		 *
		 * @name Bag
		 * @{
		 */


		/**
		 * Gives an overview of the next tetromino in the bag
		 * @return a constant reference to the next tetromino
		 */
		const Tetromino & peekNext() const;

	private:

		/**
		 * Gives the next tetromino to play
		 * @return a copy of the tetromino to play
		 */
		Tetromino getNext();

		/**
		 * Shuffles the bag
		 */
		void shuffleBag();

		/**
		 * @}
		 *
		 * @name Getters
		 * @{
		 */
	public:

		/**
		 * Gives the current score
		 * @return the current score
		 */
		const unsigned long long int & getScore() const;

		/**
		 * Gives the current level
		 * @return the current level
		 */
        const unsigned int & getLevel() const;

		/**
		 * Gives an overview of the current state of the game Grid
		 * @return a view to the current state of the Grid
		 * @sa tetris::model::Grid::getGridView
		 */
		Grid::GridView_type getGridView() const;

        /**
         * Gives the number of lines cleared since the start of the game
         * @return the number of line cleared
         */
        const unsigned int & getNbClearedLines() const;

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

		/**
		 * Performs the action rotate the current tetromino counterclockwise
		 */
		void rotateCounterclockwise();

		/**
		 * Performs the action drop the current tetromino
		 */
		void drop();


	/**
	 * @}
	 */

	private:

		/**
		 * Used to update game datas like score, level or number of cleared lines
		 * @param nbLinesRemoved the number of lines removed after a drop
		 * @param nbLinesCrossed the number of lines crossed by the last Tetromino before inserting
		 */
		void updateData(size_t nbLinesRemoved, size_t nbLinesCrossed = 0);

		/**
		 * Used at the end of a movement of a tetromino
		 */
		void endMovement();

	};

} // namespace tetris::model

#endif //TETRIS_MODEL_GAME_H
