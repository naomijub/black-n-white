#include "Portofolio.h"
#include "PortofolioExceptions.h"

Portofolio::Portofolio()  : shares_(0)
{
}

Portofolio::~Portofolio()
{
}

bool Portofolio::isEmpty() {
    return shares_ == 0;
}

void Portofolio::purchase(const std::string& item, unsigned int shares) {
    if (shares == 0) throw InvalidShareAmountException();
    shares_ = shares;
}

unsigned int Portofolio::shares(const std::string& item) {
    return shares_;
}