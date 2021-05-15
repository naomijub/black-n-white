#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Product.h"
#include "Exceptions.h"

const long UNIT = 1;

TEST(AProduct, ReturnPriceForProductCount) {
    Product test("test", Price(199), ProductType::Unit);
    long count = 4;
    Price actual = test.priceFor(count);
    Price expected(796);

    ASSERT_EQ(actual, expected);
}

TEST(AProduct, ReturnPriceForProductPortion) {
    Product test("test", Price(199), ProductType::Portion);

    Price actual = test.priceFor(0.25);
    Price expected(49);

    ASSERT_EQ(actual, expected);
}

TEST(AProduct, ThrowsForPortionMultipliedByLong) {
    Product test("test", Price(199), ProductType::Portion);
    long count = 4;

    ASSERT_THROW(test.priceFor(count), InvalidMultiplicationArgument);
}

TEST(AProduct, ThrowsForUnitMultipliedByDouble) {
    Product test("test", Price(199), ProductType::Unit);
    double portion = 0.25;

    ASSERT_THROW(test.priceFor(portion), InvalidMultiplicationArgument);
}

TEST(AProduct, ThrowsForDiscountGreaterThan1) {
    Product test("test", Price(199), ProductType::Unit);

    ASSERT_THROW(test.setDiscount(1.01), DiscountGreaterThan1);
}

TEST(AProduct, DiscountForAUnit) {
    Product test("test", Price(100), ProductType::Unit);
    test.setDiscount(0.3);
    auto price = test.priceFor(UNIT);
    auto expected = Price(70);

    ASSERT_EQ(price, expected);
}

TEST(AProduct, DiscountForVariousUnits) {
    Product test("test", Price(100), ProductType::Unit);
    test.setDiscount(0.3);
    auto price = test.priceFor(UNIT * 3);
    auto expected = Price(210);

    ASSERT_EQ(price, expected);
}

TEST(AProduct, DiscountForAPortion) {
    Product test("test", Price(100), ProductType::Portion);
    test.setDiscount(0.3);
    auto price = test.priceFor(4.5);
    auto expected = Price(315);

    ASSERT_EQ(price, expected);
}

TEST(AProduct, ThrowsWhenXLargerThanY) {
    Product test("test", Price(199), ProductType::Unit);

    ASSERT_THROW(test.setPackDiscount(3, 4), DiscountLargerThanValue);
}

TEST(AProduct, PriceIs3For2) {
    Product test("test", Price(100), ProductType::Unit);
    long x = 3;
    long y = 2;
    test.setPackDiscount(x, y);
    Price expected = Price(200);

    ASSERT_EQ(test.priceFor(x), expected);
}

TEST(AProduct, PriceIs3For2WithCount4) {
    Product test("test", Price(100), ProductType::Unit);
    long x = 3;
    long y = 2;
    long count = 4;
    test.setPackDiscount(x, y);
    Price expected = Price(300);

    ASSERT_EQ(test.priceFor(count), expected);
}

TEST(AProduct, PriceIs4For3WithCount6) {
    Product test("test", Price(100), ProductType::Unit);
    long x = 4;
    long y = 3;
    long count = 6;
    test.setPackDiscount(x, y);
    Price expected = Price(500);

    ASSERT_EQ(test.priceFor(count), expected);
}