#ifndef TETRIS_MODEL_COLOR_H
#define TETRIS_MODEL_COLOR_H

namespace tetris::model {

	/**
	 * Represents the color of a block in the Tetris game
	 */
	enum class Color : char{
		BLUE, GREEN, YELLOW, ORANGE, RED, CYAN, PURPLE,

		_count_ // used to determine the number of elements in the enum
	};

} // namespace tetris::model

#endif //TETRIS_MODEL_COLOR_H
