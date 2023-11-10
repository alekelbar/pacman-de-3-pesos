#pragma once
#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include "TileMap.hpp"

const int GAME_SCREN_SIZE = 368;

class Game
{

private:
  sf::RenderWindow *window; // La ventana del juego...
  Player *player;           // El jugador...
  TileMap tileMap;

public:
  Game();
  void playerMovement();
  int gameLoop();
};