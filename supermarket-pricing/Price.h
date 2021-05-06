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

Price operator*(const Price& lhs, long rhs) {
    return Price(lhs.amount * rhs);
}

Price operator/(Price& lhs, long rhs) {
    long remainder = lhs.amount % rhs;
    double round = (double) remainder / (double) rhs;

    if (round >= 0.5) {
        return lhs.divUp(rhs);
    } else {
        return lhs.divDown(rhs);
    }
}

Price operator*(const Price& lhs, double rhs) {
    double amount = rhs * (double) lhs.amount;
    return Price(amount);
}

Price operator+(const Price& lhs, const Price&  rhs) {
    return Price(lhs.amount + rhs.amount);
}

void operator*=(Price& lhs, long rhs) {
    lhs.amount = lhs.amount * rhs;
}

void operator*=(Price& lhs, double rhs) {
    double amount = rhs * (double) lhs.amount;
    lhs.amount = amount;
}

void operator+=(Price& lhs, const Price&  rhs) {
    lhs.amount = lhs.amount + rhs.amount;
}

bool operator==(const Price& lhs, const Price& rhs) {
    return lhs.amount == rhs.amount;
}

#endif