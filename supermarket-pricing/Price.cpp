#include "Price.h"

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