#include "player.hpp"

// Static private variables

/*
    This variable makes sure that the entities are triangles
*/
int Player::numberOfSides = 3;

// Private methods

/*
  Method to set the origin for transformations at the center of the CircleShape,
  whatever the radius
*/
void Player::setOriginAtCenter() {
  float xOrigin, yOrigin;

  xOrigin = this->m_shape->getRadius();

  yOrigin = this->m_shape->getRadius();

  this->m_shape->setOrigin(xOrigin, yOrigin);
}

/*
  Accepted Keyboard Events:
  - W -> move up
  - A -> move right
  - S -> move down
  - D -> move right
*/
void Player::evalKeyPressed(sf::Keyboard::Key keyPressed) {
  // TODO Solve the continous movement issue
  switch (keyPressed) {
    case sf::Keyboard::A:
      this->m_shape->move(-DEFAULT_MOVEMENT, 0.F);
      break;
    case sf::Keyboard::W:
      this->m_shape->move(0.F, -DEFAULT_MOVEMENT);
      break;
    case sf::Keyboard::S:
      this->m_shape->move(0.F, DEFAULT_MOVEMENT);
      break;
    case ::sf::Keyboard::D:
      this->m_shape->move(DEFAULT_MOVEMENT, 0.F);
      break;
    default:
      break;
  }
}

// Constructor / Destructor

Player::Player() {}

/*
    Sets the radius of the entity as well as the color and the number of sides,
   which is 3 for every entity, the position is set by default at (0,0), it can
   be changed with the setPosition method
*/
Player::Player(float radius, sf::Color color) {
  this->m_shape = new sf::CircleShape(radius, Player::numberOfSides);
  this->m_shape->setPosition(0.F, 0.F);
  this->m_shape->setFillColor(color);
  this->setOriginAtCenter();
}

Player::~Player() {}

// Public methodds

// Getters

sf::CircleShape Player::getShape() const { return *this->m_shape; }

// Setters

void Player::setPosition(sf::Vector2f position) {
  this->m_shape->setPosition(position);
}

// Misc

/*
  Accepted Event types:
  - Press key -> see evalKeyPressed method for details
*/
void Player::consumeEvent(sf::Event& event) {
  switch (event.type) {
    case sf::Event::KeyPressed:
      this->evalKeyPressed(event.key.code);
      break;
    default:
      break;
  }
}
