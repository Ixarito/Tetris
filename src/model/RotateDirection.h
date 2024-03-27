#ifndef TETRIS_MODEL_ROTATEDIRECTION_H
#define TETRIS_MODEL_ROTATEDIRECTION_H

namespace tetris::model {

	/**
	 * Represents a direction of rotation for a Tetromino in the Tetris game
	 * CW : Clockwise
	 * CCW : Counter-Clockwise
	 */
	enum class RotateDirection : char{
		CCW, CW
	};

} // namespace tetris::model

#endif //TETRIS_MODEL_ROTATEDIRECTION_H
