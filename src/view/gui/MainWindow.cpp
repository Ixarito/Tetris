#include "MainWindow.h"
#include <QStackedWidget>

namespace tetris::view::gui {

	MainWindow::MainWindow(MenuScene &menuScene, TetrisScene &tetrisScene, QWidget *parent)
			: QMainWindow(parent), menuScene(menuScene), tetrisScene(tetrisScene) {
		QStackedWidget *stackedWidget = new QStackedWidget(this);
		stackedWidget->addWidget(&tetrisScene);
		stackedWidget->addWidget(&menuScene);
		setCentralWidget(stackedWidget);
		currentSceneIndex = 0;
		setStyleSheet("background-color: #1e1f22;");
		setWindowTitle("Tetris");
		this->show();
	}


	void MainWindow::changeScene(QWidget* scene){
		QStackedWidget *stackedWidget = qobject_cast<QStackedWidget *>(centralWidget());
		if (stackedWidget) {
			stackedWidget->setCurrentWidget(scene);
		}
	}

} // namespace tetris::view::gui