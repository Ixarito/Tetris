#include <stdexcept>
#include "Grid.h"
#include "util/outOfRangeMessage.hpp"
#include "util//random.hpp"

#define PERCENT_RANDOM_BLOCK 75

namespace tetris::model {

    Grid::Grid(const size_t &width, const size_t &height, const int &nbAlreadyPlacedBlock) :
            _lines{}, width{width}, height{height} {
        for (size_t i{0}; i < height; i++) {
            _lines.push_back(new Line(width));
        }

        if (nbAlreadyPlacedBlock) {
            dev3::randomize();
            auto colorEnumSize = static_cast<char>(Color::_count_);
            int nbPlacedBlock{};

            for (size_t i{_lines.size()}; i-- && nbPlacedBlock < nbAlreadyPlacedBlock;) {
                for (size_t j{}; j < _lines[i]->length && nbPlacedBlock < nbAlreadyPlacedBlock; j++) {
                    if (dev3::random_value(0, 100) < PERCENT_RANDOM_BLOCK) {
                        _lines[i]->set(j, static_cast<Block>(static_cast<Color>(dev3::random_value(0, colorEnumSize))));
                        nbPlacedBlock++;
                    }
                }
                if (_lines[i]->isEmpty()) i++; // retry to fill the line if still empty
            }
        }
    }

    Grid::~Grid() {
        for (auto lp: _lines) {
            delete lp;
            lp = nullptr;
        }
    }

    const Block &Grid::get(const size_t & row, const size_t & col) const {
        if (row >= height) {
            throw std::out_of_range(util::OORmessage(row, height));
        }
        return (*_lines[row])[col];
    }

	void Grid::insert(const Tetromino & tetromino, const size_t & row, const size_t & col) {
		auto tetroWidth{tetromino.getWidth()};
		auto tetroHeight{tetromino.getHeight()};

		for (size_t x = 0; x < tetroWidth; x++) {
			for (size_t y = 0; y < tetroHeight; y++) {
				if (tetromino.isOccupied(x, y)) {
					_lines[row + y]->set(col + x, tetromino.get(x, y));
				}
			}
		}
	}


    std::vector<size_t> Grid::getFullLines() {
        std::vector<size_t> fullLines;
        for (size_t i = 0; i < height; i++) {
            if (_lines[i]->isFull()) {
                fullLines.push_back(i);
            }
        }
        return fullLines;
    }

    void Grid::removeLine(const size_t &position) {
        if (position >= height) {
            throw std::out_of_range(util::OORmessage(position, height));
        }

        // remove line from the deque
        auto it = _lines.begin() + position;
        Line *target = *it;
        _lines.erase(it);

        // clear line and reinsert in top of the grid
        target->clear();
        _lines.push_front(target);
    }

    size_t Grid::removeFullLines() {
        auto lines{getFullLines()};
        for (auto line: lines) {
            removeLine(line);
        }
        return lines.size();
    }


    const Line &Grid::operator[](const size_t &position) const {
        if (position >= height) {
            throw std::out_of_range(util::OORmessage(position, height));
        }
        return *_lines[position];
    }

    auto Grid::begin() const -> decltype(_lines.begin()) {
        return _lines.begin();
    }

    auto Grid::cbegin() const -> decltype(_lines.cbegin()) {
        return _lines.cbegin();
    }

    auto Grid::end() const -> decltype(_lines.end()) {
        return _lines.end();
    }

    auto Grid::cend() const -> decltype(_lines.cend()) {
        return _lines.cend();
    }

} // namespace tetris::model