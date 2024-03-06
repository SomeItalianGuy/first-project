#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <array>
#include <type_traits>

namespace logic{

template <class T, std::size_t size>
class GenericVector{ 

    static_assert(size > 0);
    static_assert(std::is_arithmetic<T>::value);
    
    private:
    std::array<T, size> m_data;
    public:
    // Constructor / Destructor
    
    GenericVector();
    GenericVector(GenericVector const& other);

    // Public methods

    T modulus();

    // Operators

    GenericVector<T, size> operator+(GenericVector<T, size> const& other);
    GenericVector<T, size> operator-(GenericVector<T, size> const& other);
    template<class Scalar, class = std::enable_if_t<std::is_arithmetic<Scalar>>>
    GenericVector<T, size> operator*(GenericVector<T, size> const& other);

    template<class Scalar, class = std::enable_if_t<std::is_arithmetic<Scalar>>>
    GenericVector<T, size> operator/(GenericVector<T, size> const& other);

    GenericVector<T, size> operator=(GenericVector<T, size> const& other);
    void operator+=(GenericVector<T, size> const& other);
    void operator-=(GenericVector<T, size> const& other);
    bool operator==(GenericVector<T, size> const& other);
    bool operator!=(GenericVector<T, size> const& other);
};
}
#endif