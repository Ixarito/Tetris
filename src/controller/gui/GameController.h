#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Game.h"
#include "Observer.h"
#include "TetrisScene.h"
#include "MenuController.h"
#include <QTimer>

namespace tetris::controller::gui {

	using namespace common;

	/**
	 * Controller of the GUI game Tetris
	 */
	class GameController : public QObject, Observer{
        Q_OBJECT

		model::Game * _game;
		view::gui::TetrisScene & _view;
		QTimer *timer;
    public:
		/**
		 * Creates a controller for the game Tetris
		 * @param view the view that displays the game
		 * @param game the game model
		 */
        GameController(view::gui::TetrisScene & view, model::Game * game = nullptr);

		/**
		 * Starts the game loop
		 */
        void startGame();

		/**
		 * Stops the game loop
		 */
        void stopGame();

	signals:

		/**
		 * Request to display the view
		 * @param view the Game view
		 */
		void requestDisplay(const QWidget * view);

    public slots:
		/**
		 * Contains the code of the game loop
		 */
        void tick();

		/**
		 * Executed when a keyboard input occurs
		 * @param key the key typed;
		 */
		void onInput(const int & key);

		/**
		 * Creates a new Game an launches it
		 * @param menuController the controller that contains the game settings
		 */
		void newGame(const MenuController & menuController);

	private:
		/**
		 * Updates the speed of the game
		 */
		void updateTimerInterval();

	public:
		// observer
		void update(ActionType action, void* subject);
    };

} // namespace tetris::controller::gui

#endif //GAMECONTROLLER_H