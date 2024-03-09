#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <SFML/Graphics.hpp>
#include <array>
#include <cassert>
#include <cmath>
#include <type_traits>

#include "util.hpp"

template <class T, std::size_t size>
class GenericVector {
  static_assert(size > 0);
  static_assert(std::is_arithmetic<T>::value);

 private:
  std::array<T, size> m_data;

 public:
  // Constructor / Destructor

  GenericVector();
  GenericVector(GenericVector<T, size> const& other);

  // Public methods

  template <class Scalar,
            class = std::enable_if_t<std::is_arithmetic<Scalar>::value>>
  Scalar modulus();

  GenericVector<T, size>& normalize();

  GenericVector<T, size> normalized() const;

  // Operators

  GenericVector<T, size> operator+(GenericVector<T, size> const& other) const;
  GenericVector<T, size> operator-(GenericVector<T, size> const& other) const;

  GenericVector<T, size>& operator=(GenericVector<T, size> const& other);
  GenericVector<T, size>& operator+=(GenericVector<T, size> const& other);
  GenericVector<T, size>& operator-=(GenericVector<T, size> const& other);
  template <class Scalar,
            class = std::enable_if_t<std::is_arithmetic_v<Scalar>>>
  GenericVector<T, size>& operator*=(Scalar scalar);
  template <class Scalar,
            class = std::enable_if_t<std::is_arithmetic_v<Scalar>>>
  GenericVector<T, size>& operator/=(Scalar scalar);
  bool operator==(GenericVector<T, size> const& other);
  bool operator!=(GenericVector<T, size> const& other);

  // Data operators

  T& operator[](std::size_t i);
  T const& operator[](std::size_t i) const;
};

template <std::size_t size, class T, class Scalar, class>
inline GenericVector<T, size> operator*(GenericVector<T, size> const& vec,
                                        Scalar scalar);
template <std::size_t size, class T, class Scalar, class>
inline GenericVector<T, size> operator*(Scalar scalar,
                                        GenericVector<T, size> const& vec);
template <std::size_t size, class T, class Scalar, class>
inline GenericVector<T, size> operator/(GenericVector<T, size> const& vec,
                                        Scalar scalar);

template <class T>
class Vector2 : public GenericVector<T, 2> {
 public:
  // Constructor / Destructor

  Vector2(T x, T y);
  Vector2(GenericVector<T, 2> const& vec);
  Vector2(sf::Vector2<T> const& sfVector);

  Vector2<T>& operator=(sf::Vector2<T> const& sfVector);
  Vector2<T>& operator=(GenericVector<T, 2> const& vec);
  Vector2<T>& operator()(T x, T y);

  T& x();
  T const& x() const;
  T& y();
  T const& y() const;

  sf::Vector2<T> getsfVector() const;

  float getAngleWithVector(Vector2<T> const& vec);
};

using Vec2f = Vector2<float>;
using Vec2i = Vector2<int>;
using Vec2d = Vector2<double>;
using Vec2u = Vector2<uint>;
#endif