#include "gtest/gtest.h"
#include "Portofolio.h"
#include "PortofolioExceptions.h"
#include "gmock/gmock.h"
#include <string>

using namespace ::testing;

using namespace ::testing;
class APortofolio: public Test {
public:
    Portofolio portofolio;
    static const std::string SHARE;
};
const std::string APortofolio::SHARE("TEST");


TEST_F(APortofolio, IsCreatedEmpty) {
    ASSERT_TRUE(portofolio.isEmpty());
}

TEST_F(APortofolio, NotEmptyAfterPurchase) {
    portofolio.purchase(SHARE, 5);
    ASSERT_FALSE(portofolio.isEmpty());
}

TEST_F(APortofolio, SharesStarteEmpty) {
    ASSERT_EQ(portofolio.shares(SHARE), 0);
}

TEST_F(APortofolio, SharesIncreaseAfterPurchase) {
    portofolio.purchase(SHARE, 5);
    ASSERT_EQ(portofolio.shares(SHARE), 5);
}

TEST_F(APortofolio, ThrowsWhenSharePurchaseIsZero) {
    ASSERT_THROW(portofolio.purchase(SHARE, 0), InvalidShareAmountException);
}

TEST_F(APortofolio, ThrowsWhenInsufficientSharesFOrSell) {
    ASSERT_THROW(portofolio.sell(SHARE, 5), InsufficientSharesException);
}