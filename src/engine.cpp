#include "engine.h"
#include <iostream>
#include <thread>
#include <chrono>

void runEngine(const std::vector<Tick>& ticks){
    while(true){
        double previousPrice = ticks[0].price;
        for(const auto& tick : ticks){
            if(tick.price > previousPrice){
                std::cout << "UP" ;
            }
            else if(tick.price < previousPrice){
                std::cout << "DOWN" ;
            }else{
                std::cout << "UNCHANGED" ;
            }
            std::cout << "  " << tick.date << " AAPL.O  price: " << tick.price << std::endl;
            previousPrice = tick.price;
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        std::cout << "End of tick data. Restarting..." << std::endl;
    }
}