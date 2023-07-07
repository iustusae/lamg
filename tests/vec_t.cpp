#include "../impls/data_structs/s_vector.h"
#include <cassert>
#include <iostream>
#include <optional>

int main() {
    iustus::s_vector<int> vec;

    // Test is_empty() and len() on an empty vector
    assert(vec.is_empty());
    assert(vec.len() == 0);
    std::cout << "Test 1 passed: is_empty() and len() on an empty vector"
              << std::endl;

    // Test push() and len() on a non-empty vector
    vec.push(10);
    vec.push(20);
    vec.push(30);
    assert(!vec.is_empty());
    assert(vec.len() == 3);
    std::cout << "Test 2 passed: push() and len() on a non-empty vector"
              << std::endl;

    // Test peek() on a non-empty vector
    assert(vec.peek().value_or(-1) == 10);  // The first element is 10
    assert(vec.peek(1).value_or(-1) == 20); // The second element is 20
    assert(vec.peek(2).value_or(-1) == 30); // The third element is 30
    assert(!vec.peek(3).has_value());       // Index out of range
    std::cout << "Test 3 passed: peek() on a non-empty vector" << std::endl;

    // Test pop() on a non-empty vector
    std::optional<int> popped = vec.pop();
    assert(popped.value() == 30); // The popped element is 30
    assert(vec.len() == 2);
    std::cout << "Test 4 passed: pop() on a non-empty vector" << std::endl;

    // Test prepend() and peek() on a non-empty vector
    vec.prepend(5);
    assert(vec.peek().value_or(-1) == 5);   // The first element is 5
    assert(vec.peek(1).value_or(-1) == 10); // The second element is 10
    assert(vec.peek(2).value_or(-1) == 20); // The third element is 20
    std::cout << "Test 5 passed: prepend() and peek() on a non-empty vector"
              << std::endl;

    // Test insert() on a non-empty vector
    vec.insert(15, 1);
    assert(vec.peek().value_or(-1) == 5);   // The first element is 5
    assert(vec.peek(1).value_or(-1) == 15); // The second element is 15
    assert(vec.peek(2).value_or(-1) == 10); // The third element is 10
    assert(vec.peek(3).value_or(-1) == 20); // The fourth element is 20
    assert(vec.len() == 4);
    std::cout << "Test 6 passed: insert() on a non-empty vector" << std::endl;

    // Test set() on a non-empty vector
    vec.set(2, 25);
    assert(vec.peek().value_or(-1) == 5);   // The first element is 5
    assert(vec.peek(1).value_or(-1) == 15); // The second element is 15
    assert(vec.peek(2).value_or(-1) == 25); // The third element is 25
    assert(vec.peek(3).value_or(-1) == 20); // The fourth element is 20
    std::cout << "Test 7 passed: set() on a non-empty vector" << std::endl;

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
