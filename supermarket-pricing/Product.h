#ifndef Product_h
#define Product_h

#include "Price.h"
#include "Exceptions.h"
#include <string>
#include <tuple>

enum ProductType
{
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

    Price priceForXForY(long count);
    bool isXEqY();

public:
    Product(const std::string &name, Price price, ProductType value) : value_(value),
                                                                       price_(price)
    {
        name_ = name;
        discount_ = 0.0;
        xForY = std::make_tuple(0, 0);
    }
    ~Product(){};

    Price priceFor(long count);
    Price priceFor(double portion);
    void setDiscount(double discount);
    void setDiscount(long x, long y);
};

#endif