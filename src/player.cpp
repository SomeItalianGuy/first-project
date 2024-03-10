#include "player.hpp"

// Static private variables

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
*/
void Player::evalKeyPressed(sf::Keyboard::Key keyPressed) {
  switch (keyPressed) {
    default:
      // Do nothing
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
  this->m_shape = new sf::CircleShape(radius, PLAYER_NUMBER_OF_SIDES);
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
      // Do nothing
      break;
  }
}

/*
  moves the player according to the keys:
  - W -> move up
  - A -> move right
  - S -> move down
  - D -> move right
*/
void Player::move() {
  bool moved = false;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    this->m_movement += Vec2f(-1.F, 0);
    moved = true;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    this->m_movement += Vec2f(1.F, 0);
    moved = true;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    this->m_movement += Vec2f(0, -1.F);
    moved = true;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    this->m_movement += Vec2f(0, 1.F);
    moved = true;
  }

  if (moved && this->m_movement.modulus<float>() != 0.F) {
    this->m_movement.normalize();
  } else {
    this->m_movement(0.F, 0.F);
  }

  this->m_shape->move((this->m_movement *= DEFAULT_SPEED).getsfVector());
}

void Player::rotateTowards(Vec2f const& vec) {
  // TODO Fix the rotation issues
  Vec2f position(this->m_shape->getPosition());
  float theta = position.getAngleWithVector(vec);
  this->m_shape->setRotation(theta);
}

/*
  Resets Movement vector to (0,0)
*/
void Player::reset() { this->m_movement(0.F, 0.F); }