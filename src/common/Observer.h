#ifndef TETRIS_OBSERVER_H
#define TETRIS_OBSERVER_H

#include "ActionType.h"

namespace tetris::common{

	/**
	 * Represents an Observer object
	 * @sa tetris::common::Observable
	 */
	class Observer {
	public:

		/**
		 * Called by the observable when a change occurs.
		 * @param action the action that appended
		 * @param subject subject of the action, typically the Observable object
		 *
		 * implementation example:
		 * @code
		 * void update(ActionType action, void* subject) {
		 *	 	if (action == ActionType::ModelUpdated) {
		 *			MyModel* model = dynamic_cast<MyModel*>(subject);
		 *			if (model) {
		 *				// some code
		 *			}
		 *		}
		 * }
		 * @endcode
		 */
		virtual void update(ActionType action, void* subject) = 0;

	};


} // namespace tetris::common

#endif //TETRIS_OBSERVER_H
