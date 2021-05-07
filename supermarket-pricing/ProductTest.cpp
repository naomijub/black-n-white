#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Product.h"
#include "Exceptions.h"

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