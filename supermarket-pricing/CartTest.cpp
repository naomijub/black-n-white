#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Cart.h"
#include <string>
#include "Exceptions.h"

TEST(ACart, CheckPriceForMeatPortion)
{
    std::string meat("meat");
    Cart *cart = new Cart();
    Item item_price = cart->check_price(meat, 30.0);
    ASSERT_TRUE(item_price.available);
    ASSERT_EQ(item_price.stock.portion, 120.0);
    ASSERT_EQ(item_price.price.amount, 44970);
}

TEST(ACart, CheckPriceForMilUnits)
{
    std::string milk("milk");
    Cart *cart = new Cart();
    Item item_price = cart->check_price(milk, (long)5);
    ASSERT_TRUE(item_price.available);
    ASSERT_EQ(item_price.stock.count, 50);
    ASSERT_EQ(item_price.price.amount, 1495);
}

TEST(ACart, CheckPriceForMoreMeatThanYouCanBuy)
{
    std::string meat("meat");
    Cart *cart = new Cart();
    Item item_price = cart->check_price(meat, 300.0);
    ASSERT_FALSE(item_price.available);
    ASSERT_EQ(item_price.stock.portion, 120.0);
    ASSERT_EQ(item_price.price.amount, 0);
}

TEST(ACart, CheckPriceForMoreMilkThanYouCanBuy)
{
    std::string milk("milk");
    Cart *cart = new Cart();
    Item item_price = cart->check_price(milk, (long)300);
    ASSERT_FALSE(item_price.available);
    ASSERT_EQ(item_price.stock.count, 50);
    ASSERT_EQ(item_price.price.amount, 0);
}

TEST(ACart, CheckPriceForSomethingElse)
{
    std::string milk("candy");
    Cart *cart = new Cart();
    Item item_price = cart->check_price(milk, (long)300);
    ASSERT_FALSE(item_price.available);
    ASSERT_EQ(item_price.stock.count, 0);
    ASSERT_EQ(item_price.price.amount, 0);
}

TEST(ACart, ThrowsForPortionOfMilk)
{
    std::string milk("milk");
    Cart *cart = new Cart();

    ASSERT_THROW(cart->check_price(milk, 5.0);, InvalidMultiplicationArgument);
}

TEST(ACart, ThrowsForUnitsOfMeat)
{
    std::string meat("meat");
    Cart *cart = new Cart();

    ASSERT_THROW(cart->check_price(meat, (long)5);, InvalidMultiplicationArgument);
}