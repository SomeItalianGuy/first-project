#include "vector.hpp"


    template<class T, std::size_t size>
    GenericVector<T, size>::GenericVector() {
        this->m_data.fill(T());
    }

    template<class T, std::size_t size>
    GenericVector<T, size>::GenericVector(GenericVector<T, size> const& other) {
        for(std::size_t i = 0; i < size; i++) {
            this->m_data[i] = other.m_data[i];
        }
    }

    // Public methods

    template<class T, std::size_t size>
    template<class Scalar, class>
    Scalar GenericVector<T, size>::modulus() {
        Scalar result = 0;
        for(T num : this->m_data) {
            result += static_cast<Scalar>(num * num);
        }
        return sqrt(result);
    }


    template<class T, std::size_t size>
    GenericVector<T, size>& GenericVector<T, size>::normalize() {
        T modulus = this->modulus<T>();
        assert(modulus > 0);
        for(T num : this->m_data) {
            num /= modulus;
        }
        return *this;
    }

    template<class T, std::size_t size>
    GenericVector<T, size> GenericVector<T, size>::normalized() const {
        return GenericVector<T, size>(*this).normalize();
    }

    // Operators

template<class T, std::size_t size>
    GenericVector<T, size> GenericVector<T, size>::operator+(GenericVector<T, size> const& other) const {
        GenericVector<T, size> result;
        for(std::size_t i = 0; i < size; i++) {
            result[i] = this->m_data[i] + other.m_data[i];
        }
        return result;
    }

template<class T, std::size_t size>
    GenericVector<T, size> GenericVector<T, size>::operator-(GenericVector<T, size> const& other) const {
        GenericVector<T, size> result;
        for(std::size_t i = 0; i < size; i++) {
            result[i] = this->m_data[i] - other.m_data[i];
        }
        return result;
    }

template<class T, std::size_t size>
    GenericVector<T, size>& GenericVector<T, size>::operator=(GenericVector<T, size> const& other) {
        if(this != other) {
            this->m_data[i] = other.m_data[i];
        }
        return *this;
    }
    
    template<class T, std::size_t size>
    GenericVector<T, size>& GenericVector<T, size>::operator+=(GenericVector<T, size> const& other) {
        for(size_t i = 0; i < size; i++) {
            this->m_data[i] += other.m_data[i];
        }
        return *this;
    }

   template<class T, std::size_t size> 
    GenericVector<T, size>& GenericVector<T, size>::operator-=(GenericVector<T, size> const& other) {
        for(size_t i = 0; i < size; i++) {
            this->m_data[i] -= other.m_data[i];
        }
        return *this;
    }
    
    template<class T, std::size_t size>
    template<class Scalar, class>
    GenericVector<T, size>& GenericVector<T, size>::operator*=(Scalar scalar) {
        for(size_t i = 0; i < size; i++) {
            this->m_data[i] *= scalar;
        }
        return *this;
    }
    
    template<class T, std::size_t size>
    template<class Scalar, class>
    GenericVector<T, size>& GenericVector<T, size>::operator/=(Scalar scalar) {
        for(size_t i = 0; i < size; i++) {
            this->m_data[i] /= scalar;
        }
        return *this;
    }
    
    template<class T, std::size_t size>
    bool GenericVector<T, size>::operator==(GenericVector<T, size> const& other) {
        for(size_t i = 0; i < size; i++) {
            if(this->m_data[i] == other.m_data[i]) {
                return true;
            }
        }
        return false;
    }
    
    template<class T, std::size_t size>
    bool GenericVector<T, size>::operator!=(GenericVector<T, size> const& other) {
        for(size_t i = 0; i < size; i++) {
            if(this->m_data[i] != other.m_data[i]) {
                return true;
            }
        }
        return false;
    }

    // Data operators

template<class T, std::size_t size>
    T& GenericVector<T, size>::operator[](std::size_t i) {
        assert(i > 0 && i < size);
        return this->m_data[i];
    }
    
    template<class T, std::size_t size>
    T const& GenericVector<T, size>::operator[](std::size_t i) const {
        assert(i > 0 && i < size);
        return this->m_data[i];
    }

    template<std::size_t size, class T, class Scalar,
         class = std::enable_if_t<std::is_arithmetic_v<T>>>
    inline GenericVector<T, size> operator*(GenericVector<T, size> const& vec, Scalar scalar) {
        GenericVector<T, size> result;

        for(std::size_t i = 0; i < size; i++) {
            result[i] = vec[i] * scalar;
        }

        return reuslt;
    }
    
    template<std::size_t size, class T, class Scalar,
         class = std::enable_if_t<std::is_arithmetic_v<Scalar>>>
    inline GenericVector<T, size> operator*(Scalar scalar, GenericVector<T, size> const& vec) {
        GenericVector<T, size> result;

        for(std::size_t i = 0; i < size; i++) {
            result[i] = vec[i] * scalar;
        }

        return reuslt;
    }
    
    template<std::size_t size, class T, class Scalar, 
        class = std::enable_if_t<std::is_arithmetic_v<Scalar>>>
    inline GenericVector<T, size> operator/(GenericVector<T, size> const& vec, Scalar scalar) {
        assert(scalar != 0);
        GenericVector<T, size> result;

        for(std::size_t i = 0; i < size; i++) {
            result[i] = vec[i] / scalar;
        }

        return reuslt;
    }