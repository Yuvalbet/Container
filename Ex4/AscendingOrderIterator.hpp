#ifndef ASCENDING_ORDER_ITERATOR_HPP
#define ASCENDING_ORDER_ITERATOR_HPP

#include "MyContainer.hpp"
#include <vector>
#include <algorithm>

namespace Container {


template<typename T>
class MyContainer;  // forward declaration

template<typename T> 
class AscendingOrderIterator {
private:
    std::vector<T> sorted;
    size_t index;

public:
    AscendingOrderIterator(const MyContainer<T>& container, bool begin) {
        sorted = container.data;  // נגיש כי מחלקת חבר
        std::sort(sorted.begin(), sorted.end());
        index = begin ? 0 : sorted.size();
    }

    // השוואה
    bool operator!=(const AscendingOrderIterator& other) const {
        return index != other.index;
    }

    // גישה לאיבר
    const T& operator*() const {
        return sorted.at(index);
    }

    // ++ (התקדמות באיטרציה)
    AscendingOrderIterator& operator++() {
        ++index;
        return *this;
    }
};

} // namespace Container

#endif  // ASCENDING_ORDER_ITERATOR_HPP
