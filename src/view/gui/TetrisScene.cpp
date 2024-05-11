#include <QVBoxLayout>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include "TetrisScene.h"
#include <iostream>
#include <QMessageBox>

namespace tetris::view::gui {

	TetrisWidget::TetrisWidget(model::Game &game, QWidget *parent)
			: QWidget(parent) {

		game.addObserver(this);

		// initialize widgets
		gameBoard = new QGraphicsView(this);
		gameBoard->setFixedSize(330, 630);

		auto dataContainer = initDataContainer(game);

		auto mainLayout = new QHBoxLayout;
		mainLayout->addWidget(gameBoard);
		mainLayout->addLayout(dataContainer);

		this->setLayout(mainLayout);


		updateGameBoard(game.getGridView());
	}

	TetrisWidget::~TetrisWidget() {
		delete gameBoard;
		delete scoreValue;
		delete levelValue;
		delete clearedLinesValue;
	}

	QLayout *TetrisWidget::initDataContainer(model::Game &game) {
		auto datasLayout = new QVBoxLayout;

		auto scoreLayout = new QHBoxLayout;
		auto levelLayout = new QHBoxLayout;
		auto clearedLinesLayout = new QHBoxLayout;

		auto scoreLabel = new QLabel("Score:", this);
		auto levelLabel = new QLabel("Level:", this);
		auto clearedLinesLabel = new QLabel("Full Lines:", this);

		scoreValue = new QLabel(this);
		levelValue = new QLabel(this);
		clearedLinesValue = new QLabel(this);

		updateDatasValues(game);

		scoreLayout->addWidget(scoreLabel);
		scoreLayout->addWidget(scoreValue);

		levelLayout->addWidget(levelLabel);
		levelLayout->addWidget(levelValue);

		clearedLinesLayout->addWidget(clearedLinesLabel);
		clearedLinesLayout->addWidget(clearedLinesValue);

		datasLayout->addLayout(scoreLayout);
		datasLayout->addLayout(levelLayout);
		datasLayout->addLayout(clearedLinesLayout);

		return datasLayout;
	}

	void TetrisWidget::updateDatasValues(model::Game &game) {
		scoreValue->setText(QString::number(game.getScore()));
		levelValue->setText(QString::number(game.getLevel()));
		clearedLinesValue->setText(QString::number(game.getNbClearedLines()));
	}

	void TetrisWidget::updateGameBoard(const model::Game::GridView_type &gridView) {
		// Crée une nouvelle scène
		auto scene = new QGraphicsScene(this);

		// taille de chaque bloc
		int blockSize = 30;

		for (size_t i = 0; i < gridView.size(); i++) {
			for (size_t j = 0; j < gridView[i].length; j++) {
				// Si le bloc à la position (i, j) est occupé, ajouter un QGraphicsRectItem à la scène
				if (gridView[i].isOccupied(j)) {
					auto block = new QGraphicsRectItem(j * blockSize, i * blockSize, blockSize, blockSize);
					block->setBrush(QBrush(getQtColor(gridView[i][j].getColor())));
					scene->addItem(block);
				} else {
					auto block = new QGraphicsRectItem(j * blockSize, i * blockSize, blockSize, blockSize);
					block->setPen(QPen{{20,20,20}});
					block->setBrush(QBrush{Qt::black});
					scene->addItem(block);
				}
			}
		}

		// Mettez à jour le gameBoard avec la nouvelle scène
		gameBoard->setScene(scene);
	}


	void TetrisWidget::update(ActionType action, void *subject) {
		auto game = static_cast<model::Game *>(subject);
		if (game) {
			switch (action) {
				case ActionType::DATA_UPDATED:
					updateDatasValues(*game);
					break;
				case ActionType::TETROMINO_INSERTED:
					// TODO update next Tetromino
					/* game->peekNext(); */
				case ActionType::GRID_CHANGED:
					updateGameBoard(game->getGridView());
					break;
				default:;
			}
		}
	}

	void TetrisWidget::displayGameOver(bool isWon) {
		auto message = isWon ? "You won!" : "Game Over!";
		QMessageBox::information(this, "Game Over", message);
	}

	void TetrisWidget::keyPressEvent(QKeyEvent *event) {
		emit keyboardInput(event->key());
	}

	QColor TetrisWidget::getQtColor(tetris::model::Color color) {
		switch (color) {
			case model::Color::BLUE:
				return {Qt::blue};
			case model::Color::GREEN:
				return {Qt::green};
			case model::Color::YELLOW:
				return {Qt::yellow};
			case model::Color::ORANGE:
				return {255, 165, 0};
			case model::Color::RED:
				return {Qt::red};
			case model::Color::CYAN:
				return {Qt::cyan};
			case model::Color::PURPLE:
				return {128, 0, 128};

			case model::Color::_count_:
				throw std::domain_error("Cannot use _count_ literal");
		}

		throw std::domain_error("Unknown Color used");
	}

} // namespace tetris::view::gui