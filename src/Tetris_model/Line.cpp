#include "Line.h"

namespace tetris::model{



        Line::Line(size_t length) : length(length) {}


        void set(size_t position, Block & block){}


        Block & get(size_t position){}


        const Block & Line::get(size_t position){
        }


        bool isFull(){}


        void clear(){}


        Block & operator[](size_t position){}


        const Block & operator[](size_t position){}



        Line::decltype(_content.cbegin()) inline cbegin(){}


        decltype(_content.cend()) inline cend(){}



} // namespace tetris::model

