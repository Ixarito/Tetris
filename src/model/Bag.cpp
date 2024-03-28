#include <iostream>
#include "Bag.h"

namespace tetris::model{

	Bag::Bag(){
	}


	Bag & Bag::getInstance(){
		static Bag instance; // initialiser une fois instance en variable statique locale
		return instance;
	}

	void Bag::add(Tetromino tetromino){
		_list.push_back(tetromino);
	}

	Tetromino Bag::getNext() {
		auto next = _list[_next];
		_list[1];
		_next = (_next + 1) % _list.size();
		return next;
	}

	const Tetromino &Bag::peekNext() const {
		return _list[_next];
	}

} // namespace tetris::model