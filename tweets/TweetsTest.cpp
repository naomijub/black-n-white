#include "gtest/gtest.h"
#include "Tweet.h"
#include "gmock/gmock.h"


TEST(TweetInit, COntainsIDWithMsgAndUser) {
    Tweet tweet("msg", "user");

    ASSERT_EQ(tweet.id(), "msg+user");
}