#ifndef MIDDLE_OUT_ORDER_ITERATOR_HPP
#define MIDDLE_OUT_ORDER_ITERATOR_HPP

#include <vector>
#include <stdexcept>
#include "MyContainer.hpp"

namespace Container {

template<typename T>
class MyContainer;  // forward declaration

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
        if (n % 2 == 0) {
            mid = mid - 1;  // התחלה מהאמצעי השמאלי במקרה זוגי
        }
        middleOut.push_back(original[mid]);

        int left = mid - 1;
        int right = mid + 1;

        int step = 0;
        while (left >= 0 || right < n) {
            if (n % 2 == 1) {
                // אי זוגי: סדר שמאל - ימין - שמאל - ימין ...
                if (step % 2 == 0) {  // אפילו - שמאל
                    if (left >= 0) {
                        middleOut.push_back(original[left]);
                        --left;
                    } else if (right < n) {
                        middleOut.push_back(original[right]);
                        ++right;
                    }
                } else {  // אי-זוגי - ימין
                    if (right < n) {
                        middleOut.push_back(original[right]);
                        ++right;
                    } else if (left >= 0) {
                        middleOut.push_back(original[left]);
                        --left;
                    }
                }
            } else {
                // זוגי: סדר ימין - שמאל - ימין - שמאל ...
                if (step % 2 == 0) {  // אפילו - ימין
                    if (right < n) {
                        middleOut.push_back(original[right]);
                        ++right;
                    } else if (left >= 0) {
                        middleOut.push_back(original[left]);
                        --left;
                    }
                } else {  // אי-זוגי - שמאל
                    if (left >= 0) {
                        middleOut.push_back(original[left]);
                        --left;
                    } else if (right < n) {
                        middleOut.push_back(original[right]);
                        ++right;
                    }
                }
            }
            ++step;
        }

        index = begin ? 0 : middleOut.size();
    }


    bool operator==(const MiddleOutOrderIterator& other) const {
        return index == other.index;
    }

    bool operator!=(const MiddleOutOrderIterator& other) const {
        return index != other.index;
    }

    const T& operator*() const {
        if (index >= middleOut.size()) {
            throw std::out_of_range("Dereferencing past-the-end iterator");
        }
        return middleOut.at(index);
    }

    // ++it פריפיקסי
    MiddleOutOrderIterator& operator++() {
        if (index >= middleOut.size()) {
            throw std::out_of_range("Increment past-the-end iterator");
        }
        ++index;
        return *this;
    }

    // it++ פוסטפיקסי
    MiddleOutOrderIterator operator++(int) {
        MiddleOutOrderIterator temp = *this;
        ++(*this);
        return temp;
    }
};

} // namespace Container

#endif  // MIDDLE_OUT_ORDER_ITERATOR_HPP
