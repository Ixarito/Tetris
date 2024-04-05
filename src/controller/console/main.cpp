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

// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

#include "BasicDisplay.h"
#include "Interactions.h"
#include "Games.h"
#include <stdexcept>
#include <iostream>

// ↓↓↓ define to avoid debugger error ↓↓↓
//#define NDEBUG

namespace tetris::controller::console{

	/**
	 * Runs the game
	 * @param game the Game to run
	 * @sa tetris::model::Game
	 * @sa tetris::model::GameTypeLine
	 * @sa tetris::model::GameTypeScore
	 * @sa tetris::model::GameTypeTime
	 */
	void run(model::Game & game){

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove what might remain in stdin

		view::console::displayMessage(std::string(30, '\n'));
		view::console::displayGame(game);

		while(game.isGameActive() && !game.isWon()){
			auto input = getNextString();
            if (input == "s") {
                game.drop();
            } else if (input == "q") {
                game.goLeft();
                game.goDown();
            } else if (input == "d") {
                game.goRight();
                game.goDown();
            } else if (input == "e") {
                game.rotateClockwise();
                game.goDown();
            } else if (input == "a") {
                game.rotateCounterclockwise();
                game.goDown();
            } else {
                game.goDown();
            }

			view::console::displayMessage(std::string(30, '\n'));
			view::console::displayGame(game);
		}

		view::console::displayMessage(std::string(30, '\n'));

		if(game.isWon()){
			view::console::displayWin();
		}else{
			view::console::displayGameOver();
		}
	}

	/**
	 * Init the game
	 */
	void init(){
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

		model::Game * game;

		auto gameType = ask4GameType();

		switch(gameType){
			case GameType::GAMEOVER:
				game = new model::Game(gp);
				break;
			case GameType::LINES:
				game = new model::GameTypeLines(gp, ask4LinesToReach());
				break;
			case GameType::SCORE:
				game = new model::GameTypeScore(gp, ask4ScoreToReach());
				break;
			case GameType::TIME:
				game = new model::GameTypeTime(gp, ask4Duration());
				break;
			default:
				throw std::domain_error("Unknown game type");
				break;
		}

		run(*game);

		delete game;
		game = nullptr;
	}

} // namespace tetris::controller::console

int main(){
	#ifdef _WIN32
		SetConsoleOutputCP(CP_UTF8);
	#elif defined(__linux__) || defined(__APPLE__)
		setlocale(LC_ALL, "en_US.UTF-8");
	#endif

	#ifndef NDEBUG
		enableVirtualTerminalProcessing();
	#endif

	tetris::controller::console::init();
}