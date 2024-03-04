#include "Block.h"

namespace tetris::model {

    Block::Block(Color color) : color{color} {}

    const Color & Block::getColor() const {
        return color;
    }

} // namespace tetris::model
