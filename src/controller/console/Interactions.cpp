#include <iostream>
#include <limits>
#include "Interactions.h"
#include "BasicDisplay.h"

#define MIN_DURATION 20

namespace tetris::controller::console{

	char getNextChar(){
		char input;
		std::cin.get(input);
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
		// TODO

		return GameType::TIME;
	}

	const unsigned int ask4LinesToReach() {
		return getInput<unsigned int>("Entrez l'objectif de lignes à atteindre");
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


		return 1;
	}

} // namespace tetris::controller::console