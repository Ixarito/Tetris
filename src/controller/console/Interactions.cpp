#include <iostream>
#include <limits>
#include "Interactions.h"
#include "BasicDisplay.h"

#define MIN_DURATION 20

namespace tetris::controller::console{

	std::string getNextString(){
		std::string input;
        getline (std::cin, input);
		return input;
	}

	template<typename T>
	T getInput(const std::string & prompt) {
		T value;
		while (true) {
			view::console::displayPrompt(prompt);
			if (std::cin >> value) { // valeur ok
				break;
			} else {
				view::console::displayMessage("Erreur : Entrée invalide. Veuillez réessayer.");
				// ignorer et réinitaliser
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
		return value;
	}

	GameType ask4GameType(){
        view::console::displayMessage("Veuillez choisir un mode de jeu.\n\t1. Classique\n\t2. Contre la montre\n\t3. Victoire en fonction du score\n\t4. Victoire en fonction du nombre de lignes\n");
        int input{};
        while(input < 1 || input > 4){
            input = getInput<int>("Votre choix");

			if(input < 1 || input > 4) view::console::displayMessage("Choix non valide");
        }
        return static_cast<GameType>(input-1);
    }

	const unsigned int ask4LinesToReach() {
		auto lines = getInput<int>("Entrez l'objectif de lignes à atteindre");
        if(lines < 0)
        {
            lines *= -1;
        }
        return lines;
	}

	const unsigned long long int ask4ScoreToReach() {
		return getInput<unsigned long long>("Entrez le score à atteindre");
	}

	const long long ask4Duration() {
		long long duration {};

		while(duration < MIN_DURATION){
			duration = getInput<long long>("Entrez la durée souhaitée du jeu (secondes)");

			if(duration < MIN_DURATION){
				view::console::displayMessage("La durée du jeu doit être au moins égale à " + std::to_string(MIN_DURATION));
			}
		}

		return duration;
	}

} // namespace tetris::controller::console