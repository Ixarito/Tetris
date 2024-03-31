#ifndef TETRIS_MODEL_GAMETYPESCORE_H
#define TETRIS_MODEL_GAMETYPESCORE_H

#include "Game.h"

namespace tetris::model{

	/**
	 * Represents a specific type of Game, the game ends when a specific score is reached
	 */
	class GameTypeScore: public Game{
		unsigned long long int _scoreToReach;

	public:

		/**
		 * Creates a game part of the Tetris game with the type score.
		 * With this type, the game ends when a specific score is reached
		 * @param gameParams the parameters of the basic Game
		 * @param scoreToReach the score to reach to declare the game won
		 */
		GameTypeScore(const GameParameters & gameParams, const unsigned long long int & scoreToReach);

		/**
		 * Determines if the game is won
		 * @return true if the game is won, false else
		 */
		bool isWon() const override;
	};

} // namespace tetris::model

#endif //TETRIS_MODEL_GAMETYPESCORE_H
