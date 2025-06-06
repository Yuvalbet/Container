#ifndef ORDER_ITERATOR_HPP
#define ORDER_ITERATOR_HPP

#include <vector>
#include <stdexcept>
#include "MyContainer.hpp"

namespace Container {

template<typename T>
class MyContainer;  // forward declaration

template<typename T>
class OrderIterator {
private:
    const std::vector<T>& data;
    size_t index;

public:
    OrderIterator(const MyContainer<T>& container, bool begin)
        : data(container.data), index(begin ? 0 : container.data.size()) {}

    bool operator==(const OrderIterator& other) const {
        return index == other.index;
    }

    bool operator!=(const OrderIterator& other) const {
        return index != other.index;
    }

    const T& operator*() const {
        if (index >= data.size()) {
            throw std::out_of_range("Dereferencing past-the-end iterator");
        }
        return data.at(index);
    }

    // ++it פריפיקסי
    OrderIterator& operator++() {
        if (index >= data.size()) {
            throw std::out_of_range("Increment past-the-end iterator");
        }
        ++index;
        return *this;
    }

    // it++ פוסטפיקי
    OrderIterator operator++(int) {
        OrderIterator temp = *this;
        ++(*this);
        return temp;
    }
};

} // namespace Container

#endif  // ORDER_ITERATOR_HPP
