#include <optional>
#include <string>
#include <iostream>

int main() {
    auto optional_int = std::optional<int>{ 42 };
    auto optional_string = std::optional<std::string>{ "Hello, World!" };

    std::cout << "optional_int: " << *optional_int << std::endl;
    std::cout << "optional_string: " << *optional_string << std::endl;
}
