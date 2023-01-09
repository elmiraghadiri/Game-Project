#pragma once
#include <fstream>
#include <iostream>
#include "player.hpp"
#include "map.hpp"

class Game
{
private:
    Map map;
    Player player;
    std::string name;
    std::fstream file;
    void save();
public:
    void run();
};
