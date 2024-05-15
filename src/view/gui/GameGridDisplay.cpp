#include <QGraphicsRectItem>
#include "GameGridDisplay.h"
#include "util/QtColors.hpp"

#define BLOCK_SIZE 35

namespace tetris::view::gui{

	GameGridDisplay::GameGridDisplay(QWidget *parent): QGraphicsView(parent), _scene{new QGraphicsScene(this)} {
		this->setBackgroundBrush(QBrush{{20,21,23}});

		this->setScene(_scene);
	}

	void GameGridDisplay::update(const model::Game::GridView_type &gridView) {
		_scene->clear();

		for (size_t i = 0; i < gridView.size(); i++) {
			for (size_t j = 0; j < gridView[i].length; j++) {
				auto block = new QGraphicsRectItem(j * BLOCK_SIZE, i * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
				block->setPen(QPen{{20,21,23}});

				// if position (i, j) occupied, add block of the color
				if (gridView[i].isOccupied(j)) {
					block->setBrush(QBrush(getQtColor(gridView[i][j].getColor())));
				} else {
					block->setBrush(QBrush{{30, 31, 34}});
				}

				_scene->addItem(block);
			}
		}
	}
} // namespace tetris::view::gui{
