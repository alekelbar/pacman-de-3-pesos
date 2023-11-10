#pragma once
#include <vector>

#include "exeptions/FailedToLoadTexture.hpp"
#include "models/BaseEntity.hpp"
#include "TileMap.hpp"

class Player : public BaseEntity
{
public:
  // La dirección del jugador...
  enum direction
  {
    up,
    down,
    left,
    right,
  };

  Player(sf::Vector2f);
  void draw(sf::RenderWindow &w) override;
  void moveForward();
  void moveBackward();
  void teleportIfPossible();
  void playerCollision(TileMap &);
  void setDirection(direction dir);
  void incrementeScore(int);

private:
  std::vector<sf::Texture> textures;
  int lives;
  double speed;
  bool hasSuperPower;
  int score;
  sf::Vector2f previousPosition;
  // la dirección del jugador...
  direction dir;
};
