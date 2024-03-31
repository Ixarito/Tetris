#ifndef TETRIS_MODEL_GAMETYPETIME_H
#define TETRIS_MODEL_GAMETYPETIME_H

#include "Game.h"
#include <chrono>

namespace tetris::model{

	/**
	 * Represents a specific type of Game, the game ends after a certain time
	 */
	class GameTypeTime: public Game{
		std::chrono::steady_clock::time_point _startTime{};
		const long long _duration{};

		 // TODO: modify class if Game can be paused
	public:

		/**
		 * Creates a game part of the Tetris game with the type time.
		 * With this type, the game ends after a certain time
		 * @param gameParams the parameters of the basic Game
		 * @param duration the time in seconds that the game will last
		 */
		GameTypeTime(const GameParameters & gameParams, const long long & duration);

		/**
		 * Determines if the game is won
		 * @return true if the game is won, false else
		 */
		bool isWon() const override;
	};

} // namespace tetris::model

#endif //TETRIS_MODEL_GAMETYPETIME_H
