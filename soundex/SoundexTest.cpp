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
  auto encoded = soundex.enconde("Ab");
  ASSERT_EQ(encoded, "A100");
}
