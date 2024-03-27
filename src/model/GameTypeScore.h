#ifndef TETRIS_MODEL_GAMETYPESCORE_H
#define TETRIS_MODEL_GAMETYPESCORE_H

#include "Game.h"

namespace tetris::model{

	/**
	 * Represents a specific type of Game, the game ends when a specific score is reached
	 */
	class GameTypeScore: public Game{
		long long int _scoreToReach;

	public:

		/**
		 * Creates a game part of the Tetris game with the type score.
		 * With this type, the game ends when a specific score is reached
		 * @param shapes the shapes of tetrominoes to play during the game
		 * @param scoreToReach the score to reach to declare the game won
		 * @param level if specified, the game will start at a higher level of difficulty
		 * @param nbAlreadyPlacedBlocks if specified, the game Grid will be filled with randomly placed blocks at the bottom
		 * @sa tetris::model::Grid::Grid()
		 */
		GameTypeScore(std::vector<Tetromino::ConstructorComponents_type> shapes, long long int scoreToReach, int level = 0, int nbAlreadyPlacedBlocks = 0);

		/**
		 * Determines if the game is won
		 * @return true if the game is won, false else
		 */
		bool isWon() const override;
	};

} // namespace tetris::model

#endif //TETRIS_MODEL_GAMETYPESCORE_H
