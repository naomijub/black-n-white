#include "gtest/gtest.h"
#include "RetweetCollection.h"
#include "Tweet.h"

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

TEST_F(ARetweetCollection, IsNotEmptyAfterAddingTweet) {
    retweets.add(Tweet());
    ASSERT_FALSE(retweets.isEmpty());
}

TEST_F(ARetweetCollection, SizeIncreasesAfterAdd) {
    retweets.add(Tweet());
    ASSERT_EQ(retweets.size(), 1);
}