#include "NextTetrominoDisplay.h"
#include <QGraphicsRectItem>
#include "util/QtColors.hpp"

#define BLOCK_SIZE 35

namespace tetris::view::gui {
	NextTetrominoDisplay::NextTetrominoDisplay(QWidget *parent):
	QGraphicsView(parent),
	_scene{new QGraphicsScene(this)}
	{
		this->setScene(_scene);
	}

	void NextTetrominoDisplay::updateNextTetromino(const model::Tetromino &tetromino) {
		_scene->clear();
		
		int newWidth = tetromino.getWidth() * BLOCK_SIZE;
		int newHeight = tetromino.getHeight() * BLOCK_SIZE;

		_scene->setSceneRect(0, 0, newWidth, newHeight);

		for (size_t i = 0; i < tetromino.getHeight(); i++) {
			for (size_t j = 0; j < tetromino.getWidth(); j++) {
				auto block = new QGraphicsRectItem(j * BLOCK_SIZE, i * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
				block->setPen(QPen{{30, 31, 34}});

				// if position (i, j) occupied, add block of the color
				if (tetromino.isOccupied(j, i)) {
					block->setBrush(QBrush(getQtColor(tetromino.get(j, i).getColor())));
				} else {
					block->setBrush(QBrush{{30, 31, 34}});
				}

				_scene->addItem(block);
			}
		}
	}

} // namespace tetris::view::gui