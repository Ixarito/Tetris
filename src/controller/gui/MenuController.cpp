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

		// Connecting inputs to the controller
		connect(&view, &view::gui::MenuScene::gameTypeChanged, this, &MenuController::setGameType);
		connect(&view, &view::gui::MenuScene::additionalParameterChanged, this, &MenuController::setValueToReach);
		connect(&view, &view::gui::MenuScene::difficultyChanged, this, &MenuController::setLevel);
		connect(&view, &view::gui::MenuScene::blocksCheckedChanged, this, &MenuController::setAlreadyPlacedBlock);
		//TODO connect confirmButtonClicked to startGame


	}

	void MenuController::setGameType(const int& value) {
		switch (value) {
			case 0:
				_gameType = GameType::GAMEOVER;
				break;
			case 1:
				_gameType = GameType::LINES;
				break;
			case 2:
				_gameType = GameType::SCORE;
				break;
			case 3:
				_gameType = GameType::TIME;
				break;
			default:
				_gameType = GameType::GAMEOVER;

		}
	}

	void MenuController::setValueToReach(const int& value) {
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

	void MenuController::setLevel(const int& value) {
		_gameParams.level = value;
	}

	void MenuController::setAlreadyPlacedBlock(const int& value) {
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
