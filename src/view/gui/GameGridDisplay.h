#ifndef TETRIS_GAMEGRIDDISPLAY_H
#define TETRIS_GAMEGRIDDISPLAY_H

#include <QGraphicsView>
#include "Game.h"

namespace tetris::view::gui {

	/**
	 * Represents the display of the game grid
	 */
	class GameGridDisplay : public QGraphicsView{

		QGraphicsScene * _scene;

	public:
		/**
		 * Creates a display for the game grid
		 * @param parent pointer to the parent widget
		 */
		GameGridDisplay(QWidget *parent);

		/**
		 * Updates the display of the grid
		 * @param gridView the grid to display
		 */
		void update(const model::Game::GridView_type & gridView);
	};

} // namespace tetris::view::gui

#endif //TETRIS_GAMEGRIDDISPLAY_H
