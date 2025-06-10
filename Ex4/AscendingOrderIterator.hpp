//Email: yuvali532@gmail.com
#ifndef ASCENDING_ORDER_ITERATOR_HPP
#define ASCENDING_ORDER_ITERATOR_HPP

#include "MyContainer.hpp"
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace Container {


template<typename T>
class MyContainer;  // forward declaration

template<typename T> 
class AscendingOrderIterator {
private:
    // Stores the sorted data from the container
    std::vector<T> sorted;
    // Current position of the iterator
    size_t index;

public:
    // Constructor
    AscendingOrderIterator(const MyContainer<T>& container, bool begin) {
    sorted = container.data;

        if (!sorted.empty()) {
            std::sort(sorted.begin(), sorted.end());
            index = begin ? 0 : sorted.size();  // end iterator points to past-the-end
        } else {
            index = 0; // for both begin and end in an empty container
        }
    }


    // Equality comparison
    bool operator==(const AscendingOrderIterator& other) const {
        return index == other.index;
    }

    // Inequality comparison
    bool operator!=(const AscendingOrderIterator& other) const {
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
    AscendingOrderIterator& operator++() {
        if (index >= sorted.size()) {
            throw std::out_of_range("Increment past-the-end iterator");
        }
        ++index;
        return *this;
    }

    // Postfix increment (it++)
    AscendingOrderIterator operator++(int) {
        AscendingOrderIterator temp = *this;
        ++(*this);
        return temp;
    }
};

} 

#endif  
