#include <QApplication>
#include "Game.h"
#include "GameController.h"
#include "MenuScene.h"
#include "MainWindow.h"

using namespace tetris;

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);

	auto menuScene = new view::gui::MenuScene();
	auto tetrisScene = new view::gui::TetrisScene();

	auto menuCtrl = new controller::gui::MenuController(*menuScene);
	auto gameCtrl = new controller::gui::GameController(*tetrisScene);

	view::gui::MainWindow mainWindow {*menuScene, *tetrisScene};

	QObject::connect(menuCtrl, &tetris::controller::gui::MenuController::requestGameStart, gameCtrl, &tetris::controller::gui::GameController::newGame);
	QObject::connect(menuCtrl, &tetris::controller::gui::MenuController::requestDisplay, &mainWindow, &tetris::view::gui::MainWindow::changeScene);
	QObject::connect(gameCtrl, &tetris::controller::gui::GameController::requestDisplay, &mainWindow, &tetris::view::gui::MainWindow::changeScene);
	QObject::connect(tetrisScene, &tetris::view::gui::TetrisScene::gameOverConfirmed, [&, menuScene](){
		mainWindow.changeScene(menuScene);
	});

	return QApplication::exec();
}