#include "gtest/gtest.h"
#include "Portofolio.h"
#include "PortofolioExceptions.h"
#include "gmock/gmock.h"
#include <string>
#include <chrono>
#include <vector>

using namespace ::testing;

using namespace ::testing;
class APortofolio: public Test {
public:
    Portofolio portofolio;
    static const std::string SHARE;
    static const std::string OTHER_SHARE;
    std::chrono::time_point<std::chrono::system_clock> now;
    
    void SetUp() override {
        now = std::chrono::system_clock::now();
    }

    void PurchareseShare(int shares) {
        portofolio.purchase(SHARE, shares, now);
    }
};
const std::string APortofolio::SHARE("TEST");
const std::string APortofolio::OTHER_SHARE("OTHER");


TEST_F(APortofolio, IsCreatedEmpty) {
    ASSERT_TRUE(portofolio.isEmpty());
}

TEST_F(APortofolio, NotEmptyAfterPurchase) {
    PurchareseShare(5);
    ASSERT_FALSE(portofolio.isEmpty());
}

TEST_F(APortofolio, SharesStarteEmpty) {
    ASSERT_EQ(portofolio.shares(SHARE), 0);
}

TEST_F(APortofolio, SharesIncreaseAfterPurchase) {
    PurchareseShare(5);
    ASSERT_EQ(portofolio.shares(SHARE), 5);
}

TEST_F(APortofolio, ThrowsWhenSharePurchaseIsZero) {
    ASSERT_THROW(portofolio.purchase(SHARE, 0, now), InvalidShareAmountException);
}

TEST_F(APortofolio, ThrowsWhenInsufficientSharesForSell) {
    ASSERT_THROW(portofolio.sell(SHARE, 5, now), InsufficientSharesException);
}

TEST_F(APortofolio, ThrowsWhenInsufficientSharesForSellWithDifferentShare) {
    portofolio.purchase(OTHER_SHARE, 10, now);
    ASSERT_THROW(portofolio.sell(SHARE, 5, now), InsufficientSharesException);
}

TEST_F(APortofolio, HasAListOfPurchases) {
    PurchareseShare(10);
    auto record = portofolio.purchases(SHARE)[0];

    ASSERT_EQ(record.ShareCount, 10);
    ASSERT_EQ(record.Date, now);
}

TEST_F(APortofolio, SellingReducesSharesCount) {
    PurchareseShare(10);
    portofolio.sell(SHARE, 4, now);
    ASSERT_EQ(portofolio.shares(SHARE), 10 - 4);

    auto record = portofolio.purchases(SHARE)[1];
    ASSERT_EQ(record.ShareCount, -4);
}

bool operator==(const PurchaseRecord& lhs, const PurchaseRecord& rhs) {
    return lhs.ShareCount == rhs.ShareCount && lhs.Date == rhs.Date;
}

TEST_F(APortofolio, PurchasesOnlyReturnValueForShare) {
    PurchareseShare(10);
    portofolio.purchase(OTHER_SHARE, 11, now);
    PurchareseShare(6);

    auto record = portofolio.purchases(SHARE);
    std::vector<PurchaseRecord> expected({PurchaseRecord({10, now}), PurchaseRecord({6, now})});
    ASSERT_EQ(record, expected);
}