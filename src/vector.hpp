#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <array>
#include <cassert>
#include <cmath>
#include <type_traits>

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
  Vector2(T x, T y);
};

#endif