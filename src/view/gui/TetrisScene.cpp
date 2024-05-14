#include <QVBoxLayout>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include "TetrisScene.h"
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>
#include "util/QtColors.hpp"

namespace tetris::view::gui {

	TetrisScene::TetrisScene(model::Game &game, QWidget *parent)
			: QWidget(parent) {

		game.addObserver(this);

		// initialize widgets
		gameBoard = new QGraphicsView(this);
		gameBoard->setFixedSize(385, 735);
		gameBoard->setBackgroundBrush(QBrush{Qt::black});

		scoreBoard = new ScoreBoard(this);
		scoreBoard->updateScore(game);

		// Créez une nouvelle instance de QGraphicsDropShadowEffect
		auto shadowEffect = new QGraphicsDropShadowEffect(this);

		// Définissez la couleur de l'ombre à blanc
		shadowEffect->setColor({255, 255, 255, 30});

		// Définissez le décalage de l'ombre
		shadowEffect->setOffset(0, 0);
		shadowEffect->setBlurRadius(100);

		// Appliquez l'effet d'ombre au gameBoard
		gameBoard->setGraphicsEffect(shadowEffect);

		nextTetromino = new NextTetrominoDisplay(this);

		auto mainLayout = new QHBoxLayout;
		mainLayout->setSpacing(40);
		mainLayout->setContentsMargins(40,40,40,40);
		mainLayout->addWidget(nextTetromino);
		mainLayout->addWidget(gameBoard);
		mainLayout->addWidget(scoreBoard);

		this->setLayout(mainLayout);

		updateGameBoard(game.getGridView());
	}

	TetrisScene::~TetrisScene() {
		delete gameBoard;
	}

	void TetrisScene::updateGameBoard(const model::Game::GridView_type &gridView) {
		// Crée une nouvelle scène
		auto scene = new QGraphicsScene(this);

		// taille de chaque bloc
		int blockSize = 35;

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
		QMessageBox::information(this, "Game Over", message);
	}

	void TetrisScene::keyPressEvent(QKeyEvent *event) {
		emit keyboardInput(event->key());
	}

} // namespace tetris::view::gui