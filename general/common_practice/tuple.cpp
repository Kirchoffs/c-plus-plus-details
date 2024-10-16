#include <iostream>
#include <tuple>

int main() {
    std::tuple<int, double, std::string> t(42, 3.14, "hello");
    
    std::cout << std::get<0>(t) << std::endl;
    std::cout << std::get<1>(t) << std::endl;
    std::cout << std::get<2>(t) << std::endl;
}
