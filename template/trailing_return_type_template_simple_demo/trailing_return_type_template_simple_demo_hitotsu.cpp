#include <iostream>

template<class T, class U>
auto multiply(T const& lhs, U const& rhs) -> decltype(lhs * rhs)
{
    return lhs * rhs;
}

int main() 
{
    std::cout << multiply(1, 1) << std::endl;
}
