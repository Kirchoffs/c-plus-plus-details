#include <iostream>
#include <string>

class Distance {
    int meters;

public:
    Distance(int meters) : meters(meters) {
        std::cout << "Implicit conversion: " << meters << " meters\n";
    }

    explicit Distance(std::string m) : meters(std::stoi(m)) {
        std::cout << "Explicit conversion: " << meters << " meters\n";
    }

    void display() {
        std::cout << "Distance: " << meters << " meters\n";
    }
};

int main() {
    // Implicit conversion from const char* to std::string
    // Implicit conversion is achieved by the constructor of std::string
    std::string str = "Hello, World!";

    // Implicit conversion from double to Distance
    // Implicit conversion is achieved by the constructor of Distance
    Distance d = 42;
    // Distance d = std::string("42"); // Error: explicit conversion is forbidden for this case
    d.display();
}
