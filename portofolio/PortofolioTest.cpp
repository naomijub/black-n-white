#include "gtest/gtest.h"
#include "Portofolio.h"
#include "PortofolioExceptions.h"
#include "gmock/gmock.h"
#include <string>
#include <chrono>

using namespace ::testing;

using namespace ::testing;
class APortofolio: public Test {
public:
    Portofolio portofolio;
    static const std::string SHARE;
    static const std::string OTHER_SHARE;
};
const std::string APortofolio::SHARE("TEST");
const std::string APortofolio::OTHER_SHARE("OTHER");


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

TEST_F(APortofolio, ThrowsWhenInsufficientSharesForSell) {
    ASSERT_THROW(portofolio.sell(SHARE, 5), InsufficientSharesException);
}

TEST_F(APortofolio, ThrowsWhenInsufficientSharesForSellWithDifferentShare) {
    portofolio.purchase(OTHER_SHARE, 10);
    ASSERT_THROW(portofolio.sell(SHARE, 5), InsufficientSharesException);
}

TEST_F(APortofolio, HasAListOfPurchases) {
    portofolio.purchase(SHARE, 10);
    auto record = portofolio.purchases(SHARE)[0];

    ASSERT_EQ(record.ShareCount, 10);
    ASSERT_LE(record.Date, std::chrono::system_clock::now());
}

TEST_F(APortofolio, SellingReducesSharesCount) {
    portofolio.purchase(SHARE, 10);
    portofolio.sell(SHARE, 4);
    ASSERT_EQ(portofolio.shares(SHARE), 6);

    auto record = portofolio.purchases(SHARE)[1];
    ASSERT_EQ(record.ShareCount, -4);
}