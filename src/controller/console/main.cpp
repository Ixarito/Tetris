#include "BasicDisplay.h"
#include "Game.h"
#include "Bag.h"
#include "Tetromino.h"

using namespace tetris;

int main(){

	view::console::displayMessage("Hello World");

	struct model::GameParameters gp;

	gp.shapes = {{{{true, false, true}, {true, true, true}, {true, false, true}}, model::Color::BLUE}};

	model::Game game{gp};

	game.rotateClockwise();

//	model::Tetromino t {{{true, false, true}, {true, true, true}, {true, false, true}}, model::Color::BLUE};
//
//	t.rotate(model::RotateDirection::CW);
//
//	model::Bag & instance {model::Bag::getInstance()};
//	instance.add({{{true, false, true}, {true, true, true}, {true, false, true}}, model::Color::BLUE});
//
//	model::Tetromino tetro = instance.getNext();
//
//	tetro.rotate(model::RotateDirection::CW);


	return 0;
}
