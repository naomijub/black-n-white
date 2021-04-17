#include "gtest/gtest.h"

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(MyDeathTest, TestOne) {
  ASSERT_EQ(1, 1);
}
