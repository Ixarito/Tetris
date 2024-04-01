#include "BasicDisplay.h"
#include <iostream>
#include "Game.h"
#include "Bag.h"
#include "Tetromino.h"
#include "BasicDisplay.h"
#include "Block.h"

using namespace tetris;




int main(){

	view::console::displayMessage("Hello World");

	struct model::GameParameters gp;

	gp.shapes = {{{
        {false, true, false},
        {true, true, true},
        {false, false, false}},
                  model::Color::BLUE}};
    gp.gridWidth = 10;
    gp.gridHeight = 20;
    gp.nbAlreadyPlacedBlocks = 0;
    gp.level = 1;



	model::Game game{gp};

    game.drop();


    std::cout << game.attachCurrent() << std::endl;






    view::console::displayGrid(game.getGridView());



	return 0;
}
