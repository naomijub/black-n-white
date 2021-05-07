#ifndef Price_h
#define Price_h

#include <vector>

struct Price {
    long amount;

    Price(long value) : amount(value) {};
    
    public: 
        static Price fromDouble(double value) {
            Price price = Price(0);
            price.amount = (long) 100 * value;
            return price;
        }

        Price divUp(long divider) {
            long value = amount / divider;
            if (amount % divider > 0) {
                value++;
            }
            return Price(value);
        }

        Price divDown(long divider) {
            long value = amount / divider;
            return Price(value);
        }

        std::vector<Price> sharesDivBy(long divider) {
            long remaider = amount % divider;
            long division = amount / divider;
            std::vector<Price> shares;

            for(int i = 0; i < divider; i++) {
                if (remaider > 0) {
                    remaider--;
                    shares.push_back(Price(division + 1));
                } else {
                    shares.push_back(Price(division));
                }
            }

            return shares;
        }
};


Price operator*(const Price& lhs, long rhs);
Price operator/(Price& lhs, long rhs);
Price operator*(const Price& lhs, double rhs);
Price operator+(const Price& lhs, const Price&  rhs);
void operator*=(Price& lhs, long rhs);
void operator*=(Price& lhs, double rhs);
void operator+=(Price& lhs, const Price&  rhs);
bool operator==(const Price& lhs, const Price& rhs);

#endif