#ifndef TETRIS_BASICDISPLAY_H
#define TETRIS_BASICDISPLAY_H

#include <string>

namespace tetris::view::console{

	/**
	 * Displays a message in the console
	 * @param message the message to display
	 */
	void displayMessage(const std::string & message);

} // namespace tetris::view::console

#endif //TETRIS_BASICDISPLAY_H
