#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Price.h"
#include <vector>

TEST(PriceValue, SimpleAmount) {
    Price price = Price(100);

    ASSERT_EQ(price.amount, 100); 
}

TEST(PriceValue, SimpleAmountDoubleConvertedToPrice) {
    // Decided to truc value under 2 decimals.
    double doubleValue = 1.4567;
    Price price = Price::fromDouble(doubleValue);

    ASSERT_EQ(price.amount, 145); 
}

TEST(PriceValue, PriceMultiplication) {
    Price price = Price(123);
    long mul = 11;
    Price expected = Price(1353);

    ASSERT_EQ(price * mul, expected); 
}

TEST(PriceValue, PriceAssignMultiplication) {
    Price price = Price(123);
    long mul = 11;
    Price expected = Price(1353);

    price *= mul;

    ASSERT_EQ(price.amount, expected.amount); 
}

TEST(PriceValue, PriceAdd) {
    Price price = Price(123);
    Price add_price = Price(321);
    Price expected = Price(444);

    ASSERT_EQ(price + add_price, expected); 
}

TEST(PriceValue, PriceAssingAdd) {
    Price price = Price(123);
    Price add_price = Price(321);
    Price expected = Price(444);

    price += add_price;

    ASSERT_EQ(price, expected); 
}

TEST(PriceValue, PriceMultiplicationByDouble) {
    Price price = Price(123);
    double mul = 0.75;
    Price expected = Price(92);

    ASSERT_EQ(price * mul, expected); 
}

TEST(PriceValue, PriceAssignMultiplicationByDouble) {
    Price price = Price(123);
    double mul = 0.75;
    Price expected = Price(92);

    price *= mul;

    ASSERT_EQ(price, expected); 
}

TEST(PriceValue, PriceDivisionUp) {
    Price price = Price(123);
    Price expected = Price(18);

    Price actual = price.divUp(7);

    ASSERT_EQ(actual, expected); 
}

TEST(PriceValue, PriceDivisionDown) {
    Price price = Price(123);
    Price expected = Price(17);

    Price actual = price.divDown(7);

    ASSERT_EQ(actual, expected); 
}

TEST(PriceValue, PriceAutomaticDivDown) {
    Price price = Price(123);
    long div = 8;
    Price expected = Price(15);

    ASSERT_EQ(price / div, expected); 
}

TEST(PriceValue, PriceAutomaticDivUp) {
    Price price = Price(123);
    long div = 7;
    Price expected = Price(18);

    ASSERT_EQ(price / div, expected); 
}

TEST(PriceValue, DividePriceInShares) {
    Price price = Price(101);
    long div = 3;

    std::vector<Price> expected({Price(34), Price(34), Price(33)});

    ASSERT_EQ(price.sharesDivBy(div), expected);
}