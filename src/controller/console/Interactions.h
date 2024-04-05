#ifndef TETRIS_INTERACTIONS_H
#define TETRIS_INTERACTIONS_H

#include "GameType.h"

namespace tetris::controller::console{

	/**
	 * Gives the next string in the stdin
	 * @return the next char in the stdin
	 */
	std::string getNextString();

	/**
	 * Extracts the given type of the stdin
	 * @tparam T the type you want to get
	 * @param prompt a message to explain what the user has to do
	 * @return a value of the given type extracted from stdin
	 */
	template<typename T>
	T getInput(const std::string & prompt);

	/**
	 * Asks the user the game type he wants
	 * @return the chosen game type
	 * @sa tetris::controller::GameType
	 */
	GameType ask4GameType();

	/**
	 * Asks the user the number of line he wants reach
	 * @return the number of lines to reach
	 */
	const unsigned int ask4LinesToReach();

	/**
	 * Asks the user the score he wants reach
	 * @return the score to reach
	 */
	const unsigned long long int ask4ScoreToReach();

	/**
	 * Asks the user the duration the game will lasts
	 * @return the duration the game will lasts
	 */
	const long long ask4Duration();

} // namespace tetris::controller::console

#endif //TETRIS_INTERACTIONS_H
