#ifndef Product_h
#define Product_h

#include "Price.h"
#include "Exceptions.h"
#include <string>
#include <tuple>

enum ProductType {
    Unit,
    Portion,
};

class Product
{
private:
    std::string name_;
    ProductType value_;
    Price price_;
    double discount_;
    std::tuple<long, long> xForY;

    Price priceForXForY(long count) {
        
        long x = std::get<0> (xForY);
        long y = std::get<1> (xForY);
        long rem = count % x;
        long value = count / x;

        return price_ * rem + price_ * (value * y);
    }

    bool isXEqY() {
        return std::get<0> (xForY) > std::get<1> (xForY);
    }

public:
    Product(const std::string& name, Price price, ProductType value): 
        value_(value), 
        price_(price) {
        name_ = name;
        discount_ = 0.0;
        xForY = std::make_tuple(0, 0);
    }
    ~Product() {};

    Price priceFor(long count) {
        if (value_ != ProductType::Unit) {
            throw InvalidMultiplicationArgument("ProductType::Portion should be multiplied by double");
        }
        (void) name_;

        if (discount_ > 0.0) {
            return (price_ * discount_) * count;
        }
        if (isXEqY()) {
            return priceForXForY(count);
        }

        return price_ * count;
    }

    Price priceFor(double portion) {
        if (value_ != ProductType::Portion) {
            throw InvalidMultiplicationArgument("ProductType::Unit should be multiplied by long");
        }
        (void) name_;
        if (discount_ > 0.0) {
            return (price_ * discount_) * portion;
        }

        return price_ * portion;
    }

    void setDiscount(double discount) {
        if (discount > 1.0) {
            throw DiscountGreaterThan1();
        }
        if (discount < 0.0) {
            throw DiscountSmallerThan0();
        }
        discount_ = (1.0 - discount);
        xForY = std::make_tuple(0, 0);
    }

    void setPackDiscount(long x, long y) {
        if (y >= x) {
            throw DiscountLargerThanValue();
        }
        discount_ = 0.0;

        xForY = std::make_tuple(x, y);;
    }
};


#endif