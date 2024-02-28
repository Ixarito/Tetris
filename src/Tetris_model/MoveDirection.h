#ifndef TETRIS_MODEL_MOVEDIRECTION_H
#define TETRIS_MODEL_MOVEDIRECTION_H

namespace tetris::model {

    /**
     * Represents a direction of a movement in the Tetris game
     */
    enum class MoveDirection : char{
        LEFT, RIGHT, DOWN
    };

} // namespace tetris::model

#endif //TETRIS_MODEL_MOVEDIRECTION_H
