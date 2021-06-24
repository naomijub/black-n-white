#ifndef Cart_h
#define Cart_h

#include <unordered_map>
#include <string>
#include <vector>
#include "Product.h"
#include "Price.h"

struct Item
{
    Price price;
    bool available;
    Stock stock;
};

struct Quantity
{
    long count;
    double portion;
    Quantity(double p) {
        portion = p;
        count = 0;
    }

    Quantity(long c) {
        count = c;
        portion = 0;
    }
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
    Price total_price(std::vector<std::pair<std::string, Quantity>> products_to_buy);
};

#endif