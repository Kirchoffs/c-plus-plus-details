#include <iostream>

auto add(int a, int b) -> int 
{
    return a + b;
}

int main() 
{
    std::cout << add(1, 1) << std::endl;
}
