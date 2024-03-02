#include "player.hpp"

// Static private variables

/*
    This variable makes sure that the entities are triangles
*/
int Player::numberOfSides = 3;

// Constructor / Destructor

Player::Player() {}

/*
    Sets the radius of the entity as well as the color and the number of sides,
   which is 3 for every entity, the position is set by default at (0,0), it can
   be changed with the move method
*/
Player::Player(float radius, sf::Color color) {
  this->m_shape->setRadius(radius);
  this->m_shape->setPointCount(Player::numberOfSides);
  this->m_shape->setPosition(0.F, 0.F);
  this->m_shape->setFillColor(color);
}

// Public methodds

// Getters

sf::CircleShape Player::getShape() const { return *this->m_shape; }

// Setters

void Player::setPosition(sf::Vector2f position) {
  this->m_shape->setPosition(position);
}

void Player::setOriginAtCenter() {
  float xOrigin, yOrigin;

  xOrigin = this->m_shape->getRadius();

  yOrigin = this->m_shape->getRadius();

  this->m_shape->setOrigin(xOrigin, yOrigin);
}
