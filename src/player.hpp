#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "eventListener.hpp"
#include "util.hpp"

class Player : public EventListener {
 private:
  // Static private

  static int numberOfSides;

  // Private variables

 public:
  // Constructor / Destructor

  Player();
  Player(float radius, sf::Color color);

  // Public methods

  // Getters

  sf::CircleShape getShape() const;
  sf::Vector2f getCenterCoords() const;

  // Setters

  void setPosition(sf::Vector2f position);
  void setOriginAtCenter();

  // Misc

  void move(sf::Vector2f movement);
  void rotate(float angle);
};

#endif