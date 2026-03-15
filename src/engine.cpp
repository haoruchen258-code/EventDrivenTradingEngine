#include "engine.h"
#include "strategy.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>

void runEngine(const std::vector<Tick> &ticks) {
  std::cout << "引擎启动，共加载 " << ticks.size() << " 条行情数据。"
            << std::endl;
  std::cout << "按 Ctrl+C 停止。" << std::endl;
  std::cout << std::endl;

  int cycle = 1;

  while (true) {
    std::cout << "--- 第 " << cycle << " 轮 ---" << std::endl;

    std::ofstream csv("data/signals.csv");
    csv << "Date,Price,Signal\n";

    std::vector<double> priceHistory;

    double prevPrice = ticks[0].price;

    for (int i = 0; i < (int)ticks.size(); i++) {
      double price = ticks[i].price;

      std::string direction;
      if (price > prevPrice)
        direction = "UP  ";
      else if (price < prevPrice)
        direction = "DOWN";
      else
        direction = "FLAT";

      priceHistory.push_back(price);

      Signal sig = computeSignal(5, 20, priceHistory);

      std::string sigStr;
      if (sig == Signal::BUY)
        sigStr = "BUY ";
      else if (sig == Signal::SELL)
        sigStr = "SELL";
      else
        sigStr = "----";

      std::cout << ticks[i].date << "  " << direction << "  " << sigStr
                << "  price: " << price << std::endl;

      csv << ticks[i].date << "," << price << "," << sigStr << "\n";

      prevPrice = price;

      std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    std::cout << std::endl;
    std::cout << "数据播放完毕。信号日志已写入 data/signals.csv。重新开始..."
              << std::endl;
    std::cout << std::endl;

    cycle++;
  }
}