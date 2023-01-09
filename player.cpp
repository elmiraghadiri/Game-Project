#include "player.hpp"
#include <iostream>

using namespace std;

Player::Player()
{
    initVariables();
}

void Player::initVariables()
{
    score = -1;
    bestScore = 15;
}

char Player::move()
{
    char event;
    cin >> event;
    return event;
}

void Player::getInfo()
{
    cout << "Enter your name : ";
    cin >> name;
}
