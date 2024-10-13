#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> foo;
    std::shared_ptr<const int> bar;

    foo = std::make_shared<int>(42);
    bar = std::const_pointer_cast<const int>(foo);

    std::cout << "*bar: " << *bar << '\n'; // 42
    *foo = 89;
    std::cout << "*bar: " << *bar << '\n'; // 89
}