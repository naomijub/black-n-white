#include "Portofolio.h"
#include "PortofolioExceptions.h"
#include <numeric>

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
    transact(item, shares_, now);
}

void Portofolio::sell(const std::string& item,  int shares_, Time now) {
    if (shares_ > shares(item)) throw InsufficientSharesException();
    transact(item, -shares_, now);
}

void Portofolio::transact(const std::string& item,  int shares_, Time now) {
    holdings_[item].push_back(PurchaseRecord({shares_, now}));
}

int Portofolio::shares(const std::string& item) {
    auto holdingsShares = purchases(item);
    auto holdingsCountByShare = std::accumulate(holdingsShares.begin(), holdingsShares.end(), 0, 
        [](int acc, PurchaseRecord purchase) { return  acc + purchase.ShareCount; });
    return holdingsCountByShare;
}

std::vector<PurchaseRecord> Portofolio::purchases(const std::string& item) {
    auto it = holdings_.find(item);
    if (it == holdings_.end()) return {};
    return it->second;
}