#include <iostream>
#include <memory>

class Demo {
public:
    Demo(int value) : value(value) {
        std::cout << "Demo created with value: " << value << std::endl;
    }

    ~Demo() {
        std::cout << "Demo destroyed with value: " << value << std::endl;
    }

    void display() const {
        std::cout << "Now display value: " << value << std::endl;
    }

public:
    int value;
};

void customDeleter(Demo* ptr) {
    std::cout << "Custom deleter called for Demo with value: ";
    if (ptr) {
        std::cout << ptr->value << std::endl;
    }
    delete ptr;
}

int main() {
    std::unique_ptr<Demo, decltype(&customDeleter)> uniquePtr(new Demo(42), customDeleter);
    uniquePtr->display();
}
