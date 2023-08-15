#include <type_traits>

template<typename T>

T max(T a, T b) 
{
    return a > b ? a : b;
}

template<typename T, typename U>
auto max_decltype(T a, U b) -> typename std::decay<decltype(a > b ? a : b)>::type
{
    return b < a ? a : b;
}
