#include "gtest/gtest.h"

int main(int argc, char* argv[]){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(Tetris, ExampleTest) {
	ASSERT_EQ(1,1);
}

TEST(Tetris, ExampleTestFailed) {
	ASSERT_EQ(1,1);
	EXPECT_EQ(2,3);
	ASSERT_FALSE(false);
}
