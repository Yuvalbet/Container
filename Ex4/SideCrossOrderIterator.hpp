#ifndef SIDE_CROSS_ORDER_ITERATOR_HPP
#define SIDE_CROSS_ORDER_ITERATOR_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include "MyContainer.hpp"

namespace Container {

template<typename T>
class MyContainer;  // forward declaration

template<typename T>
class SideCrossOrderIterator {
private:
    std::vector<T> crossOrder;
    size_t index;

public:
    SideCrossOrderIterator(const MyContainer<T>& container, bool begin) {
        std::vector<T> sorted = container.data; // ✅ גישה ישירה עם friend
        std::sort(sorted.begin(), sorted.end());

        size_t left = 0;
        size_t right = sorted.size() - 1;
        while (left < right) {
        crossOrder.push_back(sorted[left]);
        crossOrder.push_back(sorted[right]);
        ++left;
        --right;
    }
    if (left == right) {
        crossOrder.push_back(sorted[left]);
    }


        index = begin ? 0 : crossOrder.size();
    }

    bool operator==(const SideCrossOrderIterator& other) const {
        return index == other.index;
    }

    bool operator!=(const SideCrossOrderIterator& other) const {
        return index != other.index;
    }

    
    const T& operator*() const {
        if (crossOrder.empty()) {
            throw std::out_of_range("Dereferencing iterator on empty container");
        }
        if (index >= crossOrder.size()) {
            throw std::out_of_range("Dereferencing past-the-end iterator");
        }
        return crossOrder.at(index);
    }

    // ++it פריפיקס
    SideCrossOrderIterator& operator++() {
        if (index >= crossOrder.size()) {
            throw std::out_of_range("Increment past-the-end iterator");
        }
        ++index;
        return *this;
    }

    // it++ פוסטפיק
    SideCrossOrderIterator operator++(int) {
        SideCrossOrderIterator temp = *this;
        ++(*this);
        return temp;
    }
};

} // namespace Container

#endif  // SIDE_CROSS_ORDER_ITERATOR_HPP
