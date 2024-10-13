#include <iostream>

int main() {
    const int val = 42;
    const int* ptr_to_const_int = &val;
    int* ptr_to_int = const_cast<int*>(ptr_to_const_int);
    *ptr_to_int = 89;

    std::cout << "val: " << *ptr_to_const_int << std::endl; // 89
    std::cout << "val: " << *ptr_to_int << std::endl;       // 89
    std::cout << "val: " << val << std::endl;               // 42
    
    std::cout << "val address: " << ptr_to_const_int << std::endl;
    std::cout << "val address: " << ptr_to_int << std::endl;
    std::cout << "val address: " << &val << std::endl;
}
