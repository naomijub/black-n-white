#include "Portofolio.h"

Portofolio::Portofolio()  : empty_(true)
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
}