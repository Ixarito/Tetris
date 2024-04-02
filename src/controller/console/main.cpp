#include <iostream>
#include "BasicDisplay.h"
#include "Game.h"
#include "Bag.h"
#include "Tetromino.h"
#include "BasicDisplay.h"
#include "Block.h"

using namespace tetris;




int main(){

    view::console::displayMessage("Hello World");

    struct model::GameParameters gp;

    gp.shapes = {{{{true, false, true}, {true, true, true}, {true, false, true}}, model::Color::BLUE}};
    gp.gridWidth = 10;
    gp.gridHeight = 20;
    gp.nbAlreadyPlacedBlocks = 0;
    gp.level = 1;


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
    game.drop();

    game.goDown();game.goDown();game.goDown();game.goDown();game.goDown();game.goDown();game.goDown();game.goDown();game.goDown();game.goDown();game.goDown();game.goDown();game.goDown();game.goLeft();game.goLeft();game.goDown();game.goDown();
    game.goDown();game.goLeft();






    view::console::displayGrid(game.getGridView());




    return 0;
}