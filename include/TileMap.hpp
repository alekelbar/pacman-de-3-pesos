#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Tile.hpp"

const int BLOCKS = 23;

class TileMap
{

public:
    TileMap() {}

    void makeList()
    {
        tiles.clear();
        for (int i = 0; i < BLOCKS; i++)
        {
            for (int j = 0; j < BLOCKS; j++)
            {
                if (map[i][j] == '*') // blocks...
                {
                    auto tile = Tile(i, j, '*');
                    tiles.push_back(tile);
                }

                if (map[i][j] == 'p') // points...
                {
                    auto tile = Tile(i, j, 'p');
                    tiles.push_back(tile);
                }

                if (map[i][j] == 'f') // fruits
                {
                    auto tile = Tile(i, j, 'f');
                    tiles.push_back(tile);
                }

                if (map[i][j] == 'g') // ghost
                {
                    auto tile = Tile(i, j, 'g');
                    tiles.push_back(tile);
                }

                if (map[i][j] == 'w') // power
                {
                    auto tile = Tile(i, j, 'w');
                    tiles.push_back(tile);
                }
            }
        }
    }

    void renderMap(sf::RenderWindow &windows)
    {
        makeList();
        for (int i = 0; i < tiles.size(); i++)
        {
            windows.draw(*tiles[i].getShape());
        }
    }

private:
    std::vector<Tile> tiles;
    std::string map[23] = {
        "***********************",
        "*ppp*pfpppppppppwp*ppp*",
        "*p*p*p*p*******p*p*p*p*",
        "*ppppppp*ppppp*ppppppp*",
        "*ppp*p***p***p***p*ppp*",
        "*p*p*p***p*g*p***p*p*p*",
        "*ppp*p***p***p***p*ppp*",
        "*****p***ppppp***p*****",
        "*ppppp***********ppppp*",
        "*****p*ppppppppp*p*****",
        "pppppppp***p***pppppppp",
        "*******p*ppppp*p*******",
        "*******p*******p*******",
        "*******ppppppppp*******",
        "***********************",
        "***********************",
        "***********************",
        "***********************",
        "***********************",
        "***********************",
        "***********************",
        "***********************",
        "***********************",
    };
};