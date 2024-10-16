#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Games.h"
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
        explicit GameController(view::gui::TetrisScene & view, model::Game * game = nullptr);

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
		void requestDisplay(QPointer<QWidget> view);

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
		 * @param params the game parameters
		 * @param gameType the type chosen for the game
		 * @param valueToReach the value to reach if a game type is chosen
		 */
		void newGame(const model::GameParameters & params, const GameType & gameType, const ValueToReach & valueToReach);

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