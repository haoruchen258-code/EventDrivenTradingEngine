#pragma once
#include <string>
#include <vector>

struct Trade {
    std::string date;
    std::string action;
    double price;
    int quantity;
    double commission;
    double cashAfter;
}; 

struct Portfolio {
    double cash;
    int position;
    std::vector<Trade> tradeLog;
};

Portfolio createPortfolio(double initialCash);

bool executeBuy(Portfolio& portfolio, const std::string& date, double price);

bool executeSell(Portfolio& portfolio, const std::string& date, double price);

double getNetValue(const Portfolio& portfolio, double currentPrice);
