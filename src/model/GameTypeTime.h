#ifndef TETRIS_MODEL_GAMETYPETIME_H
#define TETRIS_MODEL_GAMETYPETIME_H

#include "Game.h"

namespace tetris::model{

	/**
	 * Represents a specific type of Game, the game ends after a certain time
	 */
	class GameTypeTime: public Game{
		 time_t _startTime;
		 time_t _duration;

		 // TODO: modify class if Game can be paused
	public:

		/**
		 * Creates a game part of the Tetris game with the type time.
		 * With this type, the game ends after a certain time
		 * @param shapes the shapes of tetrominoes to play during the game
		 * @param duration the time in seconds that the game will last
		 * @param level if specified, the game will start at a higher level of difficulty
		 * @param nbAlreadyPlacedBlocks if specified, the game Grid will be filled with randomly placed blocks at the bottom
		 * @sa tetris::model::Grid::Grid()
		 */
		GameTypeTime(std::vector<Tetromino::ConstructorComponents_type> shapes, time_t duration, int level = 0, int nbAlreadyPlacedBlocks = 0);

		/**
		 * Determines if the game is won
		 * @return true if the game is won, false else
		 */
		bool isWon() const override;
	};

} // namespace tetris::model

#endif //TETRIS_MODEL_GAMETYPETIME_H
