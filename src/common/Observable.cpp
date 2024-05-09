#include <algorithm>
#include "Observable.h"

namespace tetris::common{

	void Observable::addObserver(Observer * observer){
		observers.push_back(observer);
	}

	void Observable::removeObserver(Observer * observer){
		auto it = std::ranges::find(observers, observer);
		if(it != observers.end()){
			observers.erase(it);
		}
	}

	void Observable::notifyObservers(ActionType action, void * subject){
		for(Observer * observer : observers){
			observer->update(action, subject);
		}
	}

} // namespace tetris::common
