#ifndef TETRIS_OBSERVABLE_H
#define TETRIS_OBSERVABLE_H

#include <vector>
#include "Observer.h"

namespace tetris::common{

	/**
	 * Represents an observable Object
	 * @sa tetris::common::Observer
	 */
	class Observable {
		std::vector<Observer *> observers;

	public:

		/**
		 * Adds an observer to the list of observers
		 * @param observer the observer to add
		 */
		virtual void addObserver(Observer * observer);

		/**
		 * Removes an observer from the list of observers
		 * @param observer the observer to remove
		 */
		virtual void removeObserver(Observer * observer);

	protected:
		/**
		 * Notifies all observers with the specified action
		 * @param action the action to notify
		 * @param subject the subject of the action
		 */
		virtual void notifyObservers(ActionType action, void * subject);
	};

} // namespace tetris::common

#endif //TETRIS_OBSERVABLE_H
