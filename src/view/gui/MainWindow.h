#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MenuController.h"
#include "MenuScene.h"
#include "TetrisScene.h"
#include <QPointer>
#include <QStackedWidget>

namespace tetris::view::gui {

	/**
	 * Represents the main window of the application
	 */
	class MainWindow : public QMainWindow {
		Q_OBJECT

		QStackedWidget *stackedWidget;
		MenuScene& menuScene;
		TetrisScene& tetrisScene;

	public:

		/**
		 * Initialize the main window
		 * @param menuScene the scene that represents the menu
		 * @param tetrisScene the scene that represents the game
		 * @param parent the parent widget
		 */
		explicit MainWindow(MenuScene &menuScene, TetrisScene& tetrisScene, QWidget *parent = nullptr);

	public slots:
		/**
		 * Change the scene to the given widget
		 * @param scene the scene to display
		 */
		void changeScene(QPointer<QWidget> scene);

	};

} // namespace tetris::view::gui

#endif //MAINWINDOW_H