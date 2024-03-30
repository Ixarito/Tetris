#include <stdexcept>
#include "Line.h"

namespace tetris::model {


	Line::Line(size_t length) : _content(length), length(length) {}


	void Line::set(size_t position, Block &block) {
		if (position >= length) {
			throw std::out_of_range("invalid position");
		}
		_content[position] = block;
	}


	Block &Line::get(size_t position) {
		if (position >= length) {
			throw std::out_of_range("invalid position");
		}
		return _content[position].value();
	}

	const Block &Line::get(size_t position) const {
		if (position >= length) {
			throw std::out_of_range("invalid position");
		}
		return _content[position].value();
	}


	bool Line::isFull() const {
		for (auto block: _content) {
			if (!block.has_value()) {
				return false;
			}
		}
		return true;
	}


	void Line::clear() {
		for (auto block : _content){
			block.reset();
		}
	}


	Block &Line::operator[](size_t position) {
		if (position >= length) {
			throw std::out_of_range("invalid position");
		}
		return *_content[position];
	}


	const Block &Line::operator[](size_t position) const{
		if (position >= length) {
			throw std::out_of_range("invalid position");
		}
		return *_content[position];
	}


	auto Line::begin() const -> decltype(_content.begin()) {
		return _content.begin();
	}

	auto Line::cbegin() const -> decltype(_content.cbegin()) {
		return _content.cbegin();
	}

	auto Line::end() const -> decltype(_content.end()) {
		return _content.end();
	}

	auto Line::cend() const -> decltype(_content.cend()) {
		return _content.cend();
	}


} // namespace tetris::model