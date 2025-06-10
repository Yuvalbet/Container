//Email: yuvali532@gmail.com
#ifndef SIDE_CROSS_ORDER_ITERATOR_HPP
#define SIDE_CROSS_ORDER_ITERATOR_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include "MyContainer.hpp"

namespace Container {

template<typename T>
class MyContainer;  // forward declaration

/**
 * SideCrossOrderIterator - Iterates over the container in a "zig-zag" pattern:
 * smallest, largest, second smallest, second largest, and so on.
 */
template<typename T>
class SideCrossOrderIterator {
private:
    std::vector<T> sorted; // Stores the sorted data from the container
    size_t index; // Current iterator position

public:
    /**
     * Constructor
     * @param begin - If true, start at beginning; otherwise at the end
     */
    SideCrossOrderIterator(const MyContainer<T>& container, bool begin) {
        std::vector<T> temp = container.data; // Access allowed via 'friend'

        if (temp.empty()) {
            index = 0;  
            return;
        }

        std::sort(temp.begin(), temp.end());

        size_t left = 0;
        size_t right = temp.size() - 1;

        while (left < right) {
            sorted.push_back(temp[left]);
            sorted.push_back(temp[right]);
            ++left;
            --right;
        }

        // Add the middle element (only if size is odd)
        if (left == right) {
            sorted.push_back(temp[left]);
        }

        index = begin ? 0 : sorted.size();
    }

    // Equality operator
    bool operator==(const SideCrossOrderIterator& other) const {
        return index == other.index;
    }

    // Inequality operator
    bool operator!=(const SideCrossOrderIterator& other) const {
        return index != other.index;
    }

    // Dereference operator: returns the current element
    const T& operator*() const {
        if (sorted.empty()) {
            throw std::out_of_range("Dereferencing iterator on empty container");
        }
        if (index >= sorted.size()) {
            throw std::out_of_range("Dereferencing past-the-end iterator");
        }
        return sorted.at(index);
    }

    // Prefix increment (++it)
    SideCrossOrderIterator& operator++() {
        if (index >= sorted.size()) {
            throw std::out_of_range("Increment past-the-end iterator");
        }
        ++index;
        return *this;
    }

    // Postfix increment (it++)
    SideCrossOrderIterator operator++(int) {
        SideCrossOrderIterator temp = *this;
        ++(*this);
        return temp;
    }
};

} 

#endif  
