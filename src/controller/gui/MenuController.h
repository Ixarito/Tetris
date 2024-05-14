#ifndef TETRIS_MENUCONTROLLER_H
#define TETRIS_MENUCONTROLLER_H

#include <QObject>
#include "MenuScene.h"
#include "Games.h"
#include "GameType.h"
#include "ValueToReach.h"

namespace tetris::controller::gui {

	/**
	 * Controller of the Tetris home menu
	 */
	class MenuController: public QObject {
		Q_OBJECT

		model::GameParameters _gameParams;
		GameType _gameType;
		ValueToReach _valueToReach;
	public:
		/**
		 * Creates a menu controller
		 * @param view the view to link to the controller
		 */
		MenuController(view::gui::MenuScene & view);


	signals:

		/**
		 * Signal for request to launch a Tetris Game
		 * @param menuController the controller that contains the game settings
		 */
		void requestGameStart(const MenuController & menuController);

		/**
		 * Request to display the view
		 * @param view the Game view
		 */
		void requestDisplay(const QWidget * view);

	public slots:

		/**
		 * Sets the game type
		 * @param type the type of the game
		 */
		void setGameType(const int& value);

		/**
		 * Sets the value to reach according to the game type
		 * @param value the value to reach
		 */
		void setValueToReach(const int& value);

		/**
		 * Sets the start level of the game
		 * @param level the start level
		 * @sa tetris::model::Game::Game()
		 */
		void setLevel(const int& value);

		/**
		 * Sets the number of blocks to place at the start of the game
		 * @param value the number of blocks to place
		 * @sa tetris::model::Game::Game()
		 */
		void setAlreadyPlacedBlock(const int& value);

		/**
		 * Sets the tetrominoes to use during the game
		 * @param tetrominoes a collection of Tetrominoes
		 */
		void setTetrominoes(const std::vector<std::pair<std::vector<std::vector<bool>>, model::Color>> & tetrominoes);

		/**
		 * Calls the GameController for start the game with the current saved configuration
		 */
		void startGame();

	public:
		/**
		 * Gives the parameters for the Game
		 * @return the game parameters
		 */
		const model::GameParameters & getGameParameters() const;

		/**
		 * Gives the selected type for the game
		 * @return the type for the Game
		 */
		const GameType & getGameType() const;

		/**
		 * Gives the selected value to reach for the game type
		 * @return the value to reach
		 */
		const ValueToReach & getValueToReach() const;
	};

} // namespace tetris::controller::gui


#endif //TETRIS_MENUCONTROLLER_H
