#include "Product.h"

Price Product::priceFor(long count)
{
    if (value_ != ProductType::Unit)
    {
        throw InvalidMultiplicationArgument("ProductType::Portion should be multiplied by double");
    }
    (void)name_;

    if (discount_ > 0.0)
    {
        return (price_ * discount_) * count;
    }
    if (isXEqY())
    {
        return priceForXForY(count);
    }

    return price_ * count;
}

Price Product::priceFor(double portion)
{
    if (value_ != ProductType::Portion)
    {
        throw InvalidMultiplicationArgument("ProductType::Unit should be multiplied by long");
    }
    (void)name_;
    if (discount_ > 0.0)
    {
        return (price_ * discount_) * portion;
    }

    return price_ * portion;
}

void Product::setDiscount(double discount)
{
    if (discount > 1.0)
    {
        throw DiscountGreaterThan1();
    }
    if (discount < 0.0)
    {
        throw DiscountSmallerThan0();
    }
    discount_ = (1.0 - discount);
    xForY = std::make_tuple(0, 0);
}

void Product::setDiscount(long x, long y)
{
    if (y >= x)
    {
        throw DiscountLargerThanValue();
    }
    discount_ = 0.0;
    xForY = std::make_tuple(x, y);
}

bool Product::isXEqY()
{
    return std::get<0>(xForY) > std::get<1>(xForY);
}

Price Product::priceForXForY(long count)
{

    long x = std::get<0>(xForY);
    long y = std::get<1>(xForY);
    long rem = count % x;
    long value = count / x;

    return price_ * rem + price_ * (value * y);
}