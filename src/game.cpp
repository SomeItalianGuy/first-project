#include "game.hpp"

// Private methods

/*
    Initailizes a fullscreen winow at 60 fps
*/
void Game::initWindow() {
  this->m_window = new sf::RenderWindow(sf::VideoMode(1920, 1080),
                                        "My first game", sf::Style::Fullscreen);

  this->m_window->setFramerateLimit(60);
}

/*
  Initializes player with:
  - Radius of 40
  - Blue color
*/
void Game::initPlayer() {
  this->m_player = new Player(40.F, sf::Color::Blue);
  this->m_player->setPosition({100.F, 100.F});
}

// Constructor / Destructor

/*
    Initializes:
    - Window
    -Player
*/
Game::Game() {
  this->initWindow();
  this->initPlayer();
}

/*
    Deallocate the memory for the window and player pointers
*/
Game::~Game() {
  delete this->m_window;
  delete this->m_player;
}

// Public methods

/*
    Tells if the window is open
*/
bool Game::isRunning() { return this->m_window->isOpen(); }

/*
    Polls events from window and passes them to every eventListener
*/
void Game::pollEvents() {
  while (this->m_window->pollEvent(this->m_event)) {
    if (this->m_event.key.code == sf::Keyboard::Escape) {
      this->m_window->close();
    } else {
      this->m_player->consumeEvent(this->m_event);
    }
  }
}

/*
  Moves the player and resets the movement vector
*/
void Game::updatePlayer() {
  this->m_player->move();
  this->m_player->reset();
}

/*
    This method:
    - polls the events
*/
void Game::update() {
  this->pollEvents();
  this->updatePlayer();
}

/*
    This method:
    - clears the frame
    - draws the player
    - displays
*/
void Game::render() {
  this->m_window->clear(sf::Color::Black);

  this->m_window->draw(*this->m_player->m_shape);

  this->m_window->display();
}