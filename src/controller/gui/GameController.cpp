#include "GameController.h"

namespace tetris::controller::gui {

    GameController::GameController(model::Game &game) : game(game) {
        timer = new QTimer();
        QObject::connect(timer, &QTimer::timeout, this, &GameController::movePiece);
    }

    void GameController::startGame() {
        timer->start(1000); //TODO : change this in function of the level
    }

    void GameController::stopGame() {
        timer->stop();
    }

    void GameController::movePiece() {
        game.goDown();
    }

} // namespace tetris::controller::gui