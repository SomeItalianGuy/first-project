#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "eventListener.hpp"
#include "util.hpp"
#include "vector.hpp"

#define DEFAULT_SPEED 8.F
#define PLAYER_NUMBER_OF_SIDES 3

class Player : public EventListener {
 private:
  // Private variables

  Vec2f m_movement;

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
  void move();
  void rotateTowards(Vec2f const& vec);
  void reset();
};

#endif