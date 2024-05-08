#ifndef TETRIS_CONTROLLER_H
#define TETRIS_CONTROLLER_H

#include "Game.h"
#include "ConsoleView.h"
#include "GameType.h"

namespace tetris::controller::console{

/**
 * Console controller of the game Tetris
 */
class Controller {
	model::Game & game;
	view::console::ConsoleView view;

public:
	/**
	 * Initialize the controller of the game Tetris
	 * @param game the related game
	 * @sa tetris::model::Game
	 * @sa tetris::model::GameTypeLines
	 * @sa tetris::model::GameTypeScore
	 * @sa tetris::model::GameTypeTime
	 */
	explicit Controller(model::Game & game);

	/**
	 * Runs the game
	 */
	void run();

};

} // namespace tetris::controller::console

#endif //TETRIS_CONTROLLER_H
