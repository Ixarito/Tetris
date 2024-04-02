#define RESET   "\033[0m"
#define GRAY "\033[90m"
#include <iostream>
#include <vector>
#include <optional>
#include "BasicDisplay.h"

namespace tetris::view::console {
    using namespace std;

    void displayMessage(const std::string &message) {
        cout << message << endl;
    }

    std::string getColorCode(tetris::model::Color color) {
        switch (color) {
            case tetris::model::Color::BLUE:
                return "\033[94m";
            case tetris::model::Color::GREEN:
                return "\033[92m";
            case tetris::model::Color::YELLOW:
                return "\033[93m";
            case tetris::model::Color::ORANGE:
                return "\033[91m";
            case tetris::model::Color::RED:
                return "\033[91m";
            case tetris::model::Color::CYAN:
                return "\033[96m";
            case tetris::model::Color::PURPLE:
                return "\033[95m";
        }
    }


    void displayGrid(std::vector<model::Line> grid) {
        for (auto line : grid) {
            std::cout << GRAY << "<!" << RESET;
            for (size_t i = 0; i < line.length; i++) {
                if (line.isOccupied(i)) {
                    // Get the color code for the block
                    std::string colorCode = getColorCode(line.get(i).getColor());
                    cout << colorCode << "[]" << RESET;
                } else {
                    cout << GRAY << " ." << RESET;
                }
            }
            cout <<  GRAY <<  "!>" << RESET << endl;
        }
        cout << GRAY << "<!====================!>" << RESET

        << endl;
    }

} // namespace tetris::view::console