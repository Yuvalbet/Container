#ifndef DESCENDING_ORDER_ITERATOR_HPP
#define DESCENDING_ORDER_ITERATOR_HPP

#include <vector>
#include <algorithm>
#include "MyContainer.hpp"

namespace Container {

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

    // !=
    bool operator!=(const DescendingOrderIterator& other) const {
        return index != other.index;
    }

    // *it
    const T& operator*() const {
        return sorted.at(index);
    }

    // ++it
    DescendingOrderIterator& operator++() {
        ++index;
        return *this;
    }
};

} // namespace Container

#endif  // DESCENDING_ORDER_ITERATOR_HPP
