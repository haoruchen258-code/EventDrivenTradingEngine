#pragma once
#include <string>
#include <vector>

struct Tick {
    std::string date;
    double price;
};

std::vector<Tick> loadCSV(const std::string& filename);
