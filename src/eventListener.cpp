#include "eventListener.hpp"

// Constructor / Destructor

EventListener::EventListener() { this->m_shape = nullptr; }

EventListener::~EventListener() { delete this->m_shape; }