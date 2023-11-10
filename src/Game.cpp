#include "../include/Game.hpp"
#include "Game.hpp"

Game::Game()
{
  window = new sf::RenderWindow(sf::VideoMode(GAME_SCREN_SIZE, GAME_SCREN_SIZE), "Pacman");
  player = new Player({16, 16});
  window->setFramerateLimit(20);
}

void Game::playerMovement()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
  {
    player->setDirection(Player::direction::up);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
  {
    player->setDirection(Player::direction::down);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
  {
    player->setDirection(Player::direction::left);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
  {
    player->setDirection(Player::direction::right);
  }

  player->moveForward();
  player->playerCollision(tileMap);
  player->teleportIfPossible();
}

int Game::gameLoop()
{
  while (window->isOpen())
  {
    sf::Event event;
    while (window->pollEvent(event))
    {
      // eventos de teclado...
      if (event.type == sf::Event::Closed)
      {
        window->close();
      }

      if (event.type == sf::Event::KeyPressed)
      {
        if (event.key.code == sf::Keyboard::Escape)
        {
          window->close();
        }
      }
    }
    // Actualizacines...
    playerMovement();
    // dibujado...
    window->clear();
    tileMap.renderMap(*window);
    player->draw(*window);
    window->display();
  }

  return 0;
}