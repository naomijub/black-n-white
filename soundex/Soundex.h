#ifndef Soundex_h
#define Soundex_h

#include "string"
#include "unordered_map"
#include "algorithm"

static const size_t MAX_CODE_LENGTH{4};

class Soundex {
  public:
    std::string enconde(const std::string& word) const {
        auto headElement = head(word);
        
        return padWithZeros(headElement + encodeDigits(tail(word)));
    }  

  private:
    std::string head(const std::string& word) const {
      return word.substr(0, 1);
    }

    std::string tail(const std::string& word) const {
      return word.substr(1);
    }

    std::string encodeDigits(const std::string& word) const {
      if (word.empty()) return "";
      std::string enconding;
      enconding.resize(word.length());
      std::transform(word.begin(), word.end(), enconding.begin(), encodeDigit);

      return enconding;
    }

    static char encodeDigit(char letter) {
      const std::unordered_map<char, char> encondings {
        {'b', '1'}, {'f', '1'}, {'p', '1'}, {'v', '1'},
        {'c', '2'}, {'g', '2'}, {'j', '2'}, {'k', '2'}, {'q', '2'}, 
          {'s', '2'}, {'x', '2'}, {'z', '2'}, 
        {'d', '3'}, 
        {'l', '4'},
        {'m', '5'}, {'n', '5'}, 
        {'r', '6'},
      };
      
      auto it = encondings.find(letter);
      return it == encondings.end() ? '0' : it->second;
    }

    std::string padWithZeros(const std::string& word) const {
        auto zerosToPad = MAX_CODE_LENGTH - word.length();
        return word + std::string(zerosToPad, '0');
    }  
};

#endif