#include "gtest/gtest.h"
#include "RetweetCollection.h"

using namespace ::testing;
class ARetweetCollection: public Test {
public:
    RetweetCollection retweets;
};

TEST_F(ARetweetCollection, HasSizeZeroWhenCreated) {
    ASSERT_EQ(retweets.size(), 0);
}

TEST_F(ARetweetCollection, IsEmptyWhenCreated) {
    ASSERT_TRUE(retweets.isEmpty());
}