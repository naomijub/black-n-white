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

public:
    Product(const std::string& name, Price price, ProductType value): 
        value_(value), 
        price_(price) {
        name_ = name;
    }
    ~Product() {};

    Price priceFor(long count) {
        if (value_ != ProductType::Unit) {
            throw InvalidMultiplicationArgument("ProductType::Portion should be multiplied by double");
        }
        (void) name_;
        return price_ * count;
    }

    Price priceFor(double portion) {
        if (value_ != ProductType::Portion) {
            throw InvalidMultiplicationArgument("ProductType::Unit should be multiplied by long");
        }
        (void) name_;
        return price_ * portion;
    }
};


#endif