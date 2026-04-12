#pragma once
#include <string>

struct RiskManager{
    double peakEquity;
    double drawdown;
    double maxDrawdown;
    bool halted;
    double limit;
};

RiskManager createRiskManager(double initialEquity, double limit = 0.1);
void updateRisk(RiskManager& riskManager, double currentEquity, const std::string& date);