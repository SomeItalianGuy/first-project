#include "eventListener.hpp"

// Constructor / Destructor

EventListener::EventListener() {}

EventListener::~EventListener() { delete this->m_shape; }