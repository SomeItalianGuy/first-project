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
    
};
}
#endif