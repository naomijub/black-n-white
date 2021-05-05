#ifndef Portofolio_h
#define Portofolio_h

#include <string>

class Portofolio
{
private:
    unsigned int shares_;
public:
    Portofolio();
    ~Portofolio();
    bool isEmpty();
    void purchase(const std::string& item, unsigned int shares);
    unsigned int shares(const std::string& item);
};

#endif