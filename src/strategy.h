#pragma once
#include <vector>

enum class Signal {
    BUY,
    SELL,
    HOLD
};

Signal computeSignal(int shortLen, int longLen, std::vector<double>& prices);