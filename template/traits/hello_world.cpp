#include <iostream>

template <typename T>
struct TraitsHelper {
     static const bool isPointer = false;
};

template <typename T>
struct TraitsHelper<T*> {
     static const bool isPointer = true;
};

template <typename T>
void process(T value) {
    if (TraitsHelper<T>::isPointer) {
        std::cout << "Processing a pointer." << std::endl;
    } else {
        std::cout << "Processing a non-pointer." << std::endl;
    }
}

int main() {
    int num = 42;
    int* ptr = &num;

    process(num);
    process(ptr);
}
