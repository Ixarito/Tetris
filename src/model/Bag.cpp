#include "Bag.h"
#include <algorithm>
#include <random>

namespace tetris::model{

	Bag::Bag(): _next {0}{}


	Bag & Bag::getInstance(){
		static Bag instance; // initialiser une fois instance en variable statique locale
		return instance;
	}

	void Bag::addAll(const std::vector<Tetromino::ConstructorComponents_type> & tetrominoes){

		for(const auto & tetromino: tetrominoes){
			_list.emplace_back(tetromino);
		}

		std::random_device rd;
		std::mt19937 g(rd());
		std::ranges::shuffle(_list, g);
	}

	Tetromino Bag::getNext() {
		auto next = _list[_next];
		_next = (_next + 1) % _list.size();
		if(_next == 0){
			std::random_device rd;
			std::mt19937 g(rd());
			std::ranges::shuffle(_list, g);
		}
		return next;
	}

	const Tetromino & Bag::peekNext() const {
		return _list[_next];
	}

} // namespace tetris::model