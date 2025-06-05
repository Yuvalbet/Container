#ifndef SIDE_CROSS_ORDER_ITERATOR_HPP
#define SIDE_CROSS_ORDER_ITERATOR_HPP

#include <vector>
#include <algorithm>
#include "MyContainer.hpp"

namespace Container {

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

    bool operator!=(const SideCrossOrderIterator& other) const {
        return index != other.index;
    }

    const T& operator*() const {
        return crossOrder.at(index);
    }

    SideCrossOrderIterator& operator++() {
        ++index;
        return *this;
    }
};

} // namespace Container

#endif  // SIDE_CROSS_ORDER_ITERATOR_HPP
