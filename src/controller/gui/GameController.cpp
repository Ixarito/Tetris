#include "GameController.h"
#include <QDebug>

#define INITIAL_INTERVAL 1000
#define INTERVAL_DECREASE 100
#define MIN_INTERVAL 50

namespace tetris::controller::gui {

    GameController::GameController(model::Game &game, view::gui::TetrisWidget & view) : _game(game), _view{view} {
        timer = new QTimer();

        _game.addObserver(this);

        updateTimerInterval();
		// link timer tick to handler
        QObject::connect(timer, &QTimer::timeout, this, &GameController::tick);
		// link view input to handler
        QObject::connect(&_view, &view::gui::TetrisWidget::keyboardInput, this, &GameController::onInput);
    }

    void GameController::startGame() {
        timer->start();
    }

    void GameController::stopGame() {
        timer->stop();
    }

	void GameController::onInput(const int &key){
		try {
			switch (key) {
				case Qt::Key_Q:
					_game.goLeft();
					break;
				case Qt::Key_D:
					_game.goRight();
					break;
				case Qt::Key_S:
					_game.drop();
					break;
				case Qt::Key_A:
					_game.rotateCounterclockwise();
					break;
				case Qt::Key_E:
					_game.rotateClockwise();
					break;
			}
		}catch(std::logic_error &e){qWarning() << e.what();} // FIXME
	}

    void GameController::tick() {
        _game.goDown();
    }

    void GameController::updateTimerInterval() {
        int interval = INITIAL_INTERVAL - _game.getLevel() * INTERVAL_DECREASE;

        interval = std::max(interval, MIN_INTERVAL);
        timer->setInterval(interval);
    }

    void GameController::update(ActionType action, void *subject) {
        auto game = static_cast<model::Game *>(subject);
        if (game) {
            switch (action) {
                case ActionType::DATA_UPDATED:
                    updateTimerInterval();
                    break;
                case ActionType::GAME_OVER:
                    stopGame();
                    _view.displayGameOver(false);
                    break;
            }
        }
    }

} // namespace tetris::controller::gui