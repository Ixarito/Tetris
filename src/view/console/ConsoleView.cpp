#define RESET "\033[0m"
#define GRAY "\033[90m"

#include <iostream>
#include "ConsoleView.h"

namespace tetris::view::console {
    using namespace std;

	/**
	 * Gives the color code associated to the enum literal
	 * @param color an enum literal that represents a color
	 * @return the color code
	 */
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

            case tetris::model::Color::_count_:
                throw std::domain_error("Cannot use _count_ literal");
        }

        throw std::domain_error("Unknown Color used");
    }


	ConsoleView::ConsoleView(const model::Game & game): game{game} {}

    void ConsoleView::showGame() const{
        auto grid{game.getGridView()};

		space(); // insert space between scenes
// display commands
        cout << "\t\t\t\t\t\t\t" << GRAY << R"(
                                                                Commandes:
                                                             ↺ [A]     [E] ↻
                                                               [Q] [S] [D]
                                                                ←   ↓   →

            )" << RESET << endl;


//        display the Full lines, level, score
        cout << GRAY << "\t\t\t\t\t\t" << "\033[91mFull lines: " << RESET << game.getNbClearedLines()
             << "\033[92m\tLevel: " << RESET << game.getLevel() << "\033[94m\tScore: " << RESET << game.getScore()
             << endl;
        for (auto line: grid) {
            std::cout << GRAY << "\t\t\t\t\t\t\t" << "<!" << RESET;
            for (size_t i = 0; i < line.length; i++) {
                if (line.isOccupied(i)) {
                    // Get the color code for the block
                    std::string colorCode = getColorCode(line.get(i).getColor());
                    cout << colorCode << "[]" << RESET;
                } else {
                    cout << GRAY << " ." << RESET;
                }
            }
            cout << GRAY << "!>";
            cout << RESET << endl;
        }
        cout << GRAY << "\t\t\t\t\t\t\t" << "<!====================!>" << RESET << endl;
        cout << GRAY << "\t\t\t\t\t\t\t" << "  \\/\\/\\/\\/\\/\\/\\/\\/\\/\\/" << RESET << endl;
    }


    void ConsoleView::showGameOver() const{
		space();

        cout << "\033[91m" << R"(
                                                            ,----..
  ,----..                         ____                     /   /   \
 /   /   \                      ,'  , `.                  /   .     :
|   :     :                  ,-+-,.' _ |                 .   /   ;.  \                     __  ,-.
.   |  ;. /               ,-+-. ;   , ||                .   ;   /  ` ;     .---.         ,' ,'/ /|
.   ; /--`    ,--.--.    ,--.'|'   |  || ,---.          ;   |  ; \ ; |   /.  ./|  ,---.  '  | |' |
;   | ;  __  /       \  |   |  ,', |  |,/     \         |   :  | ; | ' .-' . ' | /     \ |  |   ,'
|   : |.' .'.--.  .-. | |   | /  | |--'/    /  |        .   |  ' ' ' :/___/ \: |/    /  |'  :  /
.   | '_.' : \__\/: . . |   : |  | ,  .    ' / |        '   ;  \; /  |.   \  ' .    ' / ||  | '
'   ; : \  | ," .--.; | |   : |  |/   '   ;   /|         \   \  ',  /  \   \   '   ;   /|;  : |
'   | '/  .'/  /  ,.  | |   | |`-'    '   |  / |          ;   :    /    \   \  '   |  / ||  , ;
|   :    / ;  :   .'   \|   ;/        |   :    |           \   \ .'      \   \ |   :    | ---'
 \   \ .'  |  ,     .-./'---'          \   \  /             `---`         '---" \   \  /
  `---`     `--`---'                    `----'                                   `----'

            )" << RESET << endl;
    }

    void ConsoleView::showWin() const{
		space();

//        text Style : 3D diagonal
        cout << "\033[96m" << R"(
                                                                              ,---,
                                                                           ,`--.' |
                                  ___                                      |   :  :
       ,---.  ,--,              ,--.'|_             ,--,                   '   '  ;
      /__./|,--.'|              |  | :,'   ,---.  ,--.'|    __  ,-.        |   |  |
 ,---.;  ; ||  |,               :  : ' :  '   ,'\ |  |,   ,' ,'/ /|        '   :  ;
/___/ \  | |`--'_       ,---. .;__,'  /  /   /   |`--'_   '  | |' | ,---.  |   |  '
\   ;  \ ' |,' ,'|     /     \|  |   |  .   ; ,. :,' ,'|  |  |   ,'/     \ '   :  |
 \   \  \: |'  | |    /    / ':__,'| :  '   | |: :'  | |  '  :  / /    /  |;   |  ;
  ;   \  ' .|  | :   .    ' /   '  : |__'   | .; :|  | :  |  | ' .    ' / |`---'. |
   \   \   ''  : |__ '   ; :__  |  | '.'|   :    |'  : |__;  : | '   ;   /| `--..`;
    \   `  ;|  | '.'|'   | '.'| ;  :    ;\   \  / |  | '.'|  , ; '   |  / |.--,_
     :   \ |;  :    ;|   :    : |  ,   /  `----'  ;  :    ;---'  |   :    ||    |`.
      '---" |  ,   /  \   \  /   ---`-'           |  ,   /        \   \  / `-- -`, ;
             ---`-'    `----'                      ---`-'          `----'    '---`"
            )" << RESET << endl;
    }

	void ConsoleView::space() const {
		cout << std::string(30, '\n');
	}

} // namespace tetris::view::console