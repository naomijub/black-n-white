#include "Portofolio.h"
#include "PortofolioExceptions.h"

Portofolio::Portofolio()  : holdings_({})
{ }

Portofolio::~Portofolio()
{
}

bool Portofolio::isEmpty() {
    return holdings_.size() == 0;
}

void Portofolio::purchase(const std::string& item, int shares_, Time now) {
    if (shares_ == 0) throw InvalidShareAmountException();
    holdings_[item] = shares(item) + shares_;
    purchases_.push_back(PurchaseRecord({shares_, now}));
}

void Portofolio::sell(const std::string& item,  int shares_, Time now) {
    if (shares_ > shares(item)) throw InsufficientSharesException();
    auto sellShares = - shares_;
    holdings_[item] = shares(item) + sellShares;
    purchases_.push_back(PurchaseRecord({sellShares, now}));
}

int Portofolio::shares(const std::string& item) {
    auto it = holdings_.find(item);
    if (it == holdings_.end()) return 0;
    return it->second;
}

std::vector<PurchaseRecord> Portofolio::purchases(const std::string& item) {
    (void)item;
    return purchases_;
}