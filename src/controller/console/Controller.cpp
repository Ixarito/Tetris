#include <iostream>
#include <limits>
#include "Controller.h"
#include "Interactions.h"

namespace tetris::controller::console{

	Controller::Controller(model::Game & game) : game{game}, view{game} {}

	void Controller::run(){

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove what might remain in stdin

		view.showGame();

		while(!game.isGameOver() && !game.isWon()){
			auto input = getNextString();
			if (input == "s") {
				game.drop();
			} else if (input == "q") {
				game.goLeft();
			} else if (input == "d") {
				game.goRight();
			} else if (input == "e") {
				game.rotateClockwise();
			} else if (input == "a") {
				game.rotateCounterclockwise();
			}
			game.time();

			view.showGame();
		}

		if(game.isWon()){
			view.showWin();
		}else{
			view.showGameOver();
		}
	}

} // namespace tetris::controller::console