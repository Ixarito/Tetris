#ifndef TETRIS_BASICDISPLAY_H
#define TETRIS_BASICDISPLAY_H

#include <string>
#include "Game.h"


namespace tetris::view::console{

	/**
	 * Displays a message in the console
	 * @param message the message to display
	 */
	void displayMessage(const std::string & message);

	/**
	 * Displays a prompt to the user in the console
	 * @param message the prompt to display
	 */
	void displayPrompt(const std::string &message);

	/**
	 * Displays the Tetris game view
	 * @param game the Game to display
	 */
    void displayGame(const model::Game & game);

	/**
	 * Displays a GameOver message
	 */
    void displayGameOver();

	/**
	 * Displays a win message
	 */
	void displayWin();

} // namespace tetris::view::console

#endif //TETRIS_BASICDISPLAY_H
