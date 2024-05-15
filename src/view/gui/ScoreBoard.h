#ifndef TETRIS_SCOREBOARD_H
#define TETRIS_SCOREBOARD_H

#include <QGraphicsView>
#include <QLabel>
#include "Game.h"

namespace tetris::view::gui {

	class ScoreBoard : public QWidget{
		Q_OBJECT

		QLabel *scoreValue;
		QLabel *levelValue;
		QLabel *clearedLinesValue;

	public:
		/**
		 * Creates a layout for displaying the score board
		 * @param parent
		 */
		explicit ScoreBoard(QWidget *parent = nullptr);

		/**
		 * Updates the display
		 * @param game the game with the related values to display
		 */
		void updateScore(const model::Game & game) const;
	};

} // namespace tetris::view::gui

#endif //TETRIS_SCOREBOARD_H
