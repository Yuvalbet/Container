//Email: yuvali532@gmail.com
#ifndef ORDER_ITERATOR_HPP
#define ORDER_ITERATOR_HPP

#include <vector>
#include <stdexcept>
#include "MyContainer.hpp"

namespace Container {

template<typename T>
class MyContainer; 


/**
 * OrderIterator - A basic iterator that traverses the container
 * in the same order as the elements appear in the internal vector.
 */
template<typename T>
class OrderIterator {
private:
    const std::vector<T>& data;  // Reference to container's data
    size_t index; // Current index in the vector

public:
    /**
     * Constructor
     * @param begin - If true, initialize at beginning; otherwise, at end
     */
    OrderIterator(const MyContainer<T>& container, bool begin)
        : data(container.data), index(begin ? 0 : container.data.size()) {}

    // Equality operator
    bool operator==(const OrderIterator& other) const {
        return index == other.index;
    }

    // Inequality operator
    bool operator!=(const OrderIterator& other) const {
        return index != other.index;
    }

    // Dereference operator: returns the current element
    const T& operator*() const {
        if (index >= data.size()) {
            throw std::out_of_range("Dereferencing past-the-end iterator");
        }
        return data.at(index);
    }

    // Prefix increment (++it)
    OrderIterator& operator++() {
        if (index >= data.size()) {
            throw std::out_of_range("Increment past-the-end iterator");
        }
        ++index;
        return *this;
    }

    // Postfix increment (it++)
    OrderIterator operator++(int) {
        OrderIterator temp = *this;
        ++(*this);
        return temp;
    }
};

} 

#endif  
