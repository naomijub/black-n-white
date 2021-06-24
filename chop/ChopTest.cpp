#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Chop.h"
#include <vector>

TEST(AChop, TestData)
{
    ASSERT_EQ(-1, chop(3, std::vector<int>{}));
    ASSERT_EQ(-1, chop(3, std::vector<int>{1}));
    ASSERT_EQ(0, chop(1, std::vector<int>{1}));

    ASSERT_EQ(0, chop(1, std::vector<int>{1, 3, 5}));
    ASSERT_EQ(1, chop(3, std::vector<int>{1, 3, 5}));
    ASSERT_EQ(2, chop(5, std::vector<int>{1, 3, 5}));
    ASSERT_EQ(-1, chop(0, std::vector<int>{1, 3, 5}));
    ASSERT_EQ(-1, chop(2, std::vector<int>{1, 3, 5}));
    ASSERT_EQ(-1, chop(4, std::vector<int>{1, 3, 5}));
    ASSERT_EQ(-1, chop(6, std::vector<int>{1, 3, 5}));
    ASSERT_EQ(0, chop(1, std::vector<int>{1, 3, 5, 7}));
    ASSERT_EQ(1, chop(3, std::vector<int>{1, 3, 5, 7}));
    ASSERT_EQ(2, chop(5, std::vector<int>{1, 3, 5, 7}));
    ASSERT_EQ(3, chop(7, std::vector<int>{1, 3, 5, 7}));
    ASSERT_EQ(-1, chop(0, std::vector<int>{1, 3, 5, 7}));
    ASSERT_EQ(-1, chop(2, std::vector<int>{1, 3, 5, 7}));
    ASSERT_EQ(-1, chop(4, std::vector<int>{1, 3, 5, 7}));
    ASSERT_EQ(-1, chop(6, std::vector<int>{1, 3, 5, 7}));
    ASSERT_EQ(-1, chop(8, std::vector<int>{1, 3, 5, 7}));
}