#include <iostream>
#include "GameController.h"
#include <QDebug>

namespace tetris::controller::gui {

    GameController::GameController(model::Game &game) : game(game) {
        timer = new QTimer();

		game.addObserver(this);

        QObject::connect(timer, &QTimer::timeout, this, &GameController::movePiece);
    }

    void GameController::startGame() {
        timer->start(100); //TODO : change this in function of the level
    }

    void GameController::stopGame() {
        timer->stop();
    }

    void GameController::movePiece() {
        game.goDown();
    }

	void GameController::update(ActionType action, void * subject){
		auto game = static_cast<model::Game *>(subject);
		if(game){
			switch(action){
				case ActionType::GAME_OVER:
					stopGame();
					qWarning() << "GameOver TODO"; // TODO
					break;
			}
		}
	}

} // namespace tetris::controller::gui