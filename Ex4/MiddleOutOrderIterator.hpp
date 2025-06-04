#ifndef MIDDLE_OUT_ORDER_ITERATOR_HPP
#define MIDDLE_OUT_ORDER_ITERATOR_HPP

#include <vector>
#include "MyContainer.hpp"

namespace Container {

template<typename T>
class MiddleOutOrderIterator {
private:
    std::vector<T> middleOut;
    size_t index;

public:
    MiddleOutOrderIterator(const MyContainer<T>& container, bool begin) {
        const std::vector<T>& original = container.data; // ✅ גישה ישירה עם friend
        int n = static_cast<int>(original.size());
        if (n == 0) {
            index = 0;
            return;
        }

        int mid = n / 2;
        middleOut.push_back(original[mid]);

        int left = mid - 1;
        int right = mid + 1;

        while (left >= 0 || right < n) {
            if (left >= 0) {
                middleOut.push_back(original[left]);
                --left;
            }
            if (right < n) {
                middleOut.push_back(original[right]);
                ++right;
            }
        }

        index = begin ? 0 : middleOut.size();
    }

    bool operator!=(const MiddleOutOrderIterator& other) const {
        return index != other.index;
    }

    const T& operator*() const {
        return middleOut.at(index);
    }

    MiddleOutOrderIterator& operator++() {
        ++index;
        return *this;
    }
};

} // namespace Container

#endif  // MIDDLE_OUT_ORDER_ITERATOR_HPP
