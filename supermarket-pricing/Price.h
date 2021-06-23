#ifndef Price_h
#define Price_h

#include <vector>

struct Price
{
    long amount;

    Price(long value) : amount(value){};

public:
    static Price fromDouble(double value)
    {
        Price price = Price(0);
        price.amount = (long)100 * value;
        return price;
    }

    Price divUp(long divider);
    Price divDown(long divider);
    std::vector<Price> sharesDivBy(long divider);
};

Price operator*(const Price &lhs, long rhs);
Price operator/(Price &lhs, long rhs);
Price operator*(const Price &lhs, double rhs);
Price operator+(const Price &lhs, const Price &rhs);
void operator*=(Price &lhs, long rhs);
void operator*=(Price &lhs, double rhs);
void operator+=(Price &lhs, const Price &rhs);
bool operator==(const Price &lhs, const Price &rhs);

#endif