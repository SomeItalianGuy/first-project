#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

#include "player.hpp"

class Game {
 private:
  // Private variables

  sf::RenderWindow* m_window;
  sf::Event m_event;
  Player* m_player;

  // Private methods

  void initWindow();
  void initPlayer();

 public:
  // Constructor / Destructor

  Game();

  ~Game();

  // Public methods

  bool isRunning();
  void pollEvents();
  void updatePlayer();
  void update();
  void render();
};

#endif