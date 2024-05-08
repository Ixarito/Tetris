#ifndef TETRIS_CONSOLEVIEW_H
#define TETRIS_CONSOLEVIEW_H

#include <string>
#include "Game.h"

namespace tetris::view::console{

	class ConsoleView {
		const model::Game & game;

	public:
		/**
		 * Initialize a view to display in a console
		 * @param game the Game related to the view
		 */
		explicit ConsoleView(const model::Game & game);

		/**
		 * Displays the Tetris game view
		 */
		void showGame() const;

		/**
		 * Displays a GameOver message
		 */
		void showGameOver() const;

		/**
		 * Displays a win message
		 */
		void showWin() const;

		/**
		 * Inserts a space of 30 lines
		 */
		void space() const;

	};

} // namespace tetris::view::console

#endif //TETRIS_CONSOLEVIEW_H
