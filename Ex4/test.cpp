#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace Container;

// טסטים על אינטגרים
TEST_CASE("Test integers") {
    std::cout << "Testing with integers (int):\n";

    MyContainer<int> c;
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);
    c.add(10);  // הוספת איבר נוסף כדי לבדוק את MiddleOut בסדר זוגי

    // Verify size
    CHECK(c.size() == 6);  // 6 items in the container

    // Test adding duplicate
    c.add(7);  // Adding duplicate of 7
    CHECK(c.size() == 7);  // Should be 7 items now

    // Test remove
    c.remove(6);
    CHECK(c.size() == 6);  // 6 items after removal

    // Test removing an element that doesn't exist
    try {
        c.remove(100);  // should throw exception
        CHECK(false);  // should not reach here
    } catch (const std::runtime_error& e) {
        // Expected exception
    }

    // Test negative numbers
    c.add(-5);
    c.add(-1);
    CHECK(c.size() == 8);  // 8 items after adding negative numbers

    // Test large numbers
    c.add(1000000);  // large positive number
    c.add(-1000000); // large negative number
    CHECK(c.size() == 10);  // 10 items after adding large numbers

    // Ascending Order Iterator
    std::vector<int> expected_ascending = { -1000000, -5, -1, 1, 2, 7, 7, 10, 15, 1000000};
    std::vector<int> result_ascending;
    for (auto it = c.begin_ascending_order(); it != c.end_ascending_order(); ++it) {
        result_ascending.push_back(*it);
    }
    
    CHECK(result_ascending == expected_ascending);

    // Descending Order Iterator
    std::vector<int> expected_descending = { 1000000, 15, 10, 7, 7, 2, 1, -1, -5, -1000000 };
    std::vector<int> result_descending;
    for (auto it = c.begin_descending_order(); it != c.end_descending_order(); ++it) {
        result_descending.push_back(*it);
    }
    CHECK(result_descending == expected_descending);

    // SideCross Order Iterator
    std::vector<int> expected_side_cross = { -1000000, 1000000, -5, 15, -1, 10, 1, 7, 2, 7 };
    std::vector<int> result_side_cross;
    for (auto it = c.begin_side_cross_order(); it != c.end_side_cross_order(); ++it) {
        result_side_cross.push_back(*it);
    }
    CHECK(result_side_cross == expected_side_cross);

    // Reverse Order Iterator
    std::vector<int> expected_reverse = { -1000000, 1000000, -1, -5, 7, 10, 2, 1, 15, 7 };
    std::vector<int> result_reverse;
    for (auto it = c.begin_reverse_order(); it != c.end_reverse_order(); ++it) {
        result_reverse.push_back(*it);
    }
    CHECK(result_reverse == expected_reverse);

    // Order Iterator
    std::vector<int> expected_order = { 7, 15, 1, 2, 10, 7, -5, -1, 1000000, -1000000 };
    std::vector<int> result_order;
    for (auto it = c.begin_order(); it != c.end_order(); ++it) {
        result_order.push_back(*it);
    }
    CHECK(result_order == expected_order);

    // MiddleOut Order Iterator
    std::vector<int> expected_middle_out = { 10, 7, 2, -5, 1, -1, 15, 1000000, 7, -1000000 };
    std::vector<int> result_middle_out;
    for (auto it = c.begin_middle_out_order(); it != c.end_middle_out_order(); ++it) {
        result_middle_out.push_back(*it);
    }
    CHECK(result_middle_out == expected_middle_out);

}

