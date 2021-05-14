#ifndef Product_h
#define Product_h

#include "Price.h"
#include "Exceptions.h"
#include <string>

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

public:
    Product(const std::string& name, Price price, ProductType value): 
        value_(value), 
        price_(price) {
        name_ = name;
        discount_ = 0.0;
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
        discount_ = (1.0 - discount);
    }
};


#endif