#include <iostream>
#include "Interactions.h"

namespace tetris::controller::console{

	char getNextChar(){
		char input;
		std::cin.get(input);
		return input;
	}

	GameType ask4GameType(){
		// TODO

		return GameType::TIME;
	}

	const int ask4LinesToReach() {
		// TODO

		return 1;
	}

	const unsigned long long int ask4ScoreToReach() {
		// TODO

		return 1;
	}

	const long long ask4Duration() {
		// TODO

		return 1;
	}

} // namespace tetris::controller::console