#ifndef REVERSE_ORDER_ITERATOR_HPP
#define REVERSE_ORDER_ITERATOR_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include "MyContainer.hpp"

namespace Container {

template<typename T>
class MyContainer;  // forward declaration

template<typename T>
class ReverseOrderIterator {
private:
    std::vector<T> reversed;
    size_t index;

public:
    ReverseOrderIterator(const MyContainer<T>& container, bool begin) {
        const std::vector<T>& original = container.data;
        reversed = std::vector<T>(original.rbegin(), original.rend());
        index = begin ? 0 : reversed.size();
    }

    bool operator==(const ReverseOrderIterator& other) const {
        return index == other.index;
    }

    bool operator!=(const ReverseOrderIterator& other) const {
        return index != other.index;
    }

    const T& operator*() const {
        if (index >= reversed.size()) {
            throw std::out_of_range("Dereferencing past-the-end iterator");
        }
        return reversed.at(index);
    }

    // ++it פריפיקסי
    ReverseOrderIterator& operator++() {
        if (index >= reversed.size()) {
            throw std::out_of_range("Increment past-the-end iterator");
        }
        ++index;
        return *this;
    }

    // it++ פוסטפיקי
    ReverseOrderIterator operator++(int) {
        ReverseOrderIterator temp = *this;
        ++(*this);
        return temp;
    }
};

} // namespace Container

#endif  // REVERSE_ORDER_ITERATOR_HPP
