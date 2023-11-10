#pragma once
#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include "TileMap.hpp"

class Game
{

private:
  sf::RenderWindow *window; // La ventana del juego...
  Player *player;           // El jugador...
  TileMap tileMap;

public:
  Game();
  void updatePlayerDirection();
  int gameLoop();
};