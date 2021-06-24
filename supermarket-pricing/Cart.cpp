#include "Cart.h"

Cart::Cart()
{
    products = {
        {"milk", new Product("milk", Price(299), ProductType::Unit, Stock((unsigned long)50))},
        {"meat", new Product("meat", Price(1499), ProductType::Portion, Stock(120.0))}};
}

Cart::~Cart()
{
    for (auto &it : products)
    {
        delete it.second;
    }
}

Item Cart::check_price(std::string &product_name, double portion)
{
    if (products.find(product_name) != products.end())
    {
        auto product = products[product_name];
        Price price = product->priceFor(portion);
        bool hasStock = product->stock.portion > portion;

        return Item{
            hasStock ? price : Price(0), hasStock, product->stock};
    }

    return Item{Price(0), false, Stock(0.0)};
}

Item Cart::check_price(std::string &product_name, long count)
{
    if (products.find(product_name) != products.end())
    {
        auto product = products[product_name];
        Price price = product->priceFor(count);
        bool hasStock = product->stock.count > count;

        return Item{
            hasStock ? price : Price(0), hasStock, product->stock};
    }

    return Item{Price(0), false, Stock((unsigned long)0)};
}
