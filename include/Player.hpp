#pragma once
#include <vector>

#include "exeptions/FailedToLoadTexture.hpp"
#include "models/BaseEntity.hpp"

class Player : public BaseEntity {
public:
  // La dirección del jugador...
  enum direction {
    up,
    down,
    left,
    right,
  };

  Player();
  void draw(sf::RenderWindow &w) override;
  void move();
  void setDirection(direction dir);

private:
  std::vector<sf::Texture> textures;
  int lives;
  double speed;
  bool hasSuperPower;
  // la dirección del jugador...
  direction dir;
};
