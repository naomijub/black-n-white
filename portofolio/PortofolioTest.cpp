#include "gtest/gtest.h"
#include "Portofolio.h"
#include "gmock/gmock.h"

using namespace ::testing;

using namespace ::testing;
class APortofolio: public Test {
public:
    Portofolio portofolio;
};

TEST_F(APortofolio, IsCreatedEmpty) {
    ASSERT_TRUE(portofolio.isEmpty());
}

TEST_F(APortofolio, NotEmptyAfterPurchase) {
    portofolio.purchase("TEST", 5);
    ASSERT_FALSE(portofolio.isEmpty());
}

TEST_F(APortofolio, SharesStarteEmpty) {
    ASSERT_EQ(portofolio.shares("TEST"), 0);
}

TEST_F(APortofolio, SharesIncreaseAfterPurchase) {
    portofolio.purchase("TEST", 5);
    ASSERT_EQ(portofolio.shares("TEST"), 5);
}