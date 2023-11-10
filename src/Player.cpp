#include "../include/Player.hpp"
#include "Player.hpp"

void Player::move()
{
  sf::Vector2f movement = this->sprite->getPosition();

  switch (this->dir)
  {
  case Player::up:
    movement.y -= speed;
    break;
  case Player::down:
    movement.y += speed;
    break;
  case Player::left:
    movement.x -= speed;
    break;
  case Player::right:
    movement.x += speed;
    break;
  default:
    break;
  }

  // Mecanico de teletransportación de por las paredes...
  if (movement.x < 0)
  {
    movement.x = 391;
  }
  if (movement.y < 0)
  {
    movement.y = 391;
  }

  if (movement.x > 391)
  {
    movement.x = 0;
  }

  if (movement.y > 391)
  {
    movement.y = 0;
  }

  this->sprite->setPosition(movement);
}

void Player::setDirection(direction dir)
{
  this->sprite->setTexture(textures.at(dir));
  this->dir = dir;
}

Player::Player()
{
  // Cargar la textura...
  const std::string filename = "assets/pacman/";

  // Llenar el vector textures antes de usarlo
  textures.resize(4);
  for (size_t i = 0; i < textures.size(); i++)
  {
    if (!textures.at(i).loadFromFile(filename + std::to_string(i) + ".png"))
      throw FailedToLoadTexture(filename + std::to_string(i) + ".png");
  }

  // cargar el sprite y la posición en pantalla...
  this->sprite = new sf::Sprite(textures.at(3));

  this->position = new sf::Vector2f({110, 110});

  // stats...
  this->lives = 3;
  this->speed = 4;
  this->hasSuperPower = false;
  this->dir = Player::right;
}

void Player::draw(sf::RenderWindow &w) { w.draw(*this->sprite); }