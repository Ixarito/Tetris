#ifndef TETRIS_OUTOFRANGEMESSAGE_HPP
#define TETRIS_OUTOFRANGEMESSAGE_HPP

#include <sstream>

namespace tetris::util {

	/**
	 * Gives a message to throw with an out_of_range exception
	 * @param index the index out of range
	 * @param length the length of the container
	 * @return a string of the form "index [index] out of range for length [length]"
	 * @sa std::out_of_range
	 */
	std::string OORmessage(const auto & index, const auto & length){
		std::stringstream ss;
		ss << "index " << index << " out of range for length " << length;
		return ss.str();
	}

} // namespace tetris::util

#endif //TETRIS_OUTOFRANGEMESSAGE_HPP
