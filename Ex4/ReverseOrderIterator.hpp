//Email: yuvali532@gmail.com
#ifndef REVERSE_ORDER_ITERATOR_HPP
#define REVERSE_ORDER_ITERATOR_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include "MyContainer.hpp"

namespace Container {

template<typename T>
class MyContainer;  // forward declaration

/**
 * ReverseOrderIterator - Iterates through the elements of the container 
 * in reverse order (from last to first as per original insertion order).
 */
template<typename T>
class ReverseOrderIterator {
private:
    std::vector<T> sorted; // Stores the reversed elements
    size_t index; // Current position in sorted vector

public:
     /**
     * Constructor
     * @param begin - If true, iterator starts at beginning; otherwise at end
     */
    ReverseOrderIterator(const MyContainer<T>& container, bool begin) {
        const std::vector<T>& original = container.data; // Access allowed via 'friend'
        sorted = std::vector<T>(original.rbegin(), original.rend());  // reverse copy
        index = begin ? 0 : sorted.size();
    }

    // Equality operator
    bool operator==(const ReverseOrderIterator& other) const {
        return index == other.index;
    }

    // Inequality operator
    bool operator!=(const ReverseOrderIterator& other) const {
        return index != other.index;
    }

    // Dereference operator: returns the current element
    const T& operator*() const {
        if (index >= sorted.size()) {
            throw std::out_of_range("Dereferencing past-the-end iterator");
        }
        return sorted.at(index);
    }

    // Prefix increment (++it)
    ReverseOrderIterator& operator++() {
        if (index >= sorted.size()) {
            throw std::out_of_range("Increment past-the-end iterator");
        }
        ++index;
        return *this;
    }

    // Postfix increment (it++)
    ReverseOrderIterator operator++(int) {
        ReverseOrderIterator temp = *this;
        ++(*this);
        return temp;
    }
};

}

#endif  
