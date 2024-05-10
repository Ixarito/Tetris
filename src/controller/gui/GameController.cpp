#include "GameController.h"
#include <QDebug>

namespace tetris::controller::gui {

    GameController::GameController(model::Game &game) : _game(game) {
        timer = new QTimer();

		_game.addObserver(this);

        QObject::connect(timer, &QTimer::timeout, this, &GameController::movePiece);
    }

    void GameController::startGame() {
		timer->setInterval(100);
        timer->start(); //TODO : change this in function of the level
    }

    void GameController::stopGame() {
        timer->stop();
    }

    void GameController::movePiece() {
        _game.goDown();
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