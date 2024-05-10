#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Game.h"
#include "Observer.h"
#include <QTimer>

namespace tetris::controller::gui {

	using namespace common;

	/**
	 * Controller of the GUI game Tetris
	 */
	class GameController : public QObject, Observer{
        Q_OBJECT

		model::Game & _game;
		QTimer *timer;
    public:
		/**
		 * Creates a controller for the game Tetris
		 * @param game the game model
		 */
        GameController(model::Game & game);

		/**
		 * Starts the game loop
		 */
        void startGame();

		/**
		 * Stops the game loop
		 */
        void stopGame();

    public slots:
		/**
		 * Contains the code of the game loop
		 */
        void tick();

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