#ifndef TETRIS_MODEL_GAMETYPELINES_H
#define TETRIS_MODEL_GAMETYPELINES_H

#include "Game.h"

namespace tetris::model{

	/**
	 * Represents a specific type of Game, the game ends when a specific number of lines is reached
	 */
	class GameTypeLines: public Game{
		int _linesToReach;
		int _nbClearedLines;

	public:

		/**
		 * Creates a game part of the Tetris game with the type line.
		 * With this type, the game ends when a specific number of lines is reached
		 * @param gameParams the parameters of the basic Game
		 * @param linesToReach the number of lines to reach to declare the game won
		 */
		GameTypeLines(const GameParameters & gameParams, int linesToReach);

		/**
		 * Determines if the game is won
		 * @return true if the game is won, false else
		 */
		bool isWon() const override;
	};

} // namespace tetris::model

#endif //TETRIS_MODEL_GAMETYPELINES_H
