#include <iostream>
#include "Tetromino.h"
#include "Block.h"

int main() {
    tetris::model::Tetromino::Shape_type shape = {
            {true, false, true, false},
            {false, false, true, false},
            {false, true, true, false},
            {false, false, true, false}
    };

    tetris::model::Tetromino t(shape, tetris::model::Color::RED);
    std::cout << "Tetromino created" << std::endl;
    t.print();
    std::cout << "\nRotating CCW" << std::endl;
    t.rotate(tetris::model::RotateDirection::CCW);
    t.print();
    std::cout << "\nRotating CW" << std::endl;
    t.rotate(tetris::model::RotateDirection::CW);
    t.print();


    std::cout << "\nHeight: " << t.getHeight() << std::endl;
    std::cout << "Width: " << t.getWidth() << std::endl;


    return 0;
}