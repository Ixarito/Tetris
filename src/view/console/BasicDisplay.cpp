#include <iostream>
#include "BasicDisplay.h"

namespace tetris::view::console{
	using namespace std;

	void displayMessage(const std::string &message) {
		cout << message << endl;
	}
} // namespace tetris::view::console
