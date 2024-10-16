#include <iostream>
#include <string>

class Distance {
    double meters;

public:
    Distance(double m) : meters(m) {
        std::cout << "Implicit conversion: " << m << " meters\n";
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
    Distance d = 42.0;
    d.display();
}
