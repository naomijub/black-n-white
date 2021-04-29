#ifndef Soundex_h
#define Soundex_h

#include "string"
#include "unordered_map"

static const size_t MAX_CODE_LENGTH{4};
const std::string NOT_A_DIGIT{"*"};
const std::string EMPTY_STR{""};

class Soundex {
  public:
    std::string enconde(const std::string& word) const {
        auto headElement = toUpper(head(word));
        
        return padWithZeros(headElement + encodeDigits(tail(word)));
    }

    std::string encodeDigit(char letter) const {
      const std::unordered_map<char, std::string> encondings {
        {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
        {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"}, 
          {'s', "2"}, {'x', "2"}, {'z', "2"}, 
        {'d', "3"}, {'t', "3"},
        {'l', "4"},
        {'m', "5"}, {'n', "5"}, 
        {'r', "6"},
      };
      auto it = encondings.find(toLower(letter));
      return it == encondings.end() ? NOT_A_DIGIT : it->second;
    }

  private:
    std::string head(const std::string& word) const {
      return word.substr(0, 1);
    }

    std::string toUpper(const std::string& s) const {
      return std::string(1, std::toupper(static_cast<unsigned char>(s.front())));
    }

    char toLower(char ch) const {
      return std::tolower(static_cast<unsigned char>(ch));
    }

    std::string tail(const std::string& word) const {
      return word.substr(1);
    }

    std::string encodeDigits(const std::string& word) const {
      if (word.empty()) return EMPTY_STR;
      std::string enconding;
      for (auto letter: word) {
        if (isCompleted(enconding)) break;
        auto digit = encodeDigit(letter);
        if (digit != NOT_A_DIGIT && digit != lastDigit(enconding))
          enconding += encodeDigit(letter);
      }
      return enconding;
    }

    std::string padWithZeros(const std::string& word) const {
        auto zerosToPad = MAX_CODE_LENGTH - word.length();
        return word + std::string(zerosToPad, '0');
    }
    
    bool isCompleted(const std::string& encoding) const {
      return encoding.length() == MAX_CODE_LENGTH - 1;
    }

    std::string lastDigit(const std::string& encoding) const {
      if (encoding.empty()) return NOT_A_DIGIT;
      return std::string(1, encoding.back());
    }
};

#endif