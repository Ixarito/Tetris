#ifndef CMAKELISTS_TXT_NEXTTETROMINO_H
#define CMAKELISTS_TXT_NEXTTETROMINO_H


#include <QGraphicsView>
#include "Tetromino.h"

namespace tetris::view::gui {
	class NextTetromino : public QGraphicsView {

	Q_OBJECT

	public:

		NextTetromino(QWidget *parent = nullptr);

		void updateNextTetromino(const model::Tetromino &tetromino);


	};
}

#endif //CMAKELISTS_TXT_NEXTTETROMINO_H
