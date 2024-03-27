#include "Line.h"

namespace tetris::model {


    Line::Line(size_t length) : _content(), length(length) {}


    void Line::set(size_t position, Block &block) {
        if (position >= this->length) {
            throw "invalid position";
        }
        this->_content[position] = block;
    }


    Block &Line::get(size_t position) {
        if (position >= this->length) {
            throw "invalid position";
        }
        return this->_content[position].value();
    }

    const Block &Line::get(size_t position) const {
        if (position >= this->length) {
            throw "invalid position";
        }
        return this->_content[position].value();
    }


    bool Line::isFull() const {
        for (std::optional<Block> block: this->_content) {
            if (!block.has_value()) {
                return false;
            }
            return true;
        }
    }


    void Line::clear() {
        for (std::optional<Block> block : this->_content){
            block.reset();
        }
    }


    Block &Line::operator[](size_t position) {
        if (position >= this->length) {
            throw "invalid position";
        }
        return _content[position].value();
    }


    const Block &Line::operator[](size_t position) const{
        if (position >= this->length) {
            throw "invalid position";
        }
        return _content[position].value();
    }


    std::vector<std::optional<Block>>::const_iterator inline Line::cbegin() const{
        return _content.cbegin();
    }


    std::vector<std::optional<Block>>::const_iterator inline Line::cend() const{
        return _content.cend();
    }


} // namespace tetris::model