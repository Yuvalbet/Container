#ifndef MY_CONTAINER_HPP
#define MY_CONTAINER_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

#include "AscendingOrderIterator.hpp"  // הוסיפי את זה כאן בסוף הקובץ

namespace Container {


template<typename T = int>
class AscendingOrderIterator; // קדימה (forward declaration)

template<typename T = int>
class DescendingOrderIterator;

template<typename T = int>
class SideCrossOrderIterator;

template<typename T = int>
class ReverseOrderIterator;

template<typename T = int>
class OrderIterator;

template<typename T = int>
class MiddleOutOrderIterator;


template<typename T = int>
class MyContainer {
private:
    std::vector<T> data;

public:
    MyContainer() = default;

    //Destructor
    ~MyContainer() = default;


    // הוספת איבר
    void add(const T& element) {
        data.push_back(element);
    }

    // הסרת כל ההופעות של איבר
    void remove(const T& element) {
    auto it = std::remove(data.begin(), data.end(), element);
    if (it == data.end()) {
        throw std::runtime_error("Item not found in container.");
    }
    data.erase(it, data.end());
    }


    // גודל הקונטיינר
    size_t size() const {
        return data.size();
    }

    // הדפסת הקונטיינר
    friend std::ostream& operator<<(std::ostream& os, const MyContainer& container) {
        os << "[";
        for (size_t i = 0; i < container.data.size(); ++i) {
            os << container.data[i];
            if (i + 1 < container.data.size()) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

     // חבר למחלקת האיטרטור
    friend class AscendingOrderIterator<T>;

    // גישה לאיטרטור מהקונטיינר
    AscendingOrderIterator<T> begin_ascending_order() const {
        return AscendingOrderIterator<T>(*this, true);
    }

    AscendingOrderIterator<T> end_ascending_order() const {
        return AscendingOrderIterator<T>(*this, false);
    }

    friend class DescendingOrderIterator<T>;

    DescendingOrderIterator<T> begin_descending_order() const {
        return DescendingOrderIterator<T>(*this, true);
    }

    DescendingOrderIterator<T> end_descending_order() const {
        return DescendingOrderIterator<T>(*this, false);
    }

    friend class SideCrossOrderIterator<T>;

    SideCrossOrderIterator<T> begin_side_cross_order() const {
        return SideCrossOrderIterator<T>(*this, true);
    }

    SideCrossOrderIterator<T> end_side_cross_order() const {
        return SideCrossOrderIterator<T>(*this, false);
    }

    friend class ReverseOrderIterator<T>;

    ReverseOrderIterator<T> begin_reverse_order() const {
        return ReverseOrderIterator<T>(*this, true);
    }

    ReverseOrderIterator<T> end_reverse_order() const {
        return ReverseOrderIterator<T>(*this, false);
    }

    friend class OrderIterator<T>;

    OrderIterator<T> begin_order() const {
        return OrderIterator<T>(*this, true);
    }

    OrderIterator<T> end_order() const {
        return OrderIterator<T>(*this, false);
    }

    friend class MiddleOutOrderIterator<T>;

    MiddleOutOrderIterator<T> begin_middle_out_order() const {
        return MiddleOutOrderIterator<T>(*this, true);
    }

    MiddleOutOrderIterator<T> end_middle_out_order() const {
        return MiddleOutOrderIterator<T>(*this, false);
    }





    // גישה לפנימיות עבור איטרטורים- לא בטוחה שצריך
    const std::vector<T>& getElements() const {
        return data;
    }



};

}  // namespace Container

#endif  // MY_CONTAINER_HPP
