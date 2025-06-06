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
    std::vector<T> sorted;
    size_t index;

public:
    // בנאי - ממיין מהגדול לקטן
    DescendingOrderIterator(const MyContainer<T>& container, bool begin) {
        sorted = container.data; 
        std::sort(sorted.begin(), sorted.end(), std::greater<T>());
        index = begin ? 0 : sorted.size();
    }

    // השוואה ==
    bool operator==(const DescendingOrderIterator& other) const {
        return index == other.index;
    }

    // !=
    bool operator!=(const DescendingOrderIterator& other) const {
        return index != other.index;
    }

     // גישה לאיבר
    const T& operator*() const {
        if (index >= sorted.size()) {
            throw std::out_of_range("Dereferencing past-the-end iterator");
        }
        return sorted.at(index);
    }

    // ++it פריפיקסי
    DescendingOrderIterator& operator++() {
        if (index >= sorted.size()) {
            throw std::out_of_range("Increment past-the-end iterator");
        }
        ++index;
        return *this;
    }

    // it++ פוסטפיקסי
    DescendingOrderIterator operator++(int) {
        DescendingOrderIterator temp = *this;
        ++(*this);
        return temp;
    }
};

} // namespace Container

#endif  // DESCENDING_ORDER_ITERATOR_HPP
