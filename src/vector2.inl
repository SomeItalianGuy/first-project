#include "vector.hpp"

// Contructor / Destructor

template <class T>
Vector2<T>::Vector2() : GenericVector<T, 2>() {}

template <class T>
Vector2<T>::Vector2(T x, T y) {
  this->x() = x;
  this->y() = y;
}

template <class T>
Vector2<T>::Vector2(GenericVector<T, 2> const& vec)
    : GenericVector<T, 2>(vec) {}

template <class T>
Vector2<T>::Vector2(sf::Vector2<T> const& sfVector) {
  this->x() = sfVector.x;
  this->y() = sfVector.y;
}

// Public methods

// Operators

template <class T>
Vector2<T>& Vector2<T>::operator=(sf::Vector2<T> const& sfVector) {
  this->x() = sfVector.x;
  this->y() = sfVector.y;
  return *this;
}

template <class T>
Vector2<T>& Vector2<T>::operator=(GenericVector<T, 2> const& vec) {
  this->x() = vec[0];
  this->y() = vec[1];
}

template <class T>
Vector2<T>& Vector2<T>::operator()(T x, T y) {
  this->x() = x;
  this->y() = y;
  return *this;
}

template <class T>
template <class Scalar, class>
Vector2<T>& Vector2<T>::operator*=(Scalar scalar) {
  this->x() *= scalar;
  this->y() *= scalar;

  return *this;
}

// Methods

template <class T>
T& Vector2<T>::x() {
  return (*this)[0];
}

template <class T>
T const& Vector2<T>::x() const {
  return (*this)[0];
}

template <class T>
T& Vector2<T>::y() {
  return (*this)[1];
}

template <class T>
T const& Vector2<T>::y() const {
  return (*this)[1];
}

template <class T>
sf::Vector2<T> Vector2<T>::getsfVector() const {
  return sf::Vector2<T>(this->x(), this->y());
}

template <class T>
float Vector2<T>::getAngleWithVector(Vector2<T> const& vec) {
  T xVariation = static_cast<double>(vec.x() - this->x());
  T yVariation = static_cast<double>(vec.y() - this->y());

  if (xVariation == 0 && yVariation < 0) {
    return 270;
  } else if (xVariation == 0 && yVariation >= 0) {
    return 90;
  }

  return static_cast<float>(util::RadsToDegs(atan(yVariation / xVariation)));
}