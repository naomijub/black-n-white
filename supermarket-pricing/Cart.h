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
    void remove_from_stock(std::string &product_name, double portion);
    void remove_from_stock(std::string &product_name, long count);

public:
    Cart();
    ~Cart();
    Item check_price(std::string &product_name, double portion);
    Item check_price(std::string &product_name, long count);
    Price buy_product(std::string &product_name, double portion);
    Price buy_product(std::string &product_name, long count);
};

#endif