#ifndef REVERSE_ORDER_ITERATOR_HPP
#define REVERSE_ORDER_ITERATOR_HPP

#include <vector>
#include <algorithm>
#include "MyContainer.hpp"

namespace Container {

template<typename T>
class ReverseOrderIterator {
private:
    std::vector<T> reversed;
    size_t index;

public:
    ReverseOrderIterator(const MyContainer<T>& container, bool begin) {
        const std::vector<T>& original = container.getElements();
        reversed = std::vector<T>(original.rbegin(), original.rend());
        index = begin ? 0 : reversed.size();
    }

    bool operator!=(const ReverseOrderIterator& other) const {
        return index != other.index;
    }

    const T& operator*() const {
        return reversed.at(index);
    }

    ReverseOrderIterator& operator++() {
        ++index;
        return *this;
    }
};

} // namespace Container

#endif  // REVERSE_ORDER_ITERATOR_HPP
