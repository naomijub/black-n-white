#ifndef Soundex_h
#define Soundex_h

#include "string"

class Soundex {
  public:
    std::string enconde(const std::string& word) const {
        auto subsWord = word.substr(0, 1);
        if (word.length() > 1) {
            subsWord += "1";
        }
        return padWithZeros(subsWord);
    }  

  private:
    std::string padWithZeros(const std::string& word) const {
        auto zerosToPad = 4 - word.length();
        return word + std::string(zerosToPad, '0');
    }  
};
#endif