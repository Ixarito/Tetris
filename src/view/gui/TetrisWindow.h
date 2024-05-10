#include <QMainWindow>
#include <QGraphicsView>
#include <QLabel>
#include "Observer.h"
#include "Game.h"
#include "GameController.h"

namespace tetris::view::gui {
	using namespace common;

	/**
	 * Represents the graphical window of the game Tetris
	 */
	class TetrisWindow : public QMainWindow, Observer{
		Q_OBJECT

		QGraphicsView * gameBoard;
		QLabel * scoreValue;
		QLabel * levelValue;
		QLabel * clearedLinesValue;

	public:
		/**
		 * Creates a tetris game window
		 * @param game the game on which the view will be based
		 * @param parent the parent of the window
		 */
		explicit TetrisWindow(model::Game & game, tetris::controller::gui::GameController & controller, QWidget *parent = nullptr);

		/**
		 * Destructor of the window
		 */
		~TetrisWindow() override;

		/**
		 * No copy constructor
		 */
		TetrisWindow(TetrisWindow &) = delete;

		/**
		 * No copy assignment operator
		 */
		TetrisWindow & operator=(TetrisWindow &) = delete;

		/**
		 * Updates the board display
		 * @param gridView the view on which to base the display
		 */
		void updateGameBoard(const model::Game::GridView_type &gridView);

		// observer
		void update(ActionType action, void* subject) override;

    protected:
        void keyPressEvent(QKeyEvent *event) override;

	private:

        tetris::controller::gui::GameController & controller;

		/**
		 * Inits the data container
		 * @param game the game with which to recover the data's
		 * @return the layout that contains data's
		 */
		QLayout * initDataContainer(model::Game & game);

		/**
		 * Sets the values of game statistics
		 * @param game the game with which to recover the data's
		 */
		void updateDatasValues(model::Game & game);

		/**
		 * Gives the GUI color that corresponds to a model color
		 * @param color a model color
		 * @return a GUI color
		 */
		QColor getQtColor(tetris::model::Color color);

	};

} // namespace tetris::view::gui