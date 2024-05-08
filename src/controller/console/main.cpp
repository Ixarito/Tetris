#ifdef _WIN32
#include <windows.h>

// MADE COLORS WORKS ON WINDOWS
void enableVirtualTerminalProcessing() {
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
}
#endif

// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

#include "ConsoleView.h"
#include "Interactions.h"
#include "Games.h"
#include "Controller.h"
#include <stdexcept>

// ↓↓↓ define to avoid debugger error ↓↓↓
//#define NDEBUG

namespace tetris::controller::console{

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
		}

		Controller(*game).run();

		delete game;
		game = nullptr;
	}

} // namespace tetris::controller::console

int main(){
	#ifdef _WIN32
		SetConsoleOutputCP(CP_UTF8);
		#ifndef NDEBUG
			enableVirtualTerminalProcessing();
		#endif
	#elif defined(__linux__) || defined(__APPLE__)
		setlocale(LC_ALL, "en_US.UTF-8");
	#endif

	tetris::controller::console::init();
}