#include "strategy.h"
#include <numeric>

static double sma(const std::vector<double>& prices, int length){
    return std::accumulate(prices.end() - length, prices.end(), 0.0) / length;
}

Signal computeSignal(int shortLen, int longLen, std::vector<double>& prices){
    if(prices.size() < longLen) {
        return Signal::HOLD; 
    }
    if ((int)prices.size() < longLen + 1) {
        return Signal::HOLD;
    }
    double shortSMA = sma(prices, shortLen);
    double longSMA = sma(prices, longLen);
    std::vector<double> prevPrices(prices.begin(), prices.end() - 1);
    double shortPrev = sma(prevPrices, shortLen);
    double longPrev = sma(prevPrices, longLen);

    if (shortSMA > longSMA && shortPrev <= longPrev) {
        return Signal::BUY;
    } else if (shortSMA < longSMA && shortPrev >= longPrev) {
        return Signal::SELL;
    } else {
        return Signal::HOLD;
    }
}