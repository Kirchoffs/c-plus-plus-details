#include <iostream>

template<typename T1, typename T2>
auto max (T1 a, T2 b) -> decltype(b < a ? a : b)
{
  return b < a ? a : b;
}

int main()
{
    std::cout << max(3.14, 42) << std::endl;
}
