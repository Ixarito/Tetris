#ifndef TETRIS_MODEL_MAXVECTORSIZE_HPP
#define TETRIS_MODEL_MAXVECTORSIZE_HPP

#include <vector>

namespace tetris::util {

	/**
	 * Gisves the maximum size of a vector of vector
	 * @tparam T any type
	 * @param matrix the 2d vector to examine
	 * @return the maximum size of a vector in the given matrix
	 */
	template<typename T>
	int maxVectorSize(const std::vector<std::vector<T>> & matrix) {
		if (matrix.empty()) return 0;

		auto maxSize = matrix.size();

		for (const auto &line: matrix) {
			auto lineSize{line.size()};
			if (lineSize > maxSize) {
				maxSize = lineSize;
			}
		}

		return maxSize;
	}

} // namespace tetris::util

#endif //TETRIS_MODEL_MAXVECTORSIZE_HPP
