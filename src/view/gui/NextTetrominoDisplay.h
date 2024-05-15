#ifndef NEXT_TETROMINO_DISPLAY_H
#define NEXT_TETROMINO_DISPLAY_H


#include <QGraphicsView>
#include "Tetromino.h"

namespace tetris::view::gui {

	/**
	 * Represents the display that shows the next Tetromino to be inserted
	 */
	class NextTetrominoDisplay : public QGraphicsView {

		QGraphicsScene * _scene;

	public:

		/**
		 * Creates a layout for displaying the next Tetromino to be inserted
		 * @param parent
		 */
		NextTetrominoDisplay(QWidget *parent = nullptr);

		/**
		 * Sets the next Tetromino
		 * @param tetromino the next Tetromino to be inserted
		 */
		void updateNextTetromino(const model::Tetromino &tetromino);

	};
}

#endif //NEXT_TETROMINO_DISPLAY_H
