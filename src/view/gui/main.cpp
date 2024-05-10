#include <QApplication>
#include "TetrisWindow.h"
#include "Game.h"

using namespace tetris;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

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

    model::Game game = model::Game(gp);

	view::gui::TetrisWindow window {game};
	window.show();

	// TODO remove
	for (int i = 0; i < 100; i++) {
		if(i % 5 == 0){
			game.goLeft();
		}
		game.goDown();
	}

    return QApplication::exec();
}