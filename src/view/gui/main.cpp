#include <QApplication>
#include "Game.h"
#include "GameController.h"
#include "MenuScene.h"
#include "MainWindow.h"

using namespace tetris;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

	view::gui::MenuScene menuScene;
	view::gui::TetrisScene tetrisScene;

	controller::gui::MenuController menuCtrl {menuScene};
	controller::gui::GameController controller {tetrisScene};

	view::gui::MainWindow mainWindow {menuScene, tetrisScene};

	QObject::connect(&menuCtrl, &tetris::controller::gui::MenuController::requestDisplay, &mainWindow, &tetris::view::gui::MainWindow::changeScene);

    return QApplication::exec();
}