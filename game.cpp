#include "game.hpp"
#include <iostream>

using namespace std;

void Game::run()
{
    
    while (1)
    {
        if (player.getScore() == -1)
        {
            player.getInfo();
            player.score++;
        }

        map.showMap(player.getScore());
        char m = player.move();
        if (m != '0')
        {
            int choice;
            int tmp = 1;
            switch (m)
            {
            case 'a':
                choice = map.update(1, player.score);
                if (choice == -1)
                {
                    tmp = 0;
                } else if (choice == -2)
                {
                    tmp = -2;
                }
                
                break;
            case 'w':
                choice = map.update(2, player.score);
                if (choice == -1)
                {
                    tmp = 0;
                } else if (choice == -2)
                {
                    tmp = -2;
                }
                break;
            case 'd':
                choice = map.update(3, player.score);
                if (choice == -1)
                {
                    tmp = 0;
                } else if (choice == -2)
                {
                    tmp = -2;
                }
                break;
            case 's':
                choice = map.update(4, player.score);
                if (choice == -1)
                {
                    tmp = 0;
                } else if (choice == -2)
                {
                    tmp = -2;
                }
                break;
            default:
                break;
            }

            if (tmp == 0)
            {
                //save
                save();
                player.score = -1;
            } else if (tmp == -2)
            {
                save();
                exit(EXIT_SUCCESS);
            }
            
            

        } else
        {
            break;
        }
    }
}

void Game::save()
{
    file.open("score.txt", ios::app | ios::out);
    file << player.name << "\t" << player.score << endl;
    file.close();
}