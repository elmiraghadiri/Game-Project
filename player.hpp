#pragma once
//#include "game.hpp"
#include <iostream>

class Player
{   
private:
    std::string name;
    int score;//number of player move
    int bestScore;//best way
    void initVariables();
public:
    Player();
    void getInfo();
    int getScore() { return score; };
    char move();

    friend class Game;
};