TEST_CASE("Iterator functionality - operators ==, !=, ++") {
    MyContainer<int> c;
    c.add(5);
    c.add(3);
    c.add(9);

    SUBCASE("AscendingOrderIterator operators") {
        auto it1 = c.begin_ascending_order();
        auto it2 = c.begin_ascending_order();
        auto it_end = c.end_ascending_order();

        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
        it2++;
        CHECK(it1 == it2);
        while (it1 != it_end) ++it1;
        CHECK(it1 == it_end);
    }

    SUBCASE("DescendingOrderIterator operators") {
        auto it1 = c.begin_descending_order();
        auto it2 = c.begin_descending_order();
        auto it_end = c.end_descending_order();

        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
        it2++;
        CHECK(it1 == it2);
        while (it1 != it_end) ++it1;
        CHECK(it1 == it_end);
    }

    SUBCASE("SideCrossOrderIterator operators") {
        auto it1 = c.begin_side_cross_order();
        auto it2 = c.begin_side_cross_order();
        auto it_end = c.end_side_cross_order();

        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
        it2++;
        CHECK(it1 == it2);
        while (it1 != it_end) ++it1;
        CHECK(it1 == it_end);
    }

    SUBCASE("ReverseOrderIterator operators") {
        auto it1 = c.begin_reverse_order();
        auto it2 = c.begin_reverse_order();
        auto it_end = c.end_reverse_order();

        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
        it2++;
        CHECK(it1 == it2);
        while (it1 != it_end) ++it1;
        CHECK(it1 == it_end);
    }

    SUBCASE("OrderIterator operators") {
        auto it1 = c.begin_order();
        auto it2 = c.begin_order();
        auto it_end = c.end_order();

        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
        it2++;
        CHECK(it1 == it2);
        while (it1 != it_end) ++it1;
        CHECK(it1 == it_end);
    }

    SUBCASE("MiddleOutIterator operators") {
        auto it1 = c.begin_middle_out_order();
        auto it2 = c.begin_middle_out_order();
        auto it_end = c.end_middle_out_order();

        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
        it2++;
        CHECK(it1 == it2);
        while (it1 != it_end) ++it1;
        CHECK(it1 == it_end);
    }
}



// טסטים על דאבלים
TEST_CASE("Test doubles") {
    std::cout << "\nTesting with doubles (double):\n";

    MyContainer<double> c;
    c.add(7.5);
    c.add(1.5);
    c.add(3.5);

    // Verify size
    CHECK(c.size() == 3);  // 3 items in the container

    // Test adding duplicate
    c.add(7.5);  // Adding duplicate of 7.5
    CHECK(c.size() == 4);  // Should be 4 items now

    // Test remove
    c.remove(3.5);
    CHECK(c.size() == 3);  // 3 items after removal

    // Test removing an element that doesn't exist
    try {
        c.remove(100.0);  // should throw exception
        CHECK(false);  // should not reach here
    } catch (const std::runtime_error& e) {
        // Expected exception
    }

 // Ascending Order Iterator
    std::vector<double> expected_ascending = { 1.5, 7.5, 7.5 };
    std::vector<double> result_ascending;
    for (auto it = c.begin_ascending_order(); it != c.end_ascending_order(); ++it) {
        result_ascending.push_back(*it);
    }
    CHECK(result_ascending == expected_ascending);

    // Descending Order Iterator
    std::vector<double> expected_descending = { 7.5, 7.5, 1.5 };
    std::vector<double> result_descending;
    for (auto it = c.begin_descending_order(); it != c.end_descending_order(); ++it) {
        result_descending.push_back(*it);
    }
    CHECK(result_descending == expected_descending);

    // SideCross Order Iterator
    std::vector<double> expected_side_cross = { 1.5, 7.5, 7.5 };
    std::vector<double> result_side_cross;
    for (auto it = c.begin_side_cross_order(); it != c.end_side_cross_order(); ++it) {
        result_side_cross.push_back(*it);
    }
    CHECK(result_side_cross == expected_side_cross);

    // Reverse Order Iterator
    std::vector<double> expected_reverse = { 7.5, 1.5, 7.5 };
    std::vector<double> result_reverse;
    for (auto it = c.begin_reverse_order(); it != c.end_reverse_order(); ++it) {
        result_reverse.push_back(*it);
    }
    CHECK(result_reverse == expected_reverse);

    // Order Iterator
    std::vector<double> expected_order = { 7.5, 1.5, 7.5 };
    std::vector<double> result_order;
    for (auto it = c.begin_order(); it != c.end_order(); ++it) {
        result_order.push_back(*it);
    }
    CHECK(result_order == expected_order);

    // MiddleOut Order Iterator
    std::vector<double> expected_middle_out = { 1.5, 7.5, 7.5 };
    std::vector<double> result_middle_out;
    for (auto it = c.begin_middle_out_order(); it != c.end_middle_out_order(); ++it) {
        result_middle_out.push_back(*it);
    }
    CHECK(result_middle_out == expected_middle_out);
}

// טסטים על דאבל
TEST_CASE("Iterator functionality - operators ==, !=, ++ with double") {
    MyContainer<double> c;
    c.add(3.14);
    c.add(2.71);
    c.add(1.41);

    SUBCASE("AscendingOrderIterator operators") {
        auto it1 = c.begin_ascending_order();
        auto it2 = c.begin_ascending_order();
        auto it_end = c.end_ascending_order();

        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
        it2++;
        CHECK(it1 == it2);
        while (it1 != it_end) ++it1;
        CHECK(it1 == it_end);
    }

    SUBCASE("DescendingOrderIterator operators") {
        auto it1 = c.begin_descending_order();
        auto it2 = c.begin_descending_order();
        auto it_end = c.end_descending_order();

        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
        it2++;
        CHECK(it1 == it2);
        while (it1 != it_end) ++it1;
        CHECK(it1 == it_end);
    }

    SUBCASE("SideCrossOrderIterator operators") {
        auto it1 = c.begin_side_cross_order();
        auto it2 = c.begin_side_cross_order();
        auto it_end = c.end_side_cross_order();

        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
        it2++;
        CHECK(it1 == it2);
        while (it1 != it_end) ++it1;
        CHECK(it1 == it_end);
    }

    SUBCASE("ReverseOrderIterator operators") {
        auto it1 = c.begin_reverse_order();
        auto it2 = c.begin_reverse_order();
        auto it_end = c.end_reverse_order();

        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
        it2++;
        CHECK(it1 == it2);
        while (it1 != it_end) ++it1;
        CHECK(it1 == it_end);
    }

    SUBCASE("OrderIterator operators") {
        auto it1 = c.begin_order();
        auto it2 = c.begin_order();
        auto it_end = c.end_order();

        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
        it2++;
        CHECK(it1 == it2);
        while (it1 != it_end) ++it1;
        CHECK(it1 == it_end);
    }

    SUBCASE("MiddleOutIterator operators") {
        auto it1 = c.begin_middle_out_order();
        auto it2 = c.begin_middle_out_order();
        auto it_end = c.end_middle_out_order();

        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
        it2++;
        CHECK(it1 == it2);
        while (it1 != it_end) ++it1;
        CHECK(it1 == it_end);
    }
}


// טסטים על סטרינגים
TEST_CASE("Test strings") {
    std::cout << "\nTesting with strings (std::string):\n";

    MyContainer<std::string> c;
    c.add("banana");
    c.add("apple");
    c.add("kiwi");
    c.add("mango");

    // Verify size
    CHECK(c.size() == 4);  // 4 items in the container

    // Test adding duplicate
    c.add("apple");  // Adding duplicate of apple
    CHECK(c.size() == 5);  // Should be 5 items now

    // Test remove
    c.remove("kiwi");
    CHECK(c.size() == 4);  // 4 items after removal

    // Test removing an element that doesn't exist
    try {
        c.remove("pear");  // should throw exception
        CHECK(false);  // should not reach here
    } catch (const std::runtime_error& e) {
        // Expected exception
    }

     // Ascending Order Iterator
    std::vector<std::string> expected_ascending = { "apple", "apple", "banana", "mango" };
    std::vector<std::string> result_ascending;
    for (auto it = c.begin_ascending_order(); it != c.end_ascending_order(); ++it) {
        result_ascending.push_back(*it);
    }
    CHECK(result_ascending == expected_ascending);

    // Descending Order Iterator
    std::vector<std::string> expected_descending = { "mango", "banana", "apple", "apple" };
    std::vector<std::string> result_descending;
    for (auto it = c.begin_descending_order(); it != c.end_descending_order(); ++it) {
        result_descending.push_back(*it);
    }
    CHECK(result_descending == expected_descending);

    // SideCross Order Iterator
    std::vector<std::string> expected_side_cross = { "apple", "mango", "apple", "banana" };
    std::vector<std::string> result_side_cross;
    for (auto it = c.begin_side_cross_order(); it != c.end_side_cross_order(); ++it) {
        result_side_cross.push_back(*it);
    }
    CHECK(result_side_cross == expected_side_cross);

    // Reverse Order Iterator
    std::vector<std::string> expected_reverse = {  "apple", "mango", "apple", "banana" };
    std::vector<std::string> result_reverse;
    for (auto it = c.begin_reverse_order(); it != c.end_reverse_order(); ++it) {
        result_reverse.push_back(*it);
    }
    CHECK(result_reverse == expected_reverse);

    // Order Iterator
    std::vector<std::string> expected_order = { "banana", "apple", "mango", "apple" };
    std::vector<std::string> result_order;
    for (auto it = c.begin_order(); it != c.end_order(); ++it) {
        result_order.push_back(*it);
    }
    CHECK(result_order == expected_order);

    // MiddleOut Order Iterator
    std::vector<std::string> expected_middle_out = {  "apple", "mango", "banana", "apple" };
    std::vector<std::string> result_middle_out;
    for (auto it = c.begin_middle_out_order(); it != c.end_middle_out_order(); ++it) {
        result_middle_out.push_back(*it);
    }
    CHECK(result_middle_out == expected_middle_out);
}

// טסטים על מחרוזות
TEST_CASE("Iterator functionality - operators ==, !=, ++ with std::string") {
    MyContainer<std::string> c;
    c.add("banana");
    c.add("apple");
    c.add("cherry");

    SUBCASE("AscendingOrderIterator operators") {
        auto it1 = c.begin_ascending_order();
        auto it2 = c.begin_ascending_order();
        auto it_end = c.end_ascending_order();

        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
        it2++;
        CHECK(it1 == it2);
        while (it1 != it_end) ++it1;
        CHECK(it1 == it_end);
    }

    SUBCASE("DescendingOrderIterator operators") {
        auto it1 = c.begin_descending_order();
        auto it2 = c.begin_descending_order();
        auto it_end = c.end_descending_order();

        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
        it2++;
        CHECK(it1 == it2);
        while (it1 != it_end) ++it1;
        CHECK(it1 == it_end);
    }

    SUBCASE("SideCrossOrderIterator operators") {
        auto it1 = c.begin_side_cross_order();
        auto it2 = c.begin_side_cross_order();
        auto it_end = c.end_side_cross_order();

        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
        it2++;
        CHECK(it1 == it2);
        while (it1 != it_end) ++it1;
        CHECK(it1 == it_end);
    }

    SUBCASE("ReverseOrderIterator operators") {
        auto it1 = c.begin_reverse_order();
        auto it2 = c.begin_reverse_order();
        auto it_end = c.end_reverse_order();

        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
        it2++;
        CHECK(it1 == it2);
        while (it1 != it_end) ++it1;
        CHECK(it1 == it_end);
    }

    SUBCASE("OrderIterator operators") {
        auto it1 = c.begin_order();
        auto it2 = c.begin_order();
        auto it_end = c.end_order();

        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
        it2++;
        CHECK(it1 == it2);
        while (it1 != it_end) ++it1;
        CHECK(it1 == it_end);
    }

    SUBCASE("MiddleOutIterator operators") {
        auto it1 = c.begin_middle_out_order();
        auto it2 = c.begin_middle_out_order();
        auto it_end = c.end_middle_out_order();

        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
        it2++;
        CHECK(it1 == it2);
        while (it1 != it_end) ++it1;
        CHECK(it1 == it_end);
    }
}