#include "gtest/gtest.h"
#include "Bag.h"

using tetris::model::Bag;

TEST(bag, bagIsSingleton){
	Bag & b1 {Bag::getInstance()};
	Bag & b2 {Bag::getInstance()};
	Bag & b3 {Bag::getInstance()};

	ASSERT_EQ(&b1, &b2);
	ASSERT_EQ(&b1, &b3);
}

TEST(bag, peekNextAlwaysReturnSameAsNext){
	Bag & b {Bag::getInstance()};

}