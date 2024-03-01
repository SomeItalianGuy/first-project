#include "entity.hpp"

// Static private variables

/*
    This variable makes sure that the entities are triangles
*/
int Entity::numberOfSides = 3;

// Constructor / Destructor

Entity::Entity() {}

/*
    Sets the radius of the entity as well as the color and the number of sides,
   which is 3 for every entity, the position is set by default at (0,0), it can
   be chan
*/
Entity::Entity(float radius, sf::Color color) {
  this->m_shape.setRadius(radius);
  this->m_shape.setPointCount(Entity::numberOfSides);
  this->m_shape.setPosition(0.F, 0.F);
  this->m_shape.setFillColor(color);
}

// Public methodds

// Getters

sf::CircleShape Entity::getShape() const { return this->m_shape; }

/*
    Calculates the coordinates of the object's center
*/
sf::Vector2f Entity::getCenterCoords() const {
  float yCenterCoords, xCenterCoords;

  xCenterCoords = this->m_shape.getPosition().x +
                  this->m_shape.getRadius() * 1.4 *
                      cos(M_PI_4 - (this->m_shape.getRotation() / 180 * M_PI));

  yCenterCoords = this->m_shape.getPosition().y +
                  this->m_shape.getRadius() * 1.4 *
                      sin(M_PI_4 - (this->m_shape.getRotation() / 180 * M_PI));

  return {xCenterCoords, yCenterCoords};
}

// Setters

void Entity::setPosition(sf::Vector2f position) {
  this->m_shape.setPosition(position);
}

void Entity::move(sf::Vector2f movement) { this->m_shape.move(movement); }

void Entity::rotate(float angle) {
  //   sf::Vector2f coordsBeforeRotation = this->getCenterCoords();

  this->m_shape.rotate(angle);

  //   sf::Vector2f coordsAfterRotation = this->getCenterCoords();

  //   this->m_shape.move(coordsBeforeRotation.x - coordsAfterRotation.x,
  //                      coordsBeforeRotation.y - coordsAfterRotation.y);
}