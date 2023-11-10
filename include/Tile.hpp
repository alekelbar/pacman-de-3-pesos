#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

const int BLOCK_SIZE = 17;

class Tile
{
private:
    char symbol;
    sf::Shape *shape;

public:
    sf::Shape *getShape() { return this->shape; }

    Tile(int row, int col, char symbol = '*')
    {
        this->symbol = symbol;
        switch (this->symbol)
        {
        case '*':
            shape = new sf::RectangleShape({BLOCK_SIZE - 2, BLOCK_SIZE - 2}); // -2 para compensar el outline...
            shape->setPosition({col * BLOCK_SIZE, row * BLOCK_SIZE});
            shape->setFillColor(sf::Color::Blue);
            shape->setOutlineThickness(2);
            shape->setOutlineColor(sf::Color::Black);
            break;

        case 'p':
            shape = new sf::CircleShape(BLOCK_SIZE / 4);
            shape->setPosition({col * BLOCK_SIZE + BLOCK_SIZE / 4, row * BLOCK_SIZE + BLOCK_SIZE / 4}); // centrar los puntos BLOCK_SIZE / 4
            shape->setFillColor(sf::Color::White);
            break;

        case 'f':
            shape = new sf::CircleShape(BLOCK_SIZE / 4);
            shape->setPosition({col * BLOCK_SIZE + BLOCK_SIZE / 4, row * BLOCK_SIZE + BLOCK_SIZE / 4}); // centrar los puntos BLOCK_SIZE / 4
            shape->setFillColor(sf::Color::Red);
            break;

        case 'g':
            shape = new sf::CircleShape(BLOCK_SIZE / 4);
            shape->setPosition({col * BLOCK_SIZE + BLOCK_SIZE / 4, row * BLOCK_SIZE + BLOCK_SIZE / 4}); // centrar los puntos BLOCK_SIZE / 4
            shape->setFillColor(sf::Color::Cyan);
            break;

        case 'w':
            shape = new sf::CircleShape(BLOCK_SIZE / 4);
            shape->setPosition({col * BLOCK_SIZE + BLOCK_SIZE / 4, row * BLOCK_SIZE + BLOCK_SIZE / 4}); // centrar los puntos BLOCK_SIZE / 4
            shape->setFillColor(sf::Color::Yellow);
            break;
        default:
            break;
        }
    }
};