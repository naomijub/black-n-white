#ifndef Portofolio_h
#define Portofolio_h

#include <string>

class Portofolio
{
private:
    bool empty_;
public:
    Portofolio();
    ~Portofolio();
    bool isEmpty();
    void purchase(const std::string& item, unsigned int shares);
};

#endif