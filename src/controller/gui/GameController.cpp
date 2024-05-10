#include "GameController.h"
#include <QDebug>

#define INITIAL_INTERVAL 1000
#define INTERVAL_DECREASE 100
#define MIN_INTERVAL 50

namespace tetris::controller::gui {

    GameController::GameController(model::Game &game) : _game(game) {
        timer = new QTimer();

		_game.addObserver(this);

		updateTimerInterval();
        QObject::connect(timer, & QTimer::timeout, this, & GameController::tick);
    }

    void GameController::startGame() {
        timer->start();
    }

    void GameController::stopGame() {
        timer->stop();
    }

    void GameController::tick() {
        _game.goDown();
    }

	void GameController::updateTimerInterval() {
		int interval = INITIAL_INTERVAL - _game.getLevel() * INTERVAL_DECREASE;

		interval = std::max(interval, MIN_INTERVAL);
		timer->setInterval(interval);
	}

	void GameController::update(ActionType action, void * subject){
		auto game = static_cast<model::Game *>(subject);
		if(game){
			switch(action){
				case ActionType::DATA_UPDATED:
					updateTimerInterval();
					break;
				case ActionType::GAME_OVER:
					stopGame();
					qWarning() << "GameOver TODO"; // TODO
					break;
			}
		}
	}

} // namespace tetris::controller::gui