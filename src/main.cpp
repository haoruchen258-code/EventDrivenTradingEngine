#include "data_feed.h"
#include <iostream>
#include "engine.h"

int main() {
  std::cout << "Event-Driven Trading Engine -- Market Data Feed" << std::endl;
  std::cout << "------------------------------------------------" << std::endl;

  std::vector<Tick> ticks = loadCSV("data/tr_eikon_eod_data.csv");

  if (ticks.empty()) {
    std::cout << "No data loaded. Check that data/tr_eikon_eod_data.csv exists."
              << std::endl;
    return 1;
  }

  std::cout << "Loaded " << ticks.size() << " AAPL.O ticks." << std::endl;

  runEngine(ticks);
  return 0;
}