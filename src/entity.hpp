#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
#include <cmath>


class Entity{
    private:
    // Static private

    static int numberOfSides;

    // Private variables

    sf::CircleShape m_shape;
    public:
    // Constructor / Destructor

    Entity();
    Entity(float radius, sf::Color color);

    // Public methods

    // Getters

    sf::CircleShape getShape() const;

    // Setters

    void setPosition(sf::Vector2f position);
    void move(sf::Vector2f movement);
    void rotate(float angle);
};

#endif