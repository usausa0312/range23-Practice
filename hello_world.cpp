#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

void test_even_doubled() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto even_doubled = numbers
                        | std::views::filter([](int n) { return n % 2 == 0; })
                        | std::views::transform([](int n) { return n * 2; });

    std::cout << "Even doubled numbers: ";
    for (int n : even_doubled) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    // Output: Even doubled numbers: 4 8 12 16 20
}

void test_reverse() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    auto reversed = numbers | std::views::reverse;

    std::cout << "Reversed numbers: ";
    for (int n : reversed) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    // Output: Reversed numbers: 5 4 3 2 1
}

void test_take() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    auto first_three = numbers | std::views::take(3);

    std::cout << "First three numbers: ";
    for (int n : first_three) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    // Output: First three numbers: 1 2 3
}

void test_drop() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    auto dropped_two = numbers | std::views::drop(2);

    std::cout << "After dropping first two numbers: ";
    for (int n : dropped_two) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    // Output: After dropping first two numbers: 3 4 5
}

void test_concat() {
    std::vector<int> numbers1 = {1, 2, 3};
    std::vector<int> numbers2 = {4, 5, 6};
    std::vector<std::vector<int>> nested = {numbers1, numbers2};
    auto concatenated = nested | std::views::join;

    std::cout << "Concatenated numbers: ";
    for (int n : concatenated) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    // Output: Concatenated numbers: 1 2 3 4 5 6
}

void test_unique() {
    std::vector<int> numbers = {1, 2, 2, 3, 4, 4, 5};
    auto end = std::ranges::unique(numbers);
    numbers.erase(end.begin(), end.end());

    std::cout << "Unique numbers: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    // Output: Unique numbers: 1 2 3 4 5
}

void test_sorted() {
    std::vector<int> numbers = {5, 3, 1, 4, 2};
    std::ranges::sort(numbers);

    std::cout << "Sorted numbers: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    // Output: Sorted numbers: 1 2 3 4 5
}

void test_transform() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    auto squared = numbers | std::views::transform([](int n) { return n * n; });

    std::cout << "Squared numbers: ";
    for (int n : squared) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    // Output: Squared numbers: 1 4 9 16 25
}

void test_filter() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    auto even_numbers = numbers | std::views::filter([](int n) { return n % 2 == 0; });

    std::cout << "Even numbers: ";
    for (int n : even_numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    // Output: Even numbers: 2 4
}

void test_zip() {
    std::vector<int> numbers1 = {1, 2, 3};
    std::vector<int> numbers2 = {4, 5, 6};
    auto zipped = std::views::zip(numbers1, numbers2);

    std::cout << "Zipped pairs: ";
    for (const auto& [a, b] : zipped) {
        std::cout << "(" << a << ", " << b << ") ";
    }
    std::cout << std::endl;
    // Output: Zipped pairs: (1, 4) (2, 5) (3, 6)
}

void test_take_while() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    auto taken_while = numbers | std::views::take_while([](int n) { return n < 4; });

    std::cout << "Taken while less than 4: ";
    for (int n : taken_while) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    // Output: Taken while less than 4: 1 2 3
}

void test_drop_while() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    auto dropped_while = numbers | std::views::drop_while([](int n) { return n < 3; });

    std::cout << "Dropped while less than 3: ";
    for (int n : dropped_while) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    // Output: Dropped while less than 3: 3 4 5
}

int main() {
    test_even_doubled();
    test_reverse();
    test_take();
    test_drop();
    test_concat();
    test_unique();
    test_sorted();
    test_transform();
    test_filter();
    test_zip();
    test_take_while();
    test_drop_while();

    return 0;
}