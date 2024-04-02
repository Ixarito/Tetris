#ifndef TETRIS_BASICDISPLAY_H
#define TETRIS_BASICDISPLAY_H

#include <string>
#include <vector>
#include <optional>
#include "../../model/Game.h"
#include "../../model/Color.h"



namespace tetris::view::console{

	/**
	 * Displays a message in the console
	 * @param message the message to display
	 */
	void displayMessage(const std::string & message);

    void displayGame(const model::Game & game);

    void displayGameOver();





} // namespace tetris::view::console

#endif //TETRIS_BASICDISPLAY_H
