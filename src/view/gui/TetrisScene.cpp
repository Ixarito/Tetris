#include <QVBoxLayout>
#include <QKeyEvent>
#include "TetrisScene.h"
#include <QMessageBox>

namespace tetris::view::gui {

	TetrisScene::TetrisScene(QWidget *parent)
		: QWidget(parent),
		  gameGrid {new GameGridDisplay(this)},
		  scoreBoard {new ScoreBoard(this)},
		  nextTetromino{new NextTetrominoDisplay(this)}
	{
		// shadows
		auto gridShadow = new QGraphicsDropShadowEffect(gameGrid);
		auto nextTetrominoShadow = new QGraphicsDropShadowEffect(nextTetromino);

		gridShadow->setColor({0, 0, 0, 150});
		gridShadow->setOffset(0, 0);
		gridShadow->setBlurRadius(200);

		nextTetrominoShadow->setColor({0, 0, 0, 150});
		nextTetrominoShadow->setOffset(0, 0);
		nextTetrominoShadow->setBlurRadius(200);

		gameGrid->setGraphicsEffect(gridShadow);
		nextTetromino->setGraphicsEffect(nextTetrominoShadow);

		// sizes
		scoreBoard->setFixedSize(150, 150);
		gameGrid->setFixedSize(365, 715);
		nextTetromino->setFixedSize(150, 150);

		// layout
		auto mainLayout = new QHBoxLayout(this);
		mainLayout->setSpacing(40);
		mainLayout->setContentsMargins(40,40,40,40);

		mainLayout->addStretch(1);  // Ajoute un espace flexible à gauche des widgets
		mainLayout->addWidget(nextTetromino);
		mainLayout->addWidget(gameGrid);
		mainLayout->addWidget(scoreBoard);
		mainLayout->addStretch(1);  // Ajoute un espace flexible à droite des widgets

		this->setLayout(mainLayout);
	}

	void TetrisScene::setGame(model::Game &game) {
		game.addObserver(this);

		scoreBoard->updateScore(game);
		gameGrid->update(game.getGridView());
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
					gameGrid->update(game->getGridView());
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