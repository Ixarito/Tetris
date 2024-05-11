#ifndef TETRIS_ACTIONTYPE_H
#define TETRIS_ACTIONTYPE_H

namespace tetris::common{

	/**
	 * Represents the type of an action in the context of a Tetris Game
	 */
	enum class ActionType : char{
		/**
		 * Used when the grid has changed. Typically when a Tetromino is rotated, moved or placed
		 */
		GRID_CHANGED,
		/**
		 * Used when a Tetromino is inserted in the Grid.
		 * @sa tetris::model::Game::peekNext() (the next Tetromino changes after this action)
		 */
		TETROMINO_INSERTED,
		/**
		 * Used to report that the game’s statistics data has been updated.
		 */
		DATA_UPDATED,
		/**
		 * Used to report that the game is over
		 */
		GAME_OVER,
		/**
		 * Used to report that the game is won
		 */
		GAME_WON,
		/**
		 * Used to request to reset the time unit
		 */
		REQUEST_RESET_TIME_UNIT
	};

} // namespace tetris::common

#endif //TETRIS_ACTIONTYPE_H
