#include <iostream>

class ReturnValue {
public:
    ReturnValue() {
        value = 42;
    }

    ReturnValue(int value) : value(value) {
        std::cout << "Constructor called" << std::endl;
    }

    ReturnValue(const ReturnValue& other) {
        std::cout << "Copy constructor called" << std::endl;
        value = other.value;
    }

    ReturnValue operator=(const ReturnValue& other) {
        std::cout << "Copy assignment operator called" << std::endl;
        value = other.value;
        return *this;
    }

    ~ReturnValue() {
        std::cout << "Destructor called" << std::endl;
    }
private:
    int value;
};

class ReturnReference {
public:
    ReturnReference() {
        value = 42;
    }

    ReturnReference(int value) : value(value) {
        std::cout << "Constructor called" << std::endl;
    }

    ReturnReference(const ReturnReference& other) {
        std::cout << "Copy constructor called" << std::endl;
        value = other.value;
    }

    ReturnReference& operator=(const ReturnReference& other) {
        std::cout << "Copy assignment operator called" << std::endl;
        value = other.value;
        return *this;
    }

    ~ReturnReference() {
        std::cout << "Destructor called" << std::endl;
    }
private:
    int value;
};

int main() {
    {
        std::cout << "Return value Result:" << std::endl;
        ReturnValue a;
        ReturnValue b;
        ReturnValue c(89);
        a = b = c;
    }

    std::cout << std::endl;

    {
        std::cout << "Return reference Result:" << std::endl;
        ReturnReference a;
        ReturnReference b;
        ReturnReference c(89);
        a = b = c;
    }
}
