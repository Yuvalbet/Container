#include "MyContainer.hpp"
#include "AscendingOrderIterator.hpp"
#include "DescendingOrderIterator.hpp"
#include "SideCrossOrderIterator.hpp"
#include "ReverseOrderIterator.hpp"
#include "OrderIterator.hpp"
#include "MiddleOutOrderIterator.hpp"


using namespace Container;

int main() {
    MyContainer<int> c;
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);

    std::cout << "Ascending: ";
    for (auto it = c.begin_ascending_order(); it != c.end_ascending_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Descending: ";
    for (auto it = c.begin_descending_order(); it != c.end_descending_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "SideCross: ";
    for (auto it = c.begin_side_cross_order(); it != c.end_side_cross_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Reverse: ";
    for (auto it = c.begin_reverse_order(); it != c.end_reverse_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Order: ";
    for (auto it = c.begin_order(); it != c.end_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "MiddleOut: ";
    for (auto it = c.begin_middle_out_order(); it != c.end_middle_out_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;




}
