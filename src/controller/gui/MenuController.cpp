#include <QCoreApplication>
#include "MenuController.h"
#include "Color.h"

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
		connect(&view, &view::gui::MenuScene::nbBlocksChanged, this, &MenuController::setAlreadyPlacedBlock);
		connect(&view, &view::gui::MenuScene::confirmButtonClicked, this, &MenuController::startGame);
		connect(&view, &view::gui::MenuScene::quitButtonClicked, this, &MenuController::quit);

		emit requestDisplay(&view);
	}

	void MenuController::setGameType(const int& value) {
		switch (value) {
			case 1:
				_gameType = GameType::TIME;
				break;
			case 2:
				_gameType = GameType::SCORE;
				break;
			case 3:
				_gameType = GameType::LINES;
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

	void MenuController::setTetrominoes(const std::vector<std::pair<std::vector<std::vector<bool>>, model::Color>> & tetrominoes) {
		_gameParams.shapes = tetrominoes;
	}

	void MenuController::startGame(){
		emit requestGameStart(_gameParams, _gameType, _valueToReach);
	}

	void MenuController::quit() {
		QCoreApplication::quit();
	}

} // namespace tetris::controller::gui
