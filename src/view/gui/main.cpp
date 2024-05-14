#include <QApplication>
#include <QMainWindow>
#include "Game.h"
#include "GameController.h"
#include "MenuScene.h"
#include "MainWindow.h"
#include "MenuController.h"

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

    model::Game game {gp};
	view::gui::TetrisScene tetrisScene {game};
	view::gui::MenuScene menuScene;
	controller::gui::MenuController menuCtrl {menuScene};
	controller::gui::GameController controller {game, tetrisScene};
	view::gui::MainWindow mainWindow {menuScene, tetrisScene};
	mainWindow.setGameScene();

    controller.startGame();


    return QApplication::exec();
}