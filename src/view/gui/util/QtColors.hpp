#ifndef QTCOLORS_HPP
#define QTCOLORS_HPP

#include <QColor>
#include "Color.h"

inline QColor getQtColor(tetris::model::Color color) {
	switch (color) {
		case tetris::model::Color::BLUE:
			return {Qt::blue};
		case tetris::model::Color::GREEN:
			return {Qt::green};
		case tetris::model::Color::YELLOW:
			return {Qt::yellow};
		case tetris::model::Color::ORANGE:
			return {255, 165, 0};
		case tetris::model::Color::RED:
			return {Qt::red};
		case tetris::model::Color::CYAN:
			return {Qt::cyan};
		case tetris::model::Color::PURPLE:
			return {128, 0, 128};

		case tetris::model::Color::_count_:
			throw std::domain_error("Cannot use _count_ literal");
	}

	throw std::domain_error("Unknown Color used");
}

#endif //QTCOLORS_HPP
