#ifndef TETRIS_DISPLAY_HPP
#define TETRIS_DISPLAY_HPP

#include <string>
#include <iostream>

namespace tetris::view::console{
	using namespace std;

	/**
	 * Displays a message in the console
	 * @param message the message to display
	 */
	inline void displayMessage(const std::string &message){
		cout << message << endl;
	}

	/**
	 * Displays a prompt to the user in the console
	 * @param message the prompt to display
	 */
	inline void displayPrompt(const std::string &message){
		cout << message << " :";
	}

} // namespace tetris::view::console

#endif //TETRIS_DISPLAY_HPP
