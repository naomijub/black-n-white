#include "gtest/gtest.h"
#include "RetweetCollection.h"
#include "Tweet.h"
#include "gmock/gmock.h"

using namespace ::testing;
class ARetweetCollection: public Test {
public:
    RetweetCollection retweets;
};

MATCHER_P(HashSize, value, "") {
  return arg.size() == value && arg.isEmpty() == (0 == value);
}

TEST_F(ARetweetCollection, HasSizeZeroWhenCreated) {
    ASSERT_EQ(retweets.size(), 0);
}

TEST_F(ARetweetCollection, IsEmptyWhenCreated) {
    ASSERT_TRUE(retweets.isEmpty());
}

TEST_F(ARetweetCollection, IsNotEmptyAfterAddingTweet) {
    Tweet tweet("msg", "user");
    retweets.add(tweet);
    ASSERT_FALSE(retweets.isEmpty());
    ASSERT_THAT(retweets.size(), Gt(0));
}

TEST_F(ARetweetCollection, HashSizeZeroAfterRemove) {
    Tweet tweet("msg", "user");
    retweets.add(tweet);
    retweets.remove(tweet);
    ASSERT_THAT(retweets, HashSize(0));
}

TEST_F(ARetweetCollection, DoesntAcceptDuplicateds) {
    Tweet tweet("msg", "user");
    Tweet duplicated("msg", "user");
    retweets.add(tweet);
    retweets.add(duplicated);
    ASSERT_THAT(retweets, HashSize(1));
}