#ifndef ORDER_ITERATOR_HPP
#define ORDER_ITERATOR_HPP

#include <vector>
#include "MyContainer.hpp"

namespace Container {

template<typename T>
class OrderIterator {
private:
    const std::vector<T>& data;
    size_t index;

public:
    OrderIterator(const MyContainer<T>& container, bool begin)
        : data(container.data), index(begin ? 0 : container.data.size()) {}

    bool operator!=(const OrderIterator& other) const {
        return index != other.index;
    }

    const T& operator*() const {
        return data.at(index);
    }

    OrderIterator& operator++() {
        ++index;
        return *this;
    }
};

} // namespace Container

#endif  // ORDER_ITERATOR_HPP
