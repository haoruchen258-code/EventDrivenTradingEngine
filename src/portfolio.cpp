#include "portfolio.h"
#include <cmath>

const double COMMISSION_RATE = 0.001; 

Portfolio createPortfolio(double initialCash){
    Portfolio p;
    p.cash = initialCash;
    p.position = 0;
    return p;
}

bool executeBuy(Portfolio& portfolio, const std::string& date, double price){
    if(portfolio.position > 0) {
        return false; 
    }
    int shares = static_cast<int>(std::floor(portfolio.cash / (price * (1.0 + COMMISSION_RATE))));
    if(shares <= 0) {
        return false; 
    }
    double cost = shares * price;
    double commission = cost * COMMISSION_RATE;
    portfolio.cash -= (cost + commission);
    portfolio.position += shares;
    portfolio.tradeLog.push_back({date, "BUY", price, shares, commission, portfolio.cash});
    return true;
}

bool executeSell(Portfolio& portfolio, const std::string& date, double price){
    if(portfolio.position <= 0) {
        return false; 
    }
    int shares = portfolio.position;
    double revenue = shares * price;
    double commission = revenue * COMMISSION_RATE;
    portfolio.cash += (revenue - commission);
    portfolio.position -= shares;
    portfolio.tradeLog.push_back({date, "SELL", price, shares, commission, portfolio.cash});
    return true;
}

double getNetValue(const Portfolio& portfolio, double currentPrice){
    return portfolio.cash + portfolio.position * currentPrice;
}