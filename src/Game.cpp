#include "../include/Game.hpp"
#include "Game.hpp"

Game::Game() {
  window = new sf::RenderWindow(sf::VideoMode(600, 600), "Pacman");
  player = new Player();
  window->setFramerateLimit(60);
}

void Game::updatePlayerDirection() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    player->setDirection(Player::direction::up);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    player->setDirection(Player::direction::down);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    player->setDirection(Player::direction::left);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    player->setDirection(Player::direction::right);
  }

  player->move();
}

int Game::gameLoop() {
  while (window->isOpen()) {
    sf::Event event;
    while (window->pollEvent(event)) {
      // eventos de teclado...
      if (event.type == sf::Event::Closed) {
        window->close();
      }
    }
    // Actualizacines...
    updatePlayerDirection();
    // dibujado...
    window->clear();
    player->draw(*window);
    window->display();
  }

  return 0;
}