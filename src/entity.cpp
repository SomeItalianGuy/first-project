#include "entity.hpp"

// Static private variables

/*
    This variable makes sure that the entities are triangles
*/
int Entity::numberOfSides = 3;

// Constructor / Destructor

Entity::Entity() {}

/*
    Sets the radius of the entity as well as the color and the number of sides, which is 3 for every
    entity, the position is set by default at (0,0), it can be chan
*/
Entity::Entity(float radius, sf::Color color) {
    this->m_shape.setRadius(radius);
    this->m_shape.setPointCount(Entity::numberOfSides);
    this->m_shape.setPosition(0.F, 0.F);
    this->m_shape.setFillColor(color);
}

// Public methodds

// Getters

sf::CircleShape Entity::getShape() const {
    return this->m_shape; 
}

// Setters

void Entity::setPosition(sf::Vector2f position) {
    this->m_shape.setPosition(position);
}

void Entity::move(sf::Vector2f movement) {
    this->m_shape.move(movement);
}

void Entity::rotate(float angle) {
    this->m_shape.rotate(angle);
}