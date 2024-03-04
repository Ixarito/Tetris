
#include "Tetromino.h"
namespace tetris::model {

    Tetromino::Tetromino(Shape_type &shape, Color color) : _shape(shape.size(), std::vector<std::optional<Block>>(shape[0].size())) {
        for (size_t i = 0; i < shape.size(); ++i) {
            for (size_t j = 0; j < shape[i].size(); ++j) {
                if (shape[i][j]) {
                    _shape[i][j] = Block(color);
                }
            }
        }
    }

    Tetromino::Tetromino(ConstructorComponents_type ctorCmpnts) {
    }


    Block get(size_t x, size_t y) {
    }


    bool isOccupied(size_t x, size_t y) {
    }


    void rotate(RotateDirection direction) {
    }


    size_t getWidth() {
    }


    size_t getHeight() {
    }


} // namespace tetris::model

