#include "gtest/gtest.h"
#include "Line.h"

using namespace tetris::model;


TEST(Line, BasicImplementationTest){
	Line l {5};

	Block b1 {Color::RED};
	Block b2 {Color::BLUE};

	ASSERT_NO_THROW({
		l.set(0, b1);
	});
	ASSERT_NO_THROW({
		l.set(0, b2);
	});
	ASSERT_NO_THROW({
		l[1] = b2;
	});
	ASSERT_NO_THROW({
		for(const auto & b: l){
			std::cout << &b << std::endl;
		}
	});
}