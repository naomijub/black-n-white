#include "Portofolio.h"

Portofolio::Portofolio()  : empty_(true), shares_(0)
{
}

Portofolio::~Portofolio()
{
}

bool Portofolio::isEmpty() {
    return empty_;
}

void Portofolio::purchase(const std::string& item, unsigned int shares) {
    (void)item; (void)shares;
    empty_ = false;
    shares_ = shares;
}

unsigned int Portofolio::shares(const std::string& item) {
    return shares_;
}