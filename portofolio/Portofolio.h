#ifndef Portofolio_h
#define Portofolio_h

#include <string>
#include <unordered_map>
#include <chrono>
#include <vector>

struct PurchaseRecord
{
    PurchaseRecord(unsigned int shares, std::chrono::time_point<std::chrono::system_clock> now) : ShareCount(shares), Date(now) {}
    unsigned int ShareCount;
    std::chrono::time_point<std::chrono::system_clock> Date;
};

class Portofolio
{
private:
    std::unordered_map<std::string, int> holdings_;
    std::vector<PurchaseRecord> purchases_;

public:
    Portofolio();
    ~Portofolio();
    bool isEmpty();
    void purchase(const std::string& item, unsigned int shares);
    void sell(const std::string& item, unsigned int shares);
    unsigned int shares(const std::string& item);
    std::vector<PurchaseRecord> purchases(const std::string& item);
};

#endif