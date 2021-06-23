#ifndef Exceptions_h
#define Exceptions_h

#include <string>

class InvalidMultiplicationArgument
{
private:
    std::string message_;

public:
    InvalidMultiplicationArgument(std::string message) : message_(message) {}
};

class DiscountGreaterThan1
{
};
class DiscountLargerThanValue
{
};
class DiscountSmallerThan0
{
};

#endif