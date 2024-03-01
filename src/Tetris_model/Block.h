#ifndef TETRIS_MODEL_BLOCK_H
#define TETRIS_MODEL_BLOCK_H

#include "Color.h"

namespace tetris::model {

	/**
	 * Represents a block
	 */
	class Block {
	public:
		/**
		 * The color fo the block
		 * @sa tetris::model::Color
		 */
		const Color color;

		/**
		 * Constructs a block
		 * @param color the color of the block
		 */
		inline explicit Block(Color color);
	};

	Block::Block(Color color) : color{color} {}

} // namespace tetris::model

#endif //TETRIS_MODEL_BLOCK_H
