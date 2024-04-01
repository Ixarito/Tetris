#include <iostream>
#include <vector>
#include <optional>
#include "BasicDisplay.h"

namespace tetris::view::console{
	using namespace std;

	void displayMessage(const std::string &message) {
		cout << message << endl;
	}

    void displayGrid(std::vector<model::Line> grid) {
        for (auto line : grid) {
            for (size_t i = 0; i < line.length; i++) {
                if (line.isOccupied(i)) {
                    cout << " X ";
                } else {
                    cout << " . ";
                }
            }
            cout << endl;
        }
    }







} // namespace tetris::view::console
