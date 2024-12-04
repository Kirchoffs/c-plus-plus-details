#include <memory>
#include <iostream>

int main() {
    int* num_ptr = new int(42);
    std::unique_ptr<int> num_unique_ptr(num_ptr);
    std::cout << *num_unique_ptr << std::endl;
    // num_ptr should not be used after this point.
    // std::cout << *num_ptr << std::endl;
}
