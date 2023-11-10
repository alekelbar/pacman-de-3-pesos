#include "../include/Player.hpp"
#include "Player.hpp"

void Player::moveBackward()
{
  sf::Vector2f movement = this->sprite->getPosition();

  switch (this->dir)
  {
  case Player::up:
    movement.y += speed;
    break;
  case Player::down:
    movement.y -= speed;
    break;
  case Player::left:
    movement.x += speed;
    break;
  case Player::right:
    movement.x -= speed;
    break;
  default:
    break;
  }

  this->sprite->setPosition(movement);
}

void Player::moveForward()
{
  sf::Vector2f movement = this->sprite->getPosition();
  previousPosition = movement;

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

  this->sprite->setPosition(movement);
}

void Player::teleportIfPossible()
{
  sf::Vector2f movement = this->sprite->getPosition();

  // Mecanica de teletransportación de por las paredes...
  if (movement.x < 0)
  {
    movement.x = 368;
  }
  if (movement.y < 0)
  {
    movement.y = 368;
  }

  if (movement.x > 368)
  {
    movement.x = 0;
  }

  if (movement.y > 368)
  {
    movement.y = 0;
  }

  this->sprite->setPosition(movement);
}

void Player::playerCollision(TileMap &map)
{
  std::vector<Tile> tiles = map.getTiles();
  for (auto &&i : tiles)
  {
    if (sprite->getGlobalBounds().intersects(i.getShape()->getGlobalBounds()))
    {

      switch (i.getSymbol())
      {
      case '*':
        moveBackward();
        std::cout << "El jugador impacta con un muro..." << std::endl;
        break;

      case 'p':
        std::cout << "El jugador impacta con un punto..." << std::endl;
        incrementeScore(1);
        // Remover ese punto del mapa...
        map.removeTile(i.getShape()->getPosition());

        std::cout << "Su score actual: " << score << std::endl;
        break;

      case 'f':
        std::cout << "El jugador impacta con una fruta..." << std::endl;
        incrementeScore(10);
        // Remover ese punto del mapa...
        map.removeTile(i.getShape()->getPosition());
        std::cout << "Su score actual: " << score << std::endl;
        break;

      case 'g':
        std::cout << "El jugador impacta con un fantasma..." << std::endl;
        // ¿Tiene super poderes?
        //........................
        // ¿No Tiene super poderes?
        break;

      case 'w':
        std::cout << "El jugador impacta con una pastilla de poder..." << std::endl;
        break;

      default:
        break;
      }
    }
  }
}

void Player::setDirection(direction dir)
{
  this->sprite->setTexture(textures.at(dir));
  this->dir = dir;
}

void Player::incrementeScore(int score) { this->score += score; }

Player::Player(sf::Vector2f initialPosition)
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
  this->position = new sf::Vector2f(initialPosition);

  this->previousPosition = *position;
  this->sprite->setPosition(*position);
  this->sprite->setScale(.8, .8);

  // stats...
  this->lives = 3;
  this->speed = 2.3;
  this->score = 0;
  this->hasSuperPower = false;
  this->dir = Player::right;
}

void Player::draw(sf::RenderWindow &w) { w.draw(*this->sprite); }