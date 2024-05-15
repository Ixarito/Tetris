#include "MainWindow.h"

namespace tetris::view::gui {

	MainWindow::MainWindow(MenuScene &menuScene, TetrisScene &tetrisScene, QWidget *parent)
			: QMainWindow(parent),stackedWidget{new QStackedWidget(this)},
			menuScene{menuScene}, tetrisScene{tetrisScene}
  	{
		stackedWidget->addWidget(&menuScene);
		stackedWidget->addWidget(&tetrisScene);
		setCentralWidget(stackedWidget);

		setStyleSheet("background-color: #1e1f22;");
		setWindowTitle("Tetris");

		this->show();
	}

	void MainWindow::changeScene(QPointer<QWidget> scene) {
		stackedWidget->setCurrentWidget(scene);
	}

} // namespace tetris::view::gui