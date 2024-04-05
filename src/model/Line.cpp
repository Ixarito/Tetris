#include <stdexcept>
#include <algorithm>
#include "Line.h"
#include "util/outOfRangeMessage.hpp"

namespace tetris::model {


	Line::Line(const size_t & length) : _content(length), length{length} {}


	void Line::set(const size_t & position, const Block &block) {
		if (position >= length) {
			throw std::out_of_range(util::OORmessage(position, length));
		}
		_content[position] = block;
	}


	Block &Line::get(const size_t & position) {
		if (position >= length) {
			throw std::out_of_range(util::OORmessage(position, length));
		}
		return _content[position].value();
	}

	const Block &Line::get(const size_t & position) const {
		if (position >= length) {
			throw std::out_of_range(util::OORmessage(position, length));
		}
		return _content[position].value();
	}


	bool Line::isFull() const {
		return std::ranges::all_of(_content, [](const auto & block) {
			return block.has_value();
		});
	}

    bool Line::isEmpty() const{
		return std::ranges::all_of(_content, [](const auto & block) {
			return !block.has_value();
		});
    }


	void Line::clear() {
		for (auto & block : _content){
			block.reset();
		}
	}

    bool Line::isOccupied(const size_t & position) const {
        return _content[position].has_value();
    }

	Block &Line::operator[](const size_t & position) {
		if (position >= length) {
			throw std::out_of_range(util::OORmessage(position, length));
		}
		return *_content[position];
	}


	const Block &Line::operator[](const size_t & position) const{
		if (position >= length) {
			throw std::out_of_range(util::OORmessage(position, length));
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