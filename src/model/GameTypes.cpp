#include "GameTypeLines.h"
#include "GameTypeScore.h"
#include "GameTypeTime.h"

namespace tetris::model{

	// --- Type Line --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

	GameTypeLines::GameTypeLines(const GameParameters & gameParams, const unsigned int & linesToReach):
		Game(gameParams), _linesToReach{linesToReach} {}

	bool GameTypeLines::isWon() const{
		return nbClearedLines >= _linesToReach;
	}


	// --- Type Score --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

	GameTypeScore::GameTypeScore(const GameParameters & gameParams, const unsigned long long int & scoreToReach):
		Game(gameParams), _scoreToReach{scoreToReach}
	{}

	bool GameTypeScore::isWon() const{
		return score >= _scoreToReach;
	}


	// --- Type Time --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

	GameTypeTime::GameTypeTime(const GameParameters & gameParams, const long long & duration):
		Game(gameParams), _startTime{std::chrono::steady_clock::now()}, _duration{duration}
	{}

	bool GameTypeTime::isWon() const{
		// steady_clock does not depend on system clock adjustments or time changes
		auto now = std::chrono::steady_clock::now();
		auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(now - _startTime).count();
		return elapsedSeconds >= _duration;
	}


} // namespace tetris::model