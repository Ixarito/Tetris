#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Game.h"
#include "Observer.h"
#include "TetrisWindow.h"
#include <QTimer>

namespace tetris::controller::gui {

	using namespace common;

	/**
	 * Controller of the GUI game Tetris
	 */
	class GameController : public QObject, Observer{
        Q_OBJECT

		model::Game & _game;
		view::gui::TetrisWindow & _view;
		QTimer *timer;
    public:
		/**
		 * Creates a controller for the game Tetris
		 * @param game the game model
		 * @param view the view that displays the game
		 */
        GameController(model::Game & game, view::gui::TetrisWindow & view);

		/**
		 * Starts the game loop
		 */
        void startGame();

		/**
		 * Stops the game loop
		 */
        void stopGame();

        /**
         * Moves the current Tetromino to the left
         */
        void goLeft();

        /**
         * Moves the current Tetromino to the right
         */
        void goRight();

        /**
         * Moves the current Tetromino down
         */
        void drop();

        /**
         * Rotates the current Tetromino clockwise
         */
        void rotateClockwise();

        /**
         * Rotates the current Tetromino counterclockwise
         */
        void rotateCounterclockwise();


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