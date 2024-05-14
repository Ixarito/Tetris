#include "GameController.h"
#include <QDebug>

#define INITIAL_INTERVAL 1000
#define INTERVAL_DECREASE 100
#define MIN_INTERVAL 50

namespace tetris::controller::gui {

    GameController::GameController(view::gui::TetrisScene & view, model::Game * game) : _game{game}, _view{view}, timer{new QTimer} {
		// link timer tick to handler
        QObject::connect(timer, &QTimer::timeout, this, &GameController::tick);
    }

    void GameController::startGame() {
		if(_game == nullptr) return;

		_view.setGame(*_game);

        timer->start();
		// link view input to handler
		QObject::connect(&_view, &view::gui::TetrisScene::keyboardInput, this, &GameController::onInput);

		emit requestDisplay(&_view);
    }

    void GameController::stopGame() {
		if(_game == nullptr) return;

        timer->stop();
		// remove link between view input and the handler
		QObject::disconnect(&_view, &view::gui::TetrisScene::keyboardInput, this, &GameController::onInput);
    }

	void GameController::onInput(const int &key){
		if(_game == nullptr) return;

		if(!_game->hasFallingTetromino()){
			_game->time(); // force reinsertion for more dynamic game
		}

		try {
			switch (key) {
				case Qt::Key_Q:
					_game->goLeft();
					break;
				case Qt::Key_D:
					_game->goRight();
					break;
				case Qt::Key_S:
					_game->goDown();
					break;
				case Qt::Key_A:
					_game->rotateCounterclockwise();
					break;
				case Qt::Key_E:
					_game->rotateClockwise();
					break;
				case Qt::Key_Space:
				case Qt::Key_Enter:
				case Qt::Key_Return:
					_game->drop();
					break;
			}
		}catch(std::logic_error & err){
			qWarning() << err.what();
		}
	}

    void GameController::tick() {
		if(_game == nullptr) return;

        _game->time();
    }

    void GameController::updateTimerInterval() {
		if(_game == nullptr) return;

        int interval = INITIAL_INTERVAL - _game->getLevel() * INTERVAL_DECREASE;

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
				case ActionType::GAME_WON:
                    stopGame();
                    _view.displayGameOver(action == ActionType::GAME_WON);
                    break;
				case ActionType::REQUEST_RESET_TIME_UNIT:
					if(timer->isActive()){
						timer->start(); // reset timer
					}
					break;
				default:;
            }
        }
    }

	void GameController::newGame(const MenuController &menuController) {
		try{
			const model::GameParameters & params = menuController.getGameParameters();
			const ValueToReach valueToReach = menuController.getValueToReach();

			switch(menuController.getGameType()){
				case GameType::GAMEOVER:
					_game = new model::Game(params);
					break;
				case GameType::LINES:
					_game = new model::GameTypeLines(params, valueToReach.line);
					break;
				case GameType::SCORE:
					_game = new model::GameTypeScore(params, valueToReach.score);
					break;
				case GameType::TIME:
					_game = new model::GameTypeTime(params, valueToReach.duration);
					break;
				default:
					throw std::domain_error("Unknown game type");
			}

			_game->addObserver(this);
			updateTimerInterval();

			startGame();
		}catch(std::invalid_argument & ex){ // no Tetrominoes specified
			qWarning() << ex.what();
		}
	}

} // namespace tetris::controller::gui