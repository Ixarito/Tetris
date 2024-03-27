#include "Line.h"

namespace tetris::model{



    Line::Line(size_t length) : _content(length)  length(length) {}


        void Line::set(size_t position, Block & block){
            if (position >= this->length) {
                throw "invalid position";
            }
            this->_content[position] = block;
        }


        Block & Line::get(size_t position){
            if (position >= this->length) {
                throw "invalid position";
            }
            return this->_content[position];
        }

        const Block & Line::get(size_t position) const {
            if (position >= this->length) {
                throw "invalid position";
            }
            return this->_content[position];
        }


        bool Line::isFull() const{
            for(Block block : this->_content){

            }
        }


        void Line::clear(){}


        Block & Line::operator[](size_t position){}


        const Block & Line::operator[](size_t position){}



        Line::decltype(_content.cbegin()) inline Line::cbegin(){}


        decltype(_content.cend()) inline Line::cend(){}



} // namespace tetris::model