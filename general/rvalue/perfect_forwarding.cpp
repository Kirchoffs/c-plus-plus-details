#include <iostream>

template<typename T>
void print(T& t) {
    std::cout << "Lvalue ref" << std::endl;
}

template<typename T>
void print(T&& t) {
    std::cout << "Rvalue ref" << std::endl;
}

template<typename T>
void testForward(T&& v){ 
    print(v);                  // Always call lvalue version of print
    print(std::forward<T>(v)); // Perfect forwarding
    print(std::move(v));       // Always call rvalue version of print
}

int main() {
    int v = 42;
    
    testForward(v);
    std::cout << "======================" << std::endl;
    testForward(std::move(v));
}
