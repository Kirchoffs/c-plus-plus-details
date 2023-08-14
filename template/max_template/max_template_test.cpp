#include "max_template_test.hpp"
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
}
