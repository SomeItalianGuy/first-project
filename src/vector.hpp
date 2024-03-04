#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <array>
#include <type_traits>

namespace logic{

template <class T, std::size_t size>
class Vector{ 

    static_assert(size > 0);
    static_assert(std::is_arithmetic<T>::value);
    
    private:
    std::array<T, size> m_data;
    public:
    // Constructor / Destructor
    
    Vector();
    Vector(Vector const& other);

    // Public methods


    // Operators

    Vector<T, size> operator+(Vector<T, size> const& other);
    Vector<T, size> operator-(Vector<T, size> const& other);
    template<class Scalar, class = std::enable_if_t<std::is_arithmetic<Scalar>>>
    Vector<T, size> operator*(Vector<T, size> const& other);

    template<class Scalar, class = std::enable_if_t<std::is_arithmetic<Scalar>>>
    Vector<T, size> operator/(Vector<T, size> const& other);

    Vector<T, size> operator=(Vector<T, size> const& other);
    void operator+=(Vector<T, size> const& other);
    void operator-=(Vector<T, size> const& other);
    bool operator==(Vector<T, size> const& other);
    bool operator!=(Vector<T, size> const& other);
};
}
#endif