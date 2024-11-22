#include <iostream>

class ValueWrapper {
    public:
        ValueWrapper(int value) : value(value) {}

        ValueWrapper(const ValueWrapper& other) : value(other.value) {
            std::cout << "Copy constructor" << std::endl;
        }

        ValueWrapper(ValueWrapper&& other) : value(other.value) {
            std::cout << "Move constructor" << std::endl;
        }

        ValueWrapper& operator=(const ValueWrapper& other) {
            std::cout << "Copy assignment" << std::endl;
            value = other.value;
            return *this;
        }

        ValueWrapper& operator=(ValueWrapper&& other) {
            std::cout << "Move assignment" << std::endl;
            value = other.value;
            return *this;
        }

        ValueWrapper& return_self() {
            return *this;
        }

        int value;
};

// Returning a left value reference of a local object will cause undefined behavior.
ValueWrapper& create_value_wrapper() {
    ValueWrapper value_wrapper(42);
    return value_wrapper;
}

int main() {
    ValueWrapper alpha_value_wrapper = create_value_wrapper();
    std::cout << "Value: " << alpha_value_wrapper.value << std::endl;
    ValueWrapper& beta_value_wrapper = create_value_wrapper();
    std::cout << "Value: " << beta_value_wrapper.value << std::endl;

    ValueWrapper value_wrapper(42);
    ValueWrapper gamma_value_wrapper = value_wrapper.return_self();
    std::cout << "Value: " << gamma_value_wrapper.value << std::endl;
    ValueWrapper& delta_value_wrapper = value_wrapper.return_self();
    std::cout << "Value: " << delta_value_wrapper.value << std::endl;
}
