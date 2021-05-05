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

void Portofolio::purchase(const std::string& item, unsigned int shares_) {
    if (shares_ == 0) throw InvalidShareAmountException();
    holdings_[item] += shares(item) + shares_;
    purchases_.push_back(PurchaseRecord({shares_, std::chrono::system_clock::now()}));
}

void Portofolio::sell(const std::string& item, unsigned int shares_) {
    if (shares_ > shares(item)) throw InsufficientSharesException();
}

unsigned int Portofolio::shares(const std::string& item) {
    auto it = holdings_.find(item);
    if (it == holdings_.end()) return 0;
    return it->second;
}

std::vector<PurchaseRecord> Portofolio::purchases(const std::string& item) {
    (void)item;
    return purchases_;
}