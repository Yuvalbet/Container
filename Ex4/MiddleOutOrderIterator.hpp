//Email: yuvali532@gmail.com
#ifndef MIDDLE_OUT_ORDER_ITERATOR_HPP
#define MIDDLE_OUT_ORDER_ITERATOR_HPP

#include <vector>
#include <stdexcept>
#include "MyContainer.hpp"

namespace Container {

template<typename T>
class MyContainer;  // forward declaration

/**
 * MiddleOutOrderIterator
 * Iterates from the middle of the container outward:
 * - Odd-sized: middle, left, right, left, right...
 * - Even-sized: - left-middle, right-middle, left-1, right+1...
 */
template<typename T>
class MiddleOutOrderIterator {
private:
    // Holds the reordered elements
    std::vector<T> sorted;
    // Current index in iteration
    size_t index;

public:
    /*
     * Constructor: Initializes the iterator with the middle-out order.
     * Strategy:
     * - Start from the middle of the container.
     * - Then alternate outward to the left and right.
     * - For even-length containers, begin with the left-middle.
     *   For odd-length containers, begin with the exact middle.
     */
    MiddleOutOrderIterator(const MyContainer<T>& container, bool begin) {
        const std::vector<T>& original = container.data; // Access allowed via 'friend'
        int n = static_cast<int>(original.size());
        if (n == 0) {
            index = 0;
            return;
        }
        
        int mid = n / 2;
        if (n % 2 == 0) {
            mid = mid - 1;  // For even-sized containers, start at the left-middle
        }
        sorted.push_back(original[mid]);

        int left = mid - 1;
        int right = mid + 1;

        int step = 0;
        while (left >= 0 || right < n) {
            if (n % 2 == 1) {
                // Odd-sized: alternate left-right
                if (step % 2 == 0) {  
                    if (left >= 0) {
                        sorted.push_back(original[left]);
                        --left;
                    } else if (right < n) {
                        sorted.push_back(original[right]);
                        ++right;
                    }
                } else {  
                    if (right < n) {
                        sorted.push_back(original[right]);
                        ++right;
                    } else if (left >= 0) {
                        sorted.push_back(original[left]);
                        --left;
                    }
                }
            } else {
                // Even-sized: alternate right-left
                if (step % 2 == 0) {  
                    if (right < n) {
                        sorted.push_back(original[right]);
                        ++right;
                    } else if (left >= 0) {
                        sorted.push_back(original[left]);
                        --left;
                    }
                } else {  
                    if (left >= 0) {
                        sorted.push_back(original[left]);
                        --left;
                    } else if (right < n) {
                        sorted.push_back(original[right]);
                        ++right;
                    }
                }
            }
            ++step;
        }

        index = begin ? 0 : sorted.size();
    }

    // Equality operator
    bool operator==(const MiddleOutOrderIterator& other) const {
        return index == other.index;
    }

    // Inequality operator
    bool operator!=(const MiddleOutOrderIterator& other) const {
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
    MiddleOutOrderIterator& operator++() {
        if (index >= sorted.size()) {
            throw std::out_of_range("Increment past-the-end iterator");
        }
        ++index;
        return *this;
    }

    // Postfix increment (it++)
    MiddleOutOrderIterator operator++(int) {
        MiddleOutOrderIterator temp = *this;
        ++(*this);
        return temp;
    }
};

} 

#endif  
