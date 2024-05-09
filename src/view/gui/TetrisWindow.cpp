#include <QVBoxLayout>
#include <QGraphicsRectItem>
#include <iostream>
#include "TetrisWindow.h"
#include "Grid.h"

TetrisWindow::TetrisWindow(QWidget *parent) : QMainWindow(parent) {
    // Initialisez vos widgets ici
    gameBoard = new QGraphicsView(this);
    scoreLabel = new QLabel("Score: 0", this);
    levelLabel = new QLabel("Level: 0", this);

    // Configurez vos widgets ici
    // Par exemple, vous pouvez définir la taille de gameBoard, définir le texte initial de scoreLabel et levelLabel, etc.
    gameBoard->setFixedSize(300, 600); // Taille arbitraire, à ajuster en fonction de vos besoins

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

void TetrisWindow::updateGameBoard(const tetris::model::Grid::GridView_type& gridView) {
    // Crée une nouvelle scène
    QGraphicsScene *scene = new QGraphicsScene(this);

    // Définisse la taille de chaque bloc
    int blockSize = 30; // Taille arbitraire, à ajuster en fonction de vos besoins

    // Parcoure le plateau de jeu
    for (size_t i = 0; i < gridView.size(); i++) {
        for (size_t j = 0; j < gridView[i].length; j++) {
            // Si le bloc à la position (i, j) est occupé, ajoutez un QGraphicsRectItem à la scène
            if (gridView[i].isOccupied(j)) {
                //print à l'écran
                std::cout << i << " " << j << std::endl;
                QGraphicsRectItem *block = new QGraphicsRectItem(j * blockSize, i * blockSize, blockSize, blockSize);
                block->setBrush(QBrush(Qt::red)); // Couleur arbitraire, à ajuster en fonction de vos besoins
                scene->addItem(block);
            } else {
                QGraphicsRectItem *block = new QGraphicsRectItem(j * blockSize, i * blockSize, blockSize, blockSize);
                block->setBrush(QBrush(Qt::gray)); // Couleur arbitraire, à ajuster en fonction de vos besoins
                scene->addItem(block);
            }
        }
    }

    // Mettez à jour le gameBoard avec la nouvelle scène
    gameBoard->setScene(scene);
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