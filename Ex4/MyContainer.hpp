// Email: yuvali532@gmail.com
#ifndef MY_CONTAINER_HPP
#define MY_CONTAINER_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

// Include all custom iterator headers
#include "AscendingOrderIterator.hpp"
#include "DescendingOrderIterator.hpp"
#include "SideCrossOrderIterator.hpp"
#include "ReverseOrderIterator.hpp"
#include "OrderIterator.hpp"
#include "MiddleOutOrderIterator.hpp"

namespace Container
{

    template <typename T = int>
    class MyContainer
    {
    private:
        std::vector<T> data;

    public:
        MyContainer() = default;

        // Destructor
        ~MyContainer() = default;

        // Adds an element to the container
        void add(const T &element)
        {
            data.push_back(element);
        }

        // Removes all occurrences of the element
        void remove(const T &element)
        {
            auto size = data.size();
            auto it = std::remove(data.begin(), data.end(), element);
            data.erase(it, data.end());

            if (data.size() == size)
            {
                throw std::runtime_error("Item not found in container.");
            }
            
        }

        // Returns number of elements in the container
        size_t size() const
        {
            return data.size();
        }

        // Overloaded stream operator to print container contents
        friend std::ostream &operator<<(std::ostream &os, const MyContainer &container)
        {
            os << "[";
            for (size_t i = 0; i < container.data.size(); ++i)
            {
                os << container.data[i];
                if (i + 1 < container.data.size())
                {
                    os << ", ";
                }
            }
            os << "]";
            return os;
        }

        // Declare iterator classes as friends to allow them access to private 'data'
        friend class AscendingOrderIterator<T>;
        friend class DescendingOrderIterator<T>;
        friend class SideCrossOrderIterator<T>;
        friend class ReverseOrderIterator<T>;
        friend class OrderIterator<T>;
        friend class MiddleOutOrderIterator<T>;

        // Ascending order iterators

        AscendingOrderIterator<T> begin_ascending_order() const
        {

            return AscendingOrderIterator<T>(*this, true);
        }

        AscendingOrderIterator<T> end_ascending_order() const
        {
            return AscendingOrderIterator<T>(*this, false);
        }

        // Descending order iterators

        DescendingOrderIterator<T> begin_descending_order() const
        {

            return DescendingOrderIterator<T>(*this, true);
        }

        DescendingOrderIterator<T> end_descending_order() const
        {
            return DescendingOrderIterator<T>(*this, false);
        }

        // Side-cross order iterators

        SideCrossOrderIterator<T> begin_side_cross_order() const
        {

            return SideCrossOrderIterator<T>(*this, true);
        }

        SideCrossOrderIterator<T> end_side_cross_order() const
        {
            return SideCrossOrderIterator<T>(*this, false);
        }

        // Reverse order iterators

        ReverseOrderIterator<T> begin_reverse_order() const
        {

            return ReverseOrderIterator<T>(*this, true);
        }

        ReverseOrderIterator<T> end_reverse_order() const
        {
            return ReverseOrderIterator<T>(*this, false);
        }

        // Regular order iterators

        OrderIterator<T> begin_order() const
        {

            return OrderIterator<T>(*this, true);
        }

        OrderIterator<T> end_order() const
        {
            return OrderIterator<T>(*this, false);
        }

        // Middle-out order iterators

        MiddleOutOrderIterator<T> begin_middle_out_order() const
        {

            return MiddleOutOrderIterator<T>(*this, true);
        }

        MiddleOutOrderIterator<T> end_middle_out_order() const
        {
            return MiddleOutOrderIterator<T>(*this, false);
        }
    };

}

#endif
