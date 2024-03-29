#include "gtest/gtest.h"
#include "Bag.h"

#include "TetrominoTestUtils.hpp"

using namespace tetris::model;


TEST(bag, bagIsSingleton){
	Bag & b1 {Bag::getInstance()};
	Bag & b2 {Bag::getInstance()};
	Bag & b3 {Bag::getInstance()};

	ASSERT_EQ(&b1, &b2);
	ASSERT_EQ(&b1, &b3);
}

TEST(bag, peekNextAlwaysReturnSameAsNext){
	Bag & b {Bag::getInstance()};
	b.add({{{true, true, false}, {true, false, false}, {true, false, false}}, Color::BLUE});
	b.add({{{false, true, false}, {false, true, false}, {false, true, false}}, Color::RED});
	b.add({{{false, true, true}, {false, true, true}, {false, true, true}}, Color::GREEN});
	b.add({{{false, true, false}, {true, true, false}, {true, false, false}}, Color::YELLOW});

	for (int i = 0; i < 50; ++i) {
//		std::cout << "loop " << i << std::endl;

		auto peek {b.peekNext()};
		std::cout << static_cast<int>(peek.get(0,1).getColor());

		ASSERT_EQ(peek, b.getNext());
	}

	std::cout << std::endl;
}