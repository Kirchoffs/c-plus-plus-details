#include "max_template_demo.hpp"
#include <iostream>
#include <string>

int main() 
{
    int i1 = 42;
    int i2 = 2001;
    std::cout << "max(i1, i2): " << ::max(i1, i2) << std::endl;

    double f1 = 3.14;
    double f2 = 2.718;
    std::cout << "max(f1, f2): " << ::max(f1, f2) << std::endl;

    std::string s1 = "mathematics";
    std::string s2 = "physics";
    std::cout << "max(s1, s2): " << ::max(s1, s2) << std::endl;

    int o1 = 42;
    double o2 = 2.718;
    std::cout << "max_max_decltype(o1, o2): " << ::max_decltype(o1, o2) << std::endl;

    std::cout << "max_common_type(o1, o2): " << ::max_common_type(o1, o2) << std::endl;
}
