#include <QVBoxLayout>
#include <QGraphicsRectItem>
#include <iostream>
#include "TetrisWindow.h"

namespace tetris::view::gui{

TetrisWindow::TetrisWindow(QWidget *parent) : QMainWindow(parent) {
    // Initialisez vos widgets ici
    gameBoard = new QGraphicsView(this);
    scoreLabel = new QLabel("Score: 0", this);
    levelLabel = new QLabel("Level: 0", this);

    // Configurez vos widgets ici
    // Par exemple, vous pouvez définir la taille de gameBoard, définir le texte initial de scoreLabel et levelLabel, etc.
    gameBoard->setFixedSize(330, 630); // Taille arbitraire, à ajuster en fonction de vos besoins

    // Ajoutez vos widgets à la fenêtre ici
    // Vous pouvez utiliser un layout pour organiser vos widgets
    // Par exemple, vous pouvez ajouter gameBoard, scoreLabel et levelLabel à un QVBoxLayout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(gameBoard);
    layout->addWidget(scoreLabel);
    layout->addWidget(levelLabel);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

TetrisWindow::~TetrisWindow() {
    delete gameBoard;
    delete scoreLabel;
    delete levelLabel;
}

void TetrisWindow::updateGameBoard(const model::Grid::GridView_type& gridView) {
    // Crée une nouvelle scène
    QGraphicsScene *scene = new QGraphicsScene(this);

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
                block->setBrush(QBrush(Qt::gray));
                scene->addItem(block);
            }
        }
    }

    // Mettez à jour le gameBoard avec la nouvelle scène
    gameBoard->setScene(scene);
}

QColor TetrisWindow::getQtColor(tetris::model::Color color){
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



void TetrisWindow::startGame() {
    // Ajoutez le code pour démarrer le jeu ici
}

void TetrisWindow::stopGame() {
    // Ajoutez le code pour arrêter le jeu ici
}

void TetrisWindow::movePiece() {
    // Ajoutez le code pour déplacer la pièce de Tetris ici
}

} // namespace tetris::view::gui