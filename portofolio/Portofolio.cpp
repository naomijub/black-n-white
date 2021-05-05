#include "Portofolio.h"
#include "PortofolioExceptions.h"
#include <map>
#include <string>

Portofolio::Portofolio()  : holdings_({})
{ }

Portofolio::~Portofolio()
{
}

bool Portofolio::isEmpty() {
    return holdings_.size() == 0;
}

void Portofolio::purchase(const std::string& item, unsigned int shares_) {
    if (shares_ == 0) throw InvalidShareAmountException();
    holdings_[item] += shares(item) + shares_;
}

void Portofolio::sell(const std::string& item, unsigned int shares_) {
    if (shares_ > shares(item)) throw InsufficientSharesException();
}

unsigned int Portofolio::shares(const std::string& item) {
    auto it = holdings_.find(item);
    if (it == holdings_.end()) return 0;
    return it->second;
}