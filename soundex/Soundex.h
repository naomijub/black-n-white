#ifndef Soundex_h
#define Soundex_h

#include "string"

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
            return "1";
      }
      return "";
    }
    std::string padWithZeros(const std::string& word) const {
        auto zerosToPad = 4 - word.length();
        return word + std::string(zerosToPad, '0');
    }  
};
#endif