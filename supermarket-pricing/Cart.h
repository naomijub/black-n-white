#ifndef Cart_h
#define Cart_h

#include <unordered_map>
#include <string>
#include "Product.h"
#include "Price.h"

struct Item
{
    Price price;
    bool available;
    Stock stock;
};

class Cart
{
private:
    std::unordered_map<std::string, Product *> products;

public:
    Cart();
    ~Cart();
    Item check_price(std::string &product_name, double portion);
    Item check_price(std::string &product_name, long count);
};

#endif