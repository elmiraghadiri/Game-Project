#pragma once
#include <array>
#include <iostream>

class Map
{
private:
    std::array<std::string, 15> sketch;
    void initMap();
public:
    Map();
    void showMap(int score);
    int update(int move, int &score);
};
