#ifndef EVENTLISTENER_HPP
#define EVENTLISTENER_HPP

#include <SFML/Graphics.hpp>

class EventListener {
 private:
  //  Nothing private
 public:
  sf::CircleShape* m_shape;
  virtual void consumeEvent(sf::Event&) = 0;

  // Constructor / Destructor

  EventListener();
  virtual ~EventListener();
};

#endif