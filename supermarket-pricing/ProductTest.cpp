#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Product.h"
#include "Exceptions.h"

const long UNIT = 1;

TEST(AProduct, ReturnPriceForProductCount)
{
    Stock s((unsigned long)100);
    Product test("test", Price(199), ProductType::Unit, s);
    long count = 4;
    Price actual = test.priceFor(count);
    Price expected(796);

    ASSERT_EQ(actual, expected);
}

TEST(AProduct, ReturnPriceForProductPortion)
{
    Stock s(100.0);
    Product test("test", Price(199), ProductType::Portion, s);

    Price actual = test.priceFor(0.25);
    Price expected(49);

    ASSERT_EQ(actual, expected);
}

TEST(AProduct, ThrowsForPortionMultipliedByLong)
{
    Stock s(100.0);
    Product test("test", Price(199), ProductType::Portion, s);
    long count = 4;

    ASSERT_THROW(test.priceFor(count), InvalidMultiplicationArgument);
}

TEST(AProduct, ThrowsForUnitMultipliedByDouble)
{
    Stock s((unsigned long)100);
    Product test("test", Price(199), ProductType::Unit, s);
    double portion = 0.25;

    ASSERT_THROW(test.priceFor(portion), InvalidMultiplicationArgument);
}

TEST(AProduct, ThrowsForDiscountGreaterThan1)
{
    Stock s((unsigned long)100);
    Product test("test", Price(199), ProductType::Unit, s);

    ASSERT_THROW(test.setDiscount(1.01), DiscountGreaterThan1);
}

TEST(AProduct, ThrowsForDiscountSmallerThan0)
{
    Stock s((unsigned long)100);
    Product test("test", Price(199), ProductType::Unit, s);

    ASSERT_THROW(test.setDiscount(-0.01), DiscountSmallerThan0);
}

TEST(AProduct, DiscountForAUnit)
{
    Stock s((unsigned long)100);
    Product test("test", Price(100), ProductType::Unit, s);
    test.setDiscount(0.3);
    auto price = test.priceFor(UNIT);
    auto expected = Price(70);

    ASSERT_EQ(price, expected);
}

TEST(AProduct, DiscountForVariousUnits)
{
    Stock s((unsigned long)100);
    Product test("test", Price(100), ProductType::Unit, s);
    test.setDiscount(0.3);
    auto price = test.priceFor(UNIT * 3);
    auto expected = Price(210);

    ASSERT_EQ(price, expected);
}

TEST(AProduct, DiscountForAPortion)
{
    Stock s(100.0);
    Product test("test", Price(100), ProductType::Portion, s);
    test.setDiscount(0.3);
    auto price = test.priceFor(4.5);
    auto expected = Price(315);

    ASSERT_EQ(price, expected);
}

TEST(AProduct, ThrowsWhenXLargerThanY)
{
    Stock s((unsigned long)100);
    Product test("test", Price(199), ProductType::Unit, s);

    ASSERT_THROW(test.setDiscount(3, 4), DiscountLargerThanValue);
}

TEST(AProduct, PriceIs3For2)
{
    Stock s((unsigned long)100);
    Product test("test", Price(100), ProductType::Unit, s);
    long x = 3;
    long y = 2;
    test.setDiscount(x, y);
    Price expected = Price(200);

    ASSERT_EQ(test.priceFor(x), expected);
}

TEST(AProduct, PriceIs3For2WithCount4)
{
    Stock s((unsigned long)100);
    Product test("test", Price(100), ProductType::Unit, s);
    long x = 3;
    long y = 2;
    long count = 4;
    test.setDiscount(x, y);
    Price expected = Price(300);

    ASSERT_EQ(test.priceFor(count), expected);
}

TEST(AProduct, PriceIs4For3WithCount6)
{
    Stock s((unsigned long)100);
    Product test("test", Price(100), ProductType::Unit, s);
    long x = 4;
    long y = 3;
    long count = 6;
    test.setDiscount(x, y);
    Price expected = Price(500);

    ASSERT_EQ(test.priceFor(count), expected);
}