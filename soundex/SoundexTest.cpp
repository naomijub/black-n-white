#include "string"

class Soundex {
  public:
    std::string enconde(const std::string& word) const {
      return word;
    }    
};

#include "gtest/gtest.h"

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(SoundexEnconding, RetainSoleLetterOfOneLetterWord) {
  Soundex soundex;
  auto encoded = soundex.enconde("A");
  ASSERT_EQ(encoded, "A");
}
