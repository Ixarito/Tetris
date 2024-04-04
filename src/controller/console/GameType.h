#ifndef TETRIS_GAMETYPE_H
#define TETRIS_GAMETYPE_H

namespace tetris::controller {

/**
 * Represents the possible types of a game
 */
	enum class GameType : char {
		GAMEOVER, TIME, SCORE, LINES
	};

#endif //TETRIS_GAMETYPE_H

} // namespace tetris::controller
