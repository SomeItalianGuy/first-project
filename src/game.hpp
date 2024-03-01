#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

#include "entity.hpp"

class Game {
 private:
  // Private variables

  sf::RenderWindow* m_window;
  sf::Event m_event;
  Entity m_player;

  sf::Vector2f m_playerCoords;

  // Private methods

  void initWindow();
  void initPlayer();

  void evalKeyPressed(sf::Event& event);

 public:
  // Constructor / Destructor

  Game();

  ~Game();

  // Public methods

  bool isRunning();
  void pollEvents();
  void update();
  void render();
};

#endif