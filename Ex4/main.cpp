#include "MyContainer.hpp"
#include "AscendingOrderIterator.hpp"
#include "DescendingOrderIterator.hpp"
#include "SideCrossOrderIterator.hpp"
#include "ReverseOrderIterator.hpp"
#include "OrderIterator.hpp"
#include "MiddleOutOrderIterator.hpp"
#include <string>

using namespace Container;

int main() {
    // בדיקת קונטיינר עם int
    MyContainer<int> intContainer;
    intContainer.add(7);
    intContainer.add(15);
    intContainer.add(6);
    intContainer.add(1);
    intContainer.add(2);
    intContainer.add(10);  

    std::cout << "Testing with integers (int):\n";

    std::cout << "Ascending: ";
    for (auto it = intContainer.begin_ascending_order(); it != intContainer.end_ascending_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Descending: ";
    for (auto it = intContainer.begin_descending_order(); it != intContainer.end_descending_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "SideCross: ";
    for (auto it = intContainer.begin_side_cross_order(); it != intContainer.end_side_cross_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Reverse: ";
    for (auto it = intContainer.begin_reverse_order(); it != intContainer.end_reverse_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Order: ";
    for (auto it = intContainer.begin_order(); it != intContainer.end_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "MiddleOut: ";
    for (auto it = intContainer.begin_middle_out_order(); it != intContainer.end_middle_out_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    // בדיקת קונטיינר עם double
    MyContainer<double> doubleContainer;
    doubleContainer.add(3.14);
    doubleContainer.add(1.618);
    doubleContainer.add(2.718);
    doubleContainer.add(0.5772);
    doubleContainer.add(1.414);

    std::cout << "\nTesting with doubles (double):\n";

    std::cout << "Ascending: ";
    for (auto it = doubleContainer.begin_ascending_order(); it != doubleContainer.end_ascending_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Descending: ";
    for (auto it = doubleContainer.begin_descending_order(); it != doubleContainer.end_descending_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "SideCross: ";
    for (auto it = doubleContainer.begin_side_cross_order(); it != doubleContainer.end_side_cross_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Reverse: ";
    for (auto it = doubleContainer.begin_reverse_order(); it != doubleContainer.end_reverse_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Order: ";
    for (auto it = doubleContainer.begin_order(); it != doubleContainer.end_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "MiddleOut: ";
    for (auto it = doubleContainer.begin_middle_out_order(); it != doubleContainer.end_middle_out_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;


    // בדיקת קונטיינר עם string
    MyContainer<std::string> stringContainer;
    stringContainer.add("apple");
    stringContainer.add("banana");
    stringContainer.add("kiwi");
    stringContainer.add("mango");

    std::cout << "\nTesting with strings (string):\n";

    std::cout << "Ascending: ";
    for (auto it = stringContainer.begin_ascending_order(); it != stringContainer.end_ascending_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Descending: ";
    for (auto it = stringContainer.begin_descending_order(); it != stringContainer.end_descending_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "SideCross: ";
    for (auto it = stringContainer.begin_side_cross_order(); it != stringContainer.end_side_cross_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Reverse: ";
    for (auto it = stringContainer.begin_reverse_order(); it != stringContainer.end_reverse_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Order: ";
    for (auto it = stringContainer.begin_order(); it != stringContainer.end_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "MiddleOut: ";
    for (auto it = stringContainer.begin_middle_out_order(); it != stringContainer.end_middle_out_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;


}
