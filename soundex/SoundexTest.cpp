#include "gtest/gtest.h"
#include "Soundex.h"

class SoundexFixture: public testing::Test {
  public:
    Soundex soundex;
};

TEST_F(SoundexFixture, RetainSoleLetterOfOneLetterWord) {
  Soundex soundex;
  auto encoded = soundex.enconde("A");
  ASSERT_EQ(encoded, "A000");
}

TEST_F(SoundexFixture, PadWithZerosToEnsureDigits) {
  Soundex soundex;
  auto encoded = soundex.enconde("I");
  ASSERT_EQ(encoded, "I000");
}

TEST_F(SoundexFixture, ReplaceConsonantWithCorrespondingDigit) {
  Soundex soundex;
  EXPECT_EQ(soundex.enconde("Ab"), "A100");
  EXPECT_EQ(soundex.enconde("Ac"), "A200");
  EXPECT_EQ(soundex.enconde("Ad"), "A300");
}

TEST_F(SoundexFixture, IgnoresNonAlphabetic) {
  Soundex soundex;
  ASSERT_EQ(soundex.enconde("A#"), "A000");
}

TEST_F(SoundexFixture, ReplaceMultipleconsonantsWithDigits) {
  Soundex soundex;
  ASSERT_EQ(soundex.enconde("Acdl"), "A234");
}