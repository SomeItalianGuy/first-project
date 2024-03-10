#include "vector.hpp"

/*
    Standard constructor sets a vector full of the T type default value
*/
template <class T, std::size_t size>
GenericVector<T, size>::GenericVector() {
  this->m_data.fill(T());
}

/*
    Sets the values equal to another vector
*/
template <class T, std::size_t size>
GenericVector<T, size>::GenericVector(GenericVector<T, size> const& other) {
  for (std::size_t i = 0; i < size; i++) {
    this->m_data[i] = other.m_data[i];
  }
}

// Public methods

/*
    Returns the modulus of the vector
*/
template <class T, std::size_t size>
template <class Scalar, class>
Scalar GenericVector<T, size>::modulus() {
  Scalar result = 0;
  for (T num : this->m_data) {
    result += static_cast<Scalar>(num * num);
  }
  return sqrt(result);
}

/*
    Normalizes the vector, so that the modulus is equal to 1
*/
template <class T, std::size_t size>
GenericVector<T, size>& GenericVector<T, size>::normalize() {
  T modulus = this->modulus<T>();
  assert(modulus > 0);
  for (T num : this->m_data) {
    num /= modulus;
  }
  return *this;
}

/*
    Returns a new vector, which is the normalized version of the vector calling
   this method
*/
template <class T, std::size_t size>
GenericVector<T, size> GenericVector<T, size>::normalized() const {
  return GenericVector<T, size>(*this).normalize();
}

// Operators

/*
    Returns a new vector whose components are the sum of the single components
   of the two added vectors
*/
template <class T, std::size_t size>
GenericVector<T, size> GenericVector<T, size>::operator+(
    GenericVector<T, size> const& other) const {
  GenericVector<T, size> result;
  for (std::size_t i = 0; i < size; i++) {
    result[i] = this->m_data[i] + other.m_data[i];
  }
  return result;
}

/*
    Returns a new vector whose components are the subtraction of the single
   components of the two vectors
*/
template <class T, std::size_t size>
GenericVector<T, size> GenericVector<T, size>::operator-(
    GenericVector<T, size> const& other) const {
  GenericVector<T, size> result;
  for (std::size_t i = 0; i < size; i++) {
    result[i] = this->m_data[i] - other.m_data[i];
  }
  return result;
}

/*
    Assigns the values of the current vector equal to those of another vector
*/
template <class T, std::size_t size>
GenericVector<T, size>& GenericVector<T, size>::operator=(
    GenericVector<T, size> const& other) {
  for (std::size_t i = 0; i < size; i++) {
    this->m_data[i] = other.m_data[i];
  }

  return *this;
}

/*
    Performs the standard "+=" operator on each component of the vector
*/
template <class T, std::size_t size>
GenericVector<T, size>& GenericVector<T, size>::operator+=(
    GenericVector<T, size> const& other) {
  for (size_t i = 0; i < size; i++) {
    this->m_data[i] += other.m_data[i];
  }
  return *this;
}

/*
    Performs the standard "-=" operator on each component of the vector
*/
template <class T, std::size_t size>
GenericVector<T, size>& GenericVector<T, size>::operator-=(
    GenericVector<T, size> const& other) {
  for (size_t i = 0; i < size; i++) {
    this->m_data[i] -= other.m_data[i];
  }
  return *this;
}

/*
    Performs the standard "*=" operator on each component of the vector
*/
template <class T, std::size_t size>
template <class Scalar, class>
GenericVector<T, size>& GenericVector<T, size>::operator*=(Scalar scalar) {
  for (size_t i = 0; i < size; i++) {
    this->m_data[i] *= scalar;
  }
  return *this;
}

/*
    Performs the standard "/=" operator on each component of the vector
    Additional controls to check wether the scalar is equal to 0
*/
template <class T, std::size_t size>
template <class Scalar, class>
GenericVector<T, size>& GenericVector<T, size>::operator/=(Scalar scalar) {
  assert(scalar != 0);
  for (size_t i = 0; i < size; i++) {
    this->m_data[i] /= scalar;
  }
  return *this;
}

/*
    Checks wether all components of a vector are equal to those of the other
   vector
*/
template <class T, std::size_t size>
bool GenericVector<T, size>::operator==(GenericVector<T, size> const& other) {
  for (size_t i = 0; i < size; i++) {
    if (this->m_data[i] == other.m_data[i]) {
      return true;
    }
  }
  return false;
}

/*
    Checks wether at least one of the vector components is different from the
   other vector
*/
template <class T, std::size_t size>
bool GenericVector<T, size>::operator!=(GenericVector<T, size> const& other) {
  for (size_t i = 0; i < size; i++) {
    if (this->m_data[i] != other.m_data[i]) {
      return true;
    }
  }
  return false;
}

// Data operators

/*
    Returns a reference to the element at the i-th position, asserts wether i is
   acceptable as a value, i.e. wether i is greater the 0 and lower than the
   vector's size
*/
template <class T, std::size_t size>
T& GenericVector<T, size>::operator[](std::size_t i) {
  assert(i >= 0 && i < size);
  return this->m_data[i];
}

/*
    Returns a const reference to the element at the i-th position, asserts
   wether i is acceptable as a value, i.e. wether i is greater the 0 and lower
   than the vector's size
*/
template <class T, std::size_t size>
T const& GenericVector<T, size>::operator[](std::size_t i) const {
  assert(i >= 0 && i < size);
  return this->m_data[i];
}

/*
    Multiplies each element of the vector by the scalar given
*/
template <std::size_t size, class T, class Scalar,
          class = std::enable_if_t<std::is_arithmetic_v<T>>>
inline GenericVector<T, size> operator*(GenericVector<T, size> const& vec,
                                        Scalar scalar) {
  GenericVector<T, size> result;

  for (std::size_t i = 0; i < size; i++) {
    result[i] = vec[i] * scalar;
  }

  return result;
}

/*
    Multiplies each element of the vector by the scalar given
*/
template <std::size_t size, class T, class Scalar,
          class = std::enable_if_t<std::is_arithmetic_v<Scalar>>>
inline GenericVector<T, size> operator*(Scalar scalar,
                                        GenericVector<T, size> const& vec) {
  GenericVector<T, size> result;

  for (std::size_t i = 0; i < size; i++) {
    result[i] = vec[i] * scalar;
  }

  return result;
}

/*
    Divides each element by the scalar given and checks wether the scalar is
   different from 0
*/
template <std::size_t size, class T, class Scalar,
          class = std::enable_if_t<std::is_arithmetic_v<Scalar>>>
inline GenericVector<T, size> operator/(GenericVector<T, size> const& vec,
                                        Scalar scalar) {
  assert(scalar != 0);
  GenericVector<T, size> result;

  for (std::size_t i = 0; i < size; i++) {
    result[i] = vec[i] / scalar;
  }

  return result;
}