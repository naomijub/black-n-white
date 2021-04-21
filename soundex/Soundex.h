#ifndef Soundex_h
#define Soundex_h

#include "string"
#include "unordered_map"

static const size_t MAX_CODE_LENGTH{4};

class Soundex {
  public:
    std::string enconde(const std::string& word) const {
        auto headElement = head(word);
        
        return padWithZeros(headElement + encodeDigits(word));
    }  

  private:
    std::string head(const std::string& word) const {
      return word.substr(0, 1);
    }

    std::string encodeDigits(const std::string& word) const {
      if (word.length() > 1) {
            return encodeDigit(word[1]);
      }
      return "";
    }

    std::string encodeDigit(char letter) const {
      const std::unordered_map<char, std::string> encondings {
        {'b', "1"},
        {'c', "2"},
        {'d', "3"},
      };
      return encondings.find(letter)->second;
    }

    std::string padWithZeros(const std::string& word) const {
        auto zerosToPad = MAX_CODE_LENGTH - word.length();
        return word + std::string(zerosToPad, '0');
    }  
};
#endif