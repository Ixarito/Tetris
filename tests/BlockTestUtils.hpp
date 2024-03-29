#ifndef TETRIS_BLOCKTESTUTILS_HPP
#define TETRIS_BLOCKTESTUTILS_HPP

#include "Block.h"

namespace tetris::model {

	bool operator==(const Block & lhs, const Block & rhs){
		return lhs.getColor() == rhs.getColor();
	}

	bool operator!=(const Block & lhs, const Block & rhs){
		return !(lhs == rhs);
	}

} // namespace tetris::model


#endif //TETRIS_BLOCKTESTUTILS_HPP
