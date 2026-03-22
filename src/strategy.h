#pragma once
#include <vector>

enum class Signal {
    BUY,
    SELL,
    HOLD
};

Signal computeSignal(const std::vector<double> &prices, int shortLen = 5, int longLen = 20);