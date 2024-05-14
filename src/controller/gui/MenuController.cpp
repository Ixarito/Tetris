#include "MenuController.h"

namespace tetris::controller::gui{

	MenuController::MenuController(view::gui::MenuScene &view)
		: _gameParams{}, _gameType{GameType::GAMEOVER}, _valueToReach{}
	{
		// default value for Tetrominoes
		setTetrominoes({
				// I-Tetromino
				{{{{false, false, false, false},
						  {true, true, true, true},
						  {false, false, false, false},
						  {false, false, false, false}}}, model::Color::CYAN},

				// O-Tetromino
				{{{{true, true},
						  {true, true}}}, model::Color::YELLOW},

				// T-Tetromino
				{{{{false, true, false},
						  {true, true, true},
						  {false, false, false}}}, model::Color::PURPLE},

				// S-Tetromino
				{{{{false, true, true},
						  {true, true, false},
						  {false, false, false}}}, model::Color::GREEN},

				// Z-Tetromino
				{{{{true, true, false},
						  {false, true, true},
						  {false, false, false}}}, model::Color::RED},

				// J-Tetromino
				{{{{true, false, false},
						  {true, true, true},
						  {false, false, false}}}, model::Color::BLUE},

				// L-Tetromino
				{{{{false, false, true},
						  {true, true, true},
						  {false, false, false}}}, model::Color::ORANGE}
		});

		// TODO Connect view signals to controller slots
	}

	void MenuController::setGameType(const GameType & type) {
		_gameType = type;
	}

	void MenuController::setValueToReach(const unsigned long long int & value) {
		switch (_gameType){
			case GameType::LINES :
				_valueToReach.line = value;
				break;
			case GameType::SCORE:
				_valueToReach.score = value;
				break;
			case GameType::TIME:
				_valueToReach.duration = value;
				break;
			default:;
		}
	}

	void MenuController::setLevel(const decltype(model::GameParameters::level) & level) {
		_gameParams.level = level;
	}

	void MenuController::setAlreadyPlacedBlock(const decltype(model::GameParameters::nbAlreadyPlacedBlocks) & value) {
		_gameParams.nbAlreadyPlacedBlocks = value;
	}

	void MenuController::setTetrominoes(const decltype(model::GameParameters::shapes) & tetrominoes) {
		_gameParams.shapes = tetrominoes;
	}

	void MenuController::startGame() const{
		// TODO call GameController
	}

	const model::GameParameters & MenuController::getGameParameters() const{
		return _gameParams;
	}

	const GameType & MenuController::getGameType() const {
		return _gameType;
	}

	const ValueToReach & MenuController::getValueToReach() const {
		return _valueToReach;
	}
} // namespace tetris::controller::gui
