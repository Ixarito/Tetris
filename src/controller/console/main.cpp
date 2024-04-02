//MADE COLORS WORKS ON WINDOWS
#ifdef _WIN32
#include <windows.h>
#endif

void enableVirtualTerminalProcessing() {
#ifdef _WIN32
    // Get the handle to the standard output device.
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    if (hOut == INVALID_HANDLE_VALUE) {
        exit(GetLastError());
    }

    DWORD dwMode = 0;

    // Get the current output mode.
    if (!GetConsoleMode(hOut, &dwMode)) {
        exit(GetLastError());
    }

    // Enable the virtual terminal processing mode.
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

    if (!SetConsoleMode(hOut, dwMode)) {
        exit(GetLastError());
    }
#endif
}

#include <iostream>
#include "BasicDisplay.h"
#include "Game.h"
#include "Bag.h"
#include "Tetromino.h"
#include "BasicDisplay.h"
#include "Block.h"


using namespace tetris;



int main(){
    enableVirtualTerminalProcessing();




    struct model::GameParameters gp;

    gp.shapes = {
            // I-Tetromino
            {{{{false, false, false, false},
                      {true, true, true, true},
                      {false, false, false, false},
                      {false, false, false, false}}}, model::Color::CYAN},

            // O-Tetromino
            {{{{true, true},
                      {true, true}}}, model::Color::YELLOW},

            // T-Tetromino
            {{{{false, true, false},
                      {true, true, true},
                      {false, false, false}}}, model::Color::PURPLE},

            // S-Tetromino
            {{{{false, true, true},
                      {true, true, false},
                      {false, false, false}}}, model::Color::GREEN},

            // Z-Tetromino
            {{{{true, true, false},
                      {false, true, true},
                      {false, false, false}}}, model::Color::RED},

            // J-Tetromino
            {{{{true, false, false},
                      {true, true, true},
                      {false, false, false}}}, model::Color::BLUE},

            // L-Tetromino
            {{{{false, false, true},
                      {true, true, true},
                      {false, false, false}}}, model::Color::ORANGE}
    };
    gp.gridWidth = 10;
    gp.gridHeight = 20;
    gp.nbAlreadyPlacedBlocks = 0;
    gp.level = 1;



    model::Game game{gp};

    while(game.isGameActive()){
        char input;
        std::cin.get(input);
        std::cout << std::string(30, '\n');
        switch (input) {
            case 'm':
                return 0;
            case 's':
                game.drop();
                break;
            case 'q':
                game.goLeft();
                break;
            case 'd':
                game.goRight();
                break;
            case 'e':
                game.rotateClockwise();
                break;
            case 'a':
                game.rotateCounterclockwise();
                break;

            case '\n':
                game.goDown();
                break;
            default:
                break;
        }

        view::console::displayGame(game);
        std::cout << "\n\n" << std::endl;

    }

    std::cout << std::string(30, '\n');
    view::console::displayGameOver();

}