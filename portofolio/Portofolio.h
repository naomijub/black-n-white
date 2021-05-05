#ifndef Portofolio_h
#define Portofolio_h

#include <string>
#include <unordered_map>
#include <chrono>
#include <vector>

using Time = std::chrono::time_point<std::chrono::system_clock>;

struct PurchaseRecord
{
    PurchaseRecord(int shares, Time now) : ShareCount(shares), Date(now) {}
    int ShareCount;
    Time Date;
};

class Portofolio
{
private:
    std::unordered_map<std::string, int> holdings_;
    std::vector<PurchaseRecord> purchases_;
    void transact(const std::string& item,  int shares, Time now);

public:
    Portofolio();
    ~Portofolio();
    bool isEmpty();
    void purchase(const std::string& item, int shares, Time now);
    void sell(const std::string& item, int shares, Time now);
    int shares(const std::string& item);
    std::vector<PurchaseRecord> purchases(const std::string& item);
};

#endif