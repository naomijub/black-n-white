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

union Stock
{
    unsigned long count;
    double portion;
    Stock(double p) {
        portion = p;
    }

    Stock( unsigned long c) {
        count = c;
    }
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
    Stock stock;

    Product(const std::string &name, Price price, ProductType value, Stock initial_stock) : value_(value),
                                                                       price_(price) , stock(initial_stock)
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