#pragma once
#include "Player.hpp"
#include <SFML/Graphics.hpp>

class Game {

private:
  sf::RenderWindow *window; // La ventana del juego...
  Player *player;           // El jugador...

public:
  Game();
  void updatePlayerDirection();
  int gameLoop();
};