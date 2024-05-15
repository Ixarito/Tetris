#include <QVBoxLayout>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include "TetrisScene.h"
#include <QMessageBox>
#include "util/QtColors.hpp"

namespace tetris::view::gui {

	TetrisScene::TetrisScene(QWidget *parent)
			: QWidget(parent) {

		// initialize widgets
		gameBoard = new QGraphicsView(this);
		gameBoard->setFixedSize(365, 715);
		gameBoard->setBackgroundBrush(QBrush{{20,21,23}});

		scoreBoard = new ScoreBoard(this);
		scoreBoard->setFixedSize(150, 150);
		scoreBoardShadow = new QGraphicsDropShadowEffect(this);
		scoreBoardShadow->setColor({0, 0, 0, 150});
		scoreBoardShadow->setOffset(0, 0);
		scoreBoardShadow->setBlurRadius(200);
		gameBoard->setGraphicsEffect(scoreBoardShadow);

		nextTetromino = new NextTetrominoDisplay(this);
		nextTetromino->setFixedSize(150, 150);
		nextTetrominoShadow = new QGraphicsDropShadowEffect(this);
		nextTetrominoShadow->setColor({0, 0, 0, 150});
		nextTetrominoShadow->setOffset(0, 0);
		nextTetrominoShadow->setBlurRadius(200);
		nextTetromino->setGraphicsEffect(nextTetrominoShadow);

		auto mainLayout = new QHBoxLayout;
		mainLayout->setSpacing(40);
		mainLayout->setContentsMargins(40,40,40,40);

		mainLayout->addStretch(1);  // Ajoute un espace flexible à gauche des widgets
		mainLayout->addWidget(nextTetromino);
		mainLayout->addWidget(gameBoard);
		mainLayout->addWidget(scoreBoard);
		mainLayout->addStretch(1);  // Ajoute un espace flexible à droite des widgets

		this->setLayout(mainLayout);
	}

	TetrisScene::~TetrisScene() {
		delete gameBoard;
	}

	void TetrisScene::setGame(model::Game &game) {
		game.addObserver(this);

		scoreBoard->updateScore(game);
		updateGameBoard(game.getGridView());
	}

	void TetrisScene::updateGameBoard(const model::Game::GridView_type &gridView) {
		auto scene = new QGraphicsScene(this);

		int blockSize = 35;

		for (size_t i = 0; i < gridView.size(); i++) {
			for (size_t j = 0; j < gridView[i].length; j++) {
				// Si le bloc à la position (i, j) est occupé, ajouter un QGraphicsRectItem à la scène
				if (gridView[i].isOccupied(j)) {
					auto block = new QGraphicsRectItem(j * blockSize, i * blockSize, blockSize, blockSize);
					block->setBrush(QBrush(getQtColor(gridView[i][j].getColor())));
					block->setPen(QPen{{20,21,23}});
					scene->addItem(block);
				} else {
					auto block = new QGraphicsRectItem(j * blockSize, i * blockSize, blockSize, blockSize);
					block->setPen(QPen{{20,21,23}});
					block->setBrush(QBrush{{30, 31, 34}});
					scene->addItem(block);
				}
			}
		}

		gameBoard->setScene(scene);
	}


	void TetrisScene::update(ActionType action, void *subject) {
		auto game = static_cast<model::Game *>(subject);
		if (game) {
			switch (action) {
				case ActionType::DATA_UPDATED:
					scoreBoard->updateScore(*game);
					break;
				case ActionType::TETROMINO_INSERTED:
					nextTetromino->updateNextTetromino(game->peekNext());
				case ActionType::GRID_CHANGED:
					updateGameBoard(game->getGridView());
					break;
				default:;
			}
		}
	}

	void TetrisScene::displayGameOver(bool isWon) {
		auto message = isWon ? "You won!" : "Game Over!";
		QMessageBox msgBox;
		msgBox.setText(message);
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		if (msgBox.exec() == QMessageBox::Ok) {
			emit gameOverConfirmed();
		}
	}

	void TetrisScene::keyPressEvent(QKeyEvent *event) {
		emit keyboardInput(event->key());
	}

} // namespace tetris::view::gui