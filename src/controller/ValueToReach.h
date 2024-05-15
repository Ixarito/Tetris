#ifndef TETRIS_VALUETOREACH_H
#define TETRIS_VALUETOREACH_H

namespace tetris::controller {

	/**
	 * Represents the value to reach for a game type
	 */
	union ValueToReach {
		unsigned int line;
		unsigned long long score;
		long long duration;
	};

} // namespace tetris::controller

#endif //TETRIS_VALUETOREACH_H