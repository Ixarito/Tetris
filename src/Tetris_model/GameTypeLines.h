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
		 * @param shapes the shapes of tetrominoes to play during the game
		 * @param linesToReach the number of lines to reach to declare the game won
		 * @param level if specified, the game will start at a higher level of difficulty
		 * @param nbAlreadyPlacedBlocks if specified, the game Grid will be filled with randomly placed blocks at the bottom
		 * @sa tetris::model::Grid::Grid()
		 */
		GameTypeLines(std::vector<Tetromino::ConstructorComponents_type> shapes, int linesToReach, int level = 0, int nbAlreadyPlacedBlocks = 0);

		/**
		 * Determines if the game is won
		 * @return true if the game is won, false else
		 */
		bool isWon() const override;
	};

} // namespace tetris::model

#endif //TETRIS_MODEL_GAMETYPELINES_H
