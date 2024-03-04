#ifndef TETRIS_MODEL_BLOCK_H
#define TETRIS_MODEL_BLOCK_H

#include "Color.h"

namespace tetris::model {

	/**
	 * Represents a block
	 */
	class Block {
        /**
		 * The color fo the block
		 * @sa tetris::model::Color
		 */
        Color color;
    public:
        /**
         * Gives the color of the block
         */
        const Color & getColor() const;

    public:
        /**
		 * Constructs a block
		 * @param color the color of the block
		 */
        explicit Block(Color color);
	};


} // namespace tetris::model

#endif //TETRIS_MODEL_BLOCK_H
