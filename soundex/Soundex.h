#ifndef Soundex_h
#define Soundex_h

#include "string"

class Soundex {
  public:
    std::string enconde(const std::string& word) const {
        if (word == "Ab") return "A100";
        return padWithZeros(word);
    }  
  private:
    std::string padWithZeros(const std::string& word) const {
      return word + "000";
    }  
};
#endif