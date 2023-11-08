#pragma once
#include <SFML/Graphics.hpp>

class BaseEntity {
protected:
  // Atributos heredables...
  sf::Sprite *sprite;
  sf::Vector2f *position;

public:
  // Metodo virtual puro...
  virtual void draw(sf::RenderWindow &w) = 0;
};