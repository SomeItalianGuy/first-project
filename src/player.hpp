#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "eventListener.hpp"
#include "util.hpp"
#include "vector.hpp"

#define DEFAULT_MOVEMENT 8.F

class Player : public EventListener {
 private:
  // Static private

  static int numberOfSides;

  // Private methods

  void setOriginAtCenter();
  void evalKeyPressed(sf::Keyboard::Key keyPressed);

 public:
  // Constructor / Destructor

  Player();
  Player(float radius, sf::Color color);
  ~Player();

  // Public methods

  // Getters

  sf::CircleShape getShape() const;

  // Setters

  void setPosition(sf::Vector2f position);

  // Misc

  void consumeEvent(sf::Event& event) override;
};

#endif