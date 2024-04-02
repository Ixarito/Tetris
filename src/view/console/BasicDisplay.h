#ifndef TETRIS_BASICDISPLAY_H
#define TETRIS_BASICDISPLAY_H

#include <string>
#include <vector>
#include <optional>
#include "../../model/Line.h"
#include "../../model/Color.h"



namespace tetris::view::console{

	/**
	 * Displays a message in the console
	 * @param message the message to display
	 */
	void displayMessage(const std::string & message);

    void displayGrid(std::vector<model::Line> grid);

    std::string getColorCode(tetris::model::Color color);





} // namespace tetris::view::console

#endif //TETRIS_BASICDISPLAY_H
