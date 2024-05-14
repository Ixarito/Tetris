#include "NextTetrominoDisplay.h"
#include <QGraphicsRectItem>
#include "util/QtColors.hpp"

namespace tetris::view::gui {
	NextTetrominoDisplay::NextTetrominoDisplay(QWidget *parent) : QGraphicsView(parent) {
		setFixedSize(35*5, 35*5);
	}

	void NextTetrominoDisplay::updateNextTetromino(const model::Tetromino &tetromino) {
		auto scene = new QGraphicsScene(this);

		int blockSize = 35;
		int newWidth = tetromino.getWidth() * blockSize;
		int newHeight = tetromino.getHeight() * blockSize;

		scene->setSceneRect(0, 0, newWidth, newHeight);

		for (size_t i = 0; i < tetromino.getHeight(); i++) {
			for (size_t j = 0; j < tetromino.getWidth(); j++) {
				if (tetromino.isOccupied(j, i)) {
					auto block = new QGraphicsRectItem(j * blockSize, i * blockSize, blockSize, blockSize);
					block->setBrush(QBrush(getQtColor(tetromino.get(j, i).getColor())));
					block->setPen(QPen{{30, 31, 34}});
					scene->addItem(block);
				} else {
					auto block = new QGraphicsRectItem(j * blockSize, i * blockSize, blockSize, blockSize);
					block->setPen(QPen{{30, 31, 34}});
					block->setBrush(QBrush{{30, 31, 34}});
					scene->addItem(block);
				}
			}
		}

		setScene(scene);
	}

} // namespace tetris::view::gui