#include "risk.h"
#include <iostream>
#include <algorithm> // std::max

RiskManager createRiskManager(double initialEquity, double limit){
    RiskManager rm;
    rm.peakEquity = initialEquity;
    rm.drawdown = 0.0;
    rm.maxDrawdown = 0.0;
    rm.halted = false;
    rm.limit = limit;
    return rm;
}

void updateRisk(RiskManager& riskManager, double currentEquity, const std::string& date){
    riskManager.peakEquity = std::max(riskManager.peakEquity, currentEquity);
    if (riskManager.peakEquity > 0.0) {
        riskManager.drawdown = (riskManager.peakEquity - currentEquity) / riskManager.peakEquity;
    } else {
        riskManager.drawdown = 0.0;
    }
    riskManager.maxDrawdown = std::max(riskManager.maxDrawdown, riskManager.drawdown);
    if(riskManager.drawdown >= riskManager.limit && !riskManager.halted) {
        riskManager.halted = true;
        std::cout << "风险警告！账户已达到最大回撤限制，停止交易。日期: " << date 
                  << " 当前回撤: " << riskManager.drawdown * 100 << "% 最大回撤: " 
                  << riskManager.maxDrawdown * 100 << "%" << std::endl;
    }
}