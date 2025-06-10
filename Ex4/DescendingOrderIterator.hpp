//Email: yuvali532@gmail.com
#ifndef DESCENDING_ORDER_ITERATOR_HPP
#define DESCENDING_ORDER_ITERATOR_HPP

#include <vector>
#include <algorithm>
#include "MyContainer.hpp"
#include <stdexcept>

namespace Container {

template<typename T>
class MyContainer;  // forward declaration

template<typename T>
class DescendingOrderIterator {
private:
    // Holds the container elements sorted in descending order
    std::vector<T> sorted;
    // Current iterator index
    size_t index;

public:
    // Constructor: initializes the sorted vector in descending order
    DescendingOrderIterator(const MyContainer<T>& container, bool begin) {
        sorted = container.data; // Access allowed via 'friend'

        if (!sorted.empty()) {
            std::sort(sorted.begin(), sorted.end(), std::greater<T>()); // Sort descending
            index = begin ? 0 : sorted.size();  // begin -> 0, end -> size
        } else {
            index = 0;  // Both begin and end will be at index 0 for empty container
        }
    }

    // Equality comparison
    bool operator==(const DescendingOrderIterator& other) const {
        return index == other.index;
    }

    
    // Inequality comparison
    bool operator!=(const DescendingOrderIterator& other) const {
        return index != other.index;
    }

    // Dereference operator: accesses current element
    const T& operator*() const {
        if (index >= sorted.size()) {
            throw std::out_of_range("Dereferencing past-the-end iterator");
        }
        return sorted.at(index);
    }

    
    // Prefix increment (++it)
    DescendingOrderIterator& operator++() {
        if (index >= sorted.size()) {
            throw std::out_of_range("Increment past-the-end iterator");
        }
        ++index;
        return *this;
    }

    // Postfix increment (it++)
    DescendingOrderIterator operator++(int) {
        DescendingOrderIterator temp = *this;
        ++(*this);
        return temp;
    }
};

} 

#endif 
