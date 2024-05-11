#include <QMainWindow>
#include "Game.h"

namespace tetris::view::gui {

	class MainWindow : QMainWindow {

		MainWindow(QWidget *parent);

		void setHomeScene(QWidget * homeScene);

		void setTetrisScene(QWidget * tetrisScene);
	};

}// namespace tetris::view::gui