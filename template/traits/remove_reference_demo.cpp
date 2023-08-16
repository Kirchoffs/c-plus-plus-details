#include <type_traits>
#include <iostream>

int main() {
    const std::remove_reference<int&>::type i = 10;
    const std::remove_reference_t<int&> j = 10;
    const int k = 10;

    static_assert(i == j && j == k);
}