#include "map.hpp"
#include <iostream>

using namespace std;

Map::Map()
{
    initMap();
}

void Map::initMap()
{
    array<string, 15> sketch1 = {
        "    -------------------------\n",
        "|   | # |   |   | # |   |   |\n",
        "-----------------------------\n",
        "|   | # |   |   | # | # |   |\n",
        "-----------------------------\n",
        "|   |   |   | # |   |   |   |\n",
        "-----------------------------\n",
        "|   |   |   |   | # |   |   |\n",
        "-----------------------------\n",
        "|   |   | # | # |   |   |   |\n",
        "-----------------------------\n",
        "| # |   |   |   |   | # |   |\n",
        "-----------------------------\n",
        "|   |   | # |   | # | # | P |\n",
        "-----------------------------\n"
    };
    sketch = sketch1;
}

void Map::showMap(int score)
{
    system("clear");
    for(auto i : sketch)
    {
        cout << i;
    }
    cout << "Score : " << score << endl;
    cout << "Move with a = left, w = up, d = right, s = down" << endl;
}

int Map::update(int move, int &score)
{
    system("clear");
    
    int x, y;
    bool find = false;
    for (size_t i = 0; i < sketch.size(); i++)
    {
        for (size_t j = 0; j < sketch[0].size(); j++)
        {
            if (sketch[i][j] == 'P')
            {
                x = j;
                y = i;
                find = true;
                break;
            }
        }
        if (find)
        {
            break;
        }        
    }
    int oldX = x, oldY = y;

    if (y == 1 && x == 2 && move == 2)
    {
        if (score == 14)
        {
            cout << "************** YOU Won **************" << endl;    
        } else
        {
            cout << "************** YOU Lost **************" << endl;
            cout << "Points required : 14" << endl;
        }
        cout << "Your score : " << score << endl;
        cout << "Enter 1 to continue..." << endl;
        int n;
        cin >> n;
        if (n == 1)
        {
            //try again
            sketch[13][26] = 'P';
            sketch[1][2] = ' ';
            return -1;
        } else
        {
            return -2;
        }
        
    }
    
    switch (move)
    {
    case 1:
        if (x - 4 > 0)
        {
            x -= 4;
        }
        break;
    case 2:
        if (y - 2 > 0)
        {
            y -= 2;
        }
        
        break;
    case 3:
        if (x + 4 < sketch[0].size())
        {
            x += 4;
        }
        
        break;
    case 4:
        if (y + 2 < 15)
        {
            y += 2;
        }
        
        break;
    default:
        break;
    }
    if (sketch[y][x] != '#')
    {
        sketch[oldY][oldX] = ' ';
        score++;
        sketch[y][x] = 'P';
    }
    return 10;
}