#include "gtest/gtest.h"
#include "Soundex.h"

class SoundexFixture: public testing::Test {
  public:
    Soundex soundex;
};

TEST_F(SoundexFixture, RetainSoleLetterOfOneLetterWord) {
  auto encoded = soundex.enconde("A");
  ASSERT_EQ(encoded, "A000");
}

TEST_F(SoundexFixture, PadWithZerosToEnsureDigits) {
  auto encoded = soundex.enconde("I");
  ASSERT_EQ(encoded, "I000");
}

TEST_F(SoundexFixture, ReplaceConsonantWithCorrespondingDigit) {
  EXPECT_EQ(soundex.enconde("Ab"), "A100");
  EXPECT_EQ(soundex.enconde("Ac"), "A200");
  EXPECT_EQ(soundex.enconde("Ad"), "A300");
}

TEST_F(SoundexFixture, IgnoresNonAlphabetic) {
  ASSERT_EQ(soundex.enconde("A#"), "A000");
}

TEST_F(SoundexFixture, ReplaceMultipleconsonantsWithDigits) {
  ASSERT_EQ(soundex.enconde("Acdl"), "A234");
}

TEST_F(SoundexFixture, LimitLengthTo4Chars) {
  ASSERT_EQ(soundex.enconde("Dcdlb"), "D234");
}

TEST_F(SoundexFixture, IgnoresVowels) {
  ASSERT_EQ(soundex.enconde("Baeiouhycdl"), "B234");
}

TEST_F(SoundexFixture, IgnoreVowelsLikeLetters) {
  ASSERT_EQ(soundex.enconde("BaAeEiIoOuUHyYhcdl"), "B234");
}

TEST_F(SoundexFixture, CombineDuplicates) {
  ASSERT_EQ(soundex.encodeDigit('b'), soundex.encodeDigit('f'));
  ASSERT_EQ(soundex.encodeDigit('c'), soundex.encodeDigit('g'));
  ASSERT_EQ(soundex.encodeDigit('d'), soundex.encodeDigit('t'));
  ASSERT_EQ(soundex.enconde("Abfcgdt"), "A123");
}

TEST_F(SoundexFixture, FirstLetterIsUpperCase) {
  ASSERT_EQ(soundex.enconde("acdl"), "A234");
}