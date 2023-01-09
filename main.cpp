#include <iostream>
#include "game.hpp"

using namespace std;

int main()
{
    Game game;
    game.run();
    return 0;
}
//g++ -o app main.cpp game.cpp map.cpp player.cpp